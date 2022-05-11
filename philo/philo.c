/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwarpath <kwarpath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:18:38 by kwarpath          #+#    #+#             */
/*   Updated: 2022/04/30 16:36:50 by kwarpath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_get_current_time(t_philo *philo)
{
	t_timeval	tm;

	gettimeofday(&tm, 0);
	return ((tm.tv_sec - philo->c_program_start_time.tv_sec) * 1000
		+ (tm.tv_usec - philo->c_program_start_time.tv_usec) / 1000);
}

int	ft_print(t_philo *philo, int condition)
{
	pthread_mutex_lock(philo->stdout_mutex);
	if (condition == EATING)
		printf("%ld %d is eating\n",
			ft_get_current_time(philo), philo->philo_type);
	else if (condition == SLEEPING)
		printf("%ld %d is sleeping\n",
			ft_get_current_time(philo), philo->philo_type);
	else if (condition == THINKING)
		printf("%ld %d is thinking\n",
			ft_get_current_time(philo), philo->philo_type);
	else if (condition == TAKING_FORK)
		printf("%ld %d has taken a fork\n",
			ft_get_current_time(philo), philo->philo_type);
	else if (condition == DYING)
	{
		printf("%ld %d died\n",
			ft_get_current_time(philo), philo->philo_type);
		return (0);
	}
	pthread_mutex_unlock(philo->stdout_mutex);
	return (0);
}

void	ft_update_last_time_eat(t_timeval *tv, t_philo *philo, int was_sleeping)
{
	tv->tv_usec += philo->c_time_to_eat * 1000;
	if (tv->tv_usec >= 100000)
	{
		tv->tv_sec++;
		tv->tv_usec -= 100000;
	}
	if (was_sleeping)
	{
		tv->tv_usec += philo->c_time_to_sleep;
		if (tv->tv_usec >= 100000)
		{
			tv->tv_sec++;
			tv->tv_usec -= 100000;
		}
	}
}

t_data	*ft_init(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if(!data)
		return (NULL);
	data->num_philo = ft_atoi(av[1]);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	data->count_eat = -1;
	if(ac == 6)
		data->count_eat = ft_atoi(av[5]);
	return(data);
}
