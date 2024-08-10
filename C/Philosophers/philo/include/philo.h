/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:50:26 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/06/17 14:55:09 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <fcntl.h>
# include <pthread.h>

# define DEF_COLOR "\033[0;39m"
# define GRAY "\033[0;90m"
# define RED "\033[0;91m"
# define GREEN "\033[0;92m"
# define YELLOW "\033[0;93m"
# define BLUE "\033[0;94m"
# define MAGENTA "\033[0;95m"
# define CYAN "\033[0;96m"
# define WHITE "\033[1;97m"

typedef struct s_philo
{
	int				philo_id;
	int				l_fork;
	int				r_fork;
	long long		last_eat;
	pthread_t		thread_id;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				n_philo;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				eating_loop;
	long long		start;
	int				dead_philo;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	checker;
	pthread_mutex_t	eat;
}	t_data;

/*init.c*/
int				ft_init(t_data *data, int argc, char **av);

/*libft_utils.c*/
size_t			ft_strlen(const char *str);
int				ft_checklen(char *argv);
long long int	atoi_ft(const char *str);
int				ft_isdigit(char *str);

/*philo_utils.c*/
long long		get_time(void);
void			ft_sleep(t_philo *philo, long long ms);
void			loner(t_data *data);
void			mutexed_print(t_philo *philo, char *action);
int				thread_management(t_philo *philo, int death);

/*philo_utils2.c*/
int				ft_parse(int argc, char **argv);

/*philo.c*/
void			*routine(void *philou);



#endif