/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:01:36 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/06/17 14:57:15 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	ft_mutex_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) == -1)
			return (1);
		i++;
	}
	if (pthread_mutex_init(&data->print, NULL) == -1)
		return (1);
	if (pthread_mutex_init(&data->checker, NULL) == -1)
		return (1);
	if (pthread_mutex_init(&data->eat, NULL) == -1)
		return (1);
	return (0);
}

static int	ft_threads_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_create(&data->philo[i].thread_id, NULL,
				&routine, &data->philo[i]) == -1)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_philos_init(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->n_philo);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philo);
	if (!data->philo || !data->forks)
		return (1);
	while (i < data->n_philo)
	{
		data->philo[i].philo_id = i + 1;
		data->philo[i].l_fork = i;
		data->philo[i].r_fork = (i + 1) % data->n_philo;
		data->philo[i].last_eat = data->start;
		data->philo[i].data = data;
		i++;
	}
	return (0);
}

static int	get_args(t_data *data, int argc, char **av)
{
	(void)argc;
	data->n_philo = atoi_ft(av[1]);
	if (data->n_philo < 1 || data->n_philo > 200)
		return (1);
	data->die_time = atoi_ft(av[2]);
	data->eat_time = atoi_ft(av[3]);
	data->sleep_time = atoi_ft(av[4]);
	data->start = get_time();
	return (0);
}

int	ft_init(t_data *data, int argc, char **av)
{
	if (get_args(data, argc, av))
		return (1);
	if (data->n_philo == 1)
	{
		loner(data);
		return (2);
	}
	if (argc == 6)
		data->eating_loop = atoi_ft(av[5]);
	else
		data->eating_loop = -1;
	data->dead_philo = 0;
	if (ft_philos_init(data))
		return (1);
	if (ft_threads_init(data) || ft_mutex_init(data))
		return (1);
	return (0);
}
