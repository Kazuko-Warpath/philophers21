/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwarpath <kwarpath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:18:38 by kwarpath          #+#    #+#             */
/*   Updated: 2022/04/28 17:16:29 by kwarpath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
