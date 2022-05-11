/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwarpath <kwarpath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:06:08 by kwarpath          #+#    #+#             */
/*   Updated: 2022/05/11 19:02:17 by kwarpath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_fork_lock(t_fork *fork)
{
	pthread_mutex_lock(&fork->mutex);
	fork->is_busy = 1;
	return (0);
}

int	ft_fork_unlock(t_fork *fork)
{
	fork->is_busy = 0;
	pthread_mutex_unlock(&fork->mutex);
	return (0);
}

int	ft_forks_destroy(t_fork *forks, int forks_count)
{
	int	i;

	i = 0;
	while (i < forks_count)
	{
		forks[i].fork_type = i + 1;
		if (pthread_mutex_destroy(&forks[i].mutex))
			return (-1);
	}
	return (0);
}

void	simulate(t_fork *forks, t_philo *philos, t_data_ph *all, int j)
{
	while (j++ < LIMIT)
	{
		all->i = 0;
		all->eating_times_flag = 1;
		while (all->i < all->num_philo)
		{
			if (all->count_eat == -1
				|| philos[all->i].eating_times < all->count_eat)
				all->eating_times_flag = 0;
			if (ft_philo_was_died(&philos[all->i], all))
			{
				ft_die(forks, philos, all);
				return ;
			}
			++all->i;
		}
		if (all->eating_times_flag)
		{
			ft_forks_destroy(forks, all->num_philo);
			pthread_mutex_destroy(&all->stdout_mutex);
			return ;
		}
		j++;
	}
	ft_error_destroy(forks, all);
}

int	main(int argc, char **argv)
{
	t_data_ph	all;
	t_fork		forks[PHILO_MAX];
	t_philo		philos[PHILO_MAX];

	if (checker_argc(argc) == -1)
		return (1);
	if (checker_argv(argv) == -1)
		return (1);
	if (checker_value_argv(argc, argv) == -1)
		return (1);
	if (ft_init(argc, argv, &all) == -1)
		return (ft_error(4));
	if (ft_forks_init(forks, all.num_philo) == -1)
		return (ft_error(4));
	if (ft_philos_init(philos, all.num_philo, forks, &all) == -1)
		return (ft_error(4));
	simulate(forks, philos, &all, 0);
	return (0);
}
