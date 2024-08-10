/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:50:17 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/06/17 15:03:59 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	eat_action(t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->data->eat);
	time = get_time();
	philo->last_eat = time - philo->data->start;
	philo->data->eating_loop++;
	pthread_mutex_unlock(&philo->data->eat);
	if (!thread_management(philo, 0))
	{
		mutexed_print(philo, YELLOW"is eating");
		ft_sleep(philo, philo->data->eat_time);
	}
}

static void	eating_routine(t_philo *philo)
{
	if (philo->philo_id % 2 != 0)
	{
		pthread_mutex_lock(&philo->data->forks[philo->r_fork]);
		mutexed_print(philo, MAGENTA"has taken a fork");
		pthread_mutex_lock(&philo->data->forks[philo->l_fork]);
		mutexed_print(philo, MAGENTA"has taken a fork");
		eat_action(philo);
		pthread_mutex_unlock(&philo->data->forks[philo->l_fork]);
		pthread_mutex_unlock(&philo->data->forks[philo->r_fork]);
	}
	else
	{
		pthread_mutex_lock(&philo->data->forks[philo->l_fork]);
		mutexed_print(philo, MAGENTA"has taken a fork");
		pthread_mutex_lock(&philo->data->forks[philo->r_fork]);
		mutexed_print(philo, MAGENTA"has taken a fork");
		eat_action(philo);
		pthread_mutex_unlock(&philo->data->forks[philo->r_fork]);
		pthread_mutex_unlock(&philo->data->forks[philo->l_fork]);
	}
}

void	*routine(void *philou)
{
	t_philo	*philo;

	philo = (t_philo *)philou;
	if (philo->philo_id % 2 == 0)
		usleep(philo->data->eat_time);
	while (1)
	{
		eating_routine(philo);
		if (thread_management(philo, 0))
			break ;
		mutexed_print(philo, CYAN"is sleeping");
		ft_sleep(philo, philo->data->sleep_time);
		mutexed_print(philo, GREEN"is thinking");
		if (philo->data->n_philo % 2 != 0 && !thread_management(philo, 0))
			ft_sleep(philo, (philo->data->die_time - \
					(philo->data->eat_time + philo->data->sleep_time)) / 2);
	}
	return (0);
}

void	death_check(t_data *data)
{
	long long	actual_time = 0;

	actual_time = get_time();
	actual_time = actual_time - data->start;
	if (data->sleep_time + data->eat_time >= data->die_time)
	{
		mutexed_print(data->philo, "is dead");
		thread_management(data->philo, 1);
	}
}

int	main(int argc, char **argv)
{
	t_data		data;
	int			check;

	if (ft_parse(argc, argv))
		return (1);
	check = ft_init(&data, argc, argv);
	if (check == 1)
	{
		printf(RED"Initialization failed\n"DEF_COLOR);
		return (1);
	}
	if (check == 2)
		return (0);
	// process_ending(&data);
	int	i = 0;
	while (i < data.n_philo)
	{
		death_check(&data);
		if (data.dead_philo)
			break ;
		i++;
	}
	i = 0;
	while (i < data.n_philo)
	{
		pthread_join(data.philo[i].thread_id, NULL);
		i++;
	}
	return (0);
}
