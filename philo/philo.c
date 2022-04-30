/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwarpath <kwarpath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:18:38 by kwarpath          #+#    #+#             */
/*   Updated: 2022/04/30 18:30:20 by kwarpath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init(int ac, char **av, t_data_ph *data)
{
	data = malloc(sizeof(t_data_ph));
	if(!data)
		return (-1);
	data->num_philo = ft_atoi(av[1]);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	data->count_eat = -1;
	if(ac == 6)
		data->count_eat = ft_atoi(av[5]);
	if(pthread_mutex_init(&data->stdout_mutex, 0))
		return(1);
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
	ft_philo_eat((t_philo *) data, 0);//написать
	ft_philo_sleep((t_philo *) data);//написать
	ft_philo_think((t_philo *) data);//написать
	while (1)
	{
		ft_philo_eat((t_philo *) data, 1);//написать
		ft_philo_sleep((t_philo *) data);//написать
		ft_philo_think((t_philo *) data);//написать
	}
	return (0);
}

int	ft_philos_init(t_philo *philo, int philo_count,
	t_fork *forks, t_data_ph *util)
{
	int			i;
	pthread_t	ptid;

	i = 0;
	while (i < philo_count)
	{
		philo[i].philo_type = i + 1;
		philo[i].left = forks + i;
		philo[i].right = forks + ((i + 1) % util->num_philo);
		philo[i].stdout_mutex = &util->stdout_mutex;
		if (pthread_mutex_init(&philo[i].condition_mutex, 0))
			return (1);
		philo[i].eating_times = 0;
		philo[i].c_time_to_eat = util->time_eat;
		philo[i].c_time_to_sleep = util->time_sleep;
		philo[i].c_program_start_time = util->program_start_time;
		gettimeofday(&philo[i].last_time_eat, 0);
		if (pthread_create(&ptid, 0, ft_philo, &(philo[i])))
			return (1);
		pthread_detach(ptid);
		i++;
	}
	return (0);
}