/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwarpath <kwarpath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:18:33 by kwarpath          #+#    #+#             */
/*   Updated: 2022/05/11 18:58:17 by kwarpath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(int err_id)
{
	printf("Error: ");
	if (err_id == 1)
		printf("wrong number of arguments\n");
	if (err_id == 2)
		printf("arguments must be numbers\n");
	if (err_id == 3)
		printf("not value arguments\n");
	if (err_id == 4)
		printf("system failed\n");
	if (err_id == 5)
		printf("max philo == 200\nmin = 2\n");
	return (-1);
}

int	ft_atoi_check(const char *str, int *def)
{
	long long	res;
	int			sign;

	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res *= 10;
		res += (*str - '0');
		str++;
	}
	if (*str != 0)
		return (1);
	*def = (res * sign);
	return (0);
}

void	ft_die(t_fork *forks, t_philo *philos, t_data_ph *all)
{
	ft_print(&philos[all->i], DYING);
	ft_forks_destroy(forks, all->num_philo);
	pthread_mutex_destroy(&all->stdout_mutex);
}

void	ft_error_destroy(t_fork *forks, t_data_ph *all)
{
	ft_forks_destroy(forks, all->num_philo);
	pthread_mutex_destroy(&all->stdout_mutex);
	printf("simulate is infinite\n");
}
