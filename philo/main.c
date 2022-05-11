/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwarpath <kwarpath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:06:08 by kwarpath          #+#    #+#             */
/*   Updated: 2022/04/30 16:41:07 by kwarpath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	ft_simulate(t_fork *forks, t_philo *philos, t_data *data)
{
	while (1)
	{
		data->i = 0;
		data->eating_times = 1;
		while (data->i < data->num_philo)
		{
			if (data->eating_times == -1
				|| philos[data->i].eating_times < data->eating_times)
				data->eating_times = 0;
			if (ft_philo_was_died(&philos[data->i], data))
			{
				ft_print(&philos[data->i], DYING);
				ft_forks_destroy(forks, data->num_philo);
				pthread_mutex_destroy(&data->stdout_mutex);
				return (1);
			}
			++data->i;
		}
		if (data->eating_times)
		{
			ft_forks_destroy(forks, data->num_philo);
			pthread_mutex_destroy(&data->stdout_mutex);
			return (0);
		}
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_fork	forks[PHILO_MAX];
	t_philo	philos[PHILO_MAX];

	if(checker_argc(argc) == -1)
		return(0);
	if(checker_argv(argv) == -1)
		return(0);
	if(checker_value_argv(argc, argv))
		return(0);
	data = ft_init(argc, argv);
	if(!data)
		return(0);
	if (ft_forks_init(forks, data->num_philo))
		return (1);
	if (ft_philos_init(philos, data->num_philo, forks, &data))
		return (1);
	return (ft_simulate(forks, philos, &data));

	return(0);
}