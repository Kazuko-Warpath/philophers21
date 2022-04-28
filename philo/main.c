/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwarpath <kwarpath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:06:08 by kwarpath          #+#    #+#             */
/*   Updated: 2022/04/28 17:13:04 by kwarpath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if(checker_argc(argc) == -1)
		return(0);
	if(checker_argv(argv) == -1)
		return(0);
	if(checker_value_argv(argc, argv))
		return(0);
	data = ft_init(argc, argv);
	if(!data)
		return(0);
	printf("%d",data->num_philo);
	printf("%d",data->time_die);
	printf("%d",data->time_eat);
	printf("%d",data->time_sleep);
	printf("%d",data->count_eat);

	return(0);
}