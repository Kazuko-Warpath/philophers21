/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwarpath <kwarpath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 18:42:06 by kwarpath          #+#    #+#             */
/*   Updated: 2022/04/30 18:42:35 by kwarpath         ###   ########.fr       */
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
