/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwarpath <kwarpath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:18:38 by kwarpath          #+#    #+#             */
/*   Updated: 2022/05/11 16:57:16 by kwarpath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init(int ac, char **av, t_data_ph *data)
{
	if (ft_atoi_check(av[1], &data->num_philo))
		return (-1);
	if (ft_atoi_check(av[2], &data->time_die))
		return (-1);
	if (ft_atoi_check(av[3], &data->time_eat))
		return (-1);
	if (ft_atoi_check(av[4], &data->time_sleep))
		return (-1);
	if (pthread_mutex_init(&data->stdout_mutex, 0))
		return (-1);
	data->count_eat = -1;
	if (ac == 6)
	{
		if (ft_atoi_check(av[5], &data->count_eat))
			return (-1);
	}
	if (pthread_mutex_init(&data->stdout_mutex, 0))
		return (-1);
	gettimeofday(&data->program_start_time, 0);
	return (0);
}

int	ft_forks_init(t_fork *forks, int forks_count)
{
	int	i;

	i = 0;
	while (i < forks_count)
	{
		forks[i].fork_type = i + 1;
		forks[i].is_busy = 0;
		if (pthread_mutex_init(&forks[i].mutex, 0))
			return (-1);
		i++;
	}
	return (0);
}

void	*ft_philo(void *data)
{
	if (((t_philo *)data)->philo_type % 2 == 0)
		usleep(2500);
	ft_philo_eat((t_philo *) data, 0);
	ft_philo_sleep((t_philo *) data);
	ft_philo_think((t_philo *) data);
	while (1)
	{
		ft_philo_eat((t_philo *) data, 1);
		ft_philo_sleep((t_philo *) data);
		ft_philo_think((t_philo *) data);
	}
	return (0);
}

int	ft_philos_init(t_philo *philo, int philo_count,
	t_fork *forks, t_data_ph *data)
{
	int			i;
	pthread_t	ptid;

	i = 0;
	while (i < philo_count)
	{
		philo[i].philo_type = i + 1;
		philo[i].left = forks + i;
		philo[i].right = forks + ((i + 1) % data->num_philo);
		philo[i].stdout_mutex = &data->stdout_mutex;
		if (pthread_mutex_init(&philo[i].condition_mutex, 0))
			return (-1);
		philo[i].eating_times = 0;
		philo[i].c_time_to_eat = data->time_eat;
		philo[i].c_time_to_sleep = data->time_sleep;
		philo[i].c_program_start_time = data->program_start_time;
		gettimeofday(&philo[i].last_time_eat, 0);
		if (pthread_create(&ptid, 0, ft_philo, &(philo[i])))
			return (-1);
		pthread_detach(ptid);
		i++;
	}
	return (0);
}
