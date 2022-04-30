/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwarpath <kwarpath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:18:33 by kwarpath          #+#    #+#             */
/*   Updated: 2022/04/30 18:07:55 by kwarpath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_error(int err_id)
{
	printf("Error: ");
	if(err_id == 1)
		printf("wrong number of arguments\n");
	if(err_id == 2)
		printf("arguments must be numbers\n");
	if(err_id == 3)
		printf("not value arguments");
	if(err_id == 4)
		printf("system failed");
	return(-1);
}