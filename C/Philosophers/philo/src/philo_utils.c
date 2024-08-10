/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:41:21 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/06/17 15:00:15 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_sleep(t_philo *philo, long long ms)
{
	long long	t;

	t = get_time();
	while (!thread_management(philo, 0) && (get_time() - t) < ms)
		usleep(500);
}

void	loner(t_data *data)
{
	printf(BLUE"0 "WHITE"1 " MAGENTA"is taking a fork\n"DEF_COLOR);
	printf(RED"%d 1 is dead"DEF_COLOR, data->die_time);
}

void	mutexed_print(t_philo *philo, char *action)
{
	long long	actual_time;

	pthread_mutex_lock(&philo->data->print);
	actual_time = get_time();
	actual_time = actual_time - philo->data->start;
	if (!philo->data->dead_philo && !thread_management(philo, 0))
		printf(BLUE"%lld "WHITE"%d ""%s\n"DEF_COLOR, actual_time,
			philo->philo_id, action);
	pthread_mutex_unlock(&philo->data->print);
}

int	thread_management(t_philo *philo, int death)
{
	pthread_mutex_lock(&philo->data->checker);
	if (death)
	{
		philo->data->dead_philo = 1;
		pthread_mutex_unlock(&philo->data->checker);
		return (1);
	}
	if (philo->data->dead_philo)
	{
		pthread_mutex_unlock(&philo->data->checker);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->checker);
	return (0);
}

