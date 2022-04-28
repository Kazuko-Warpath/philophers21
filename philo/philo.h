/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwarpath <kwarpath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:18:41 by kwarpath          #+#    #+#             */
/*   Updated: 2022/04/28 17:16:12 by kwarpath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft/libft.h"
# include <unistd.h> /* usleep, write*/
# include <stdio.h> /* printf*/
# include <string.h> /* memset*/
# include <stdlib.h> /* malloc, free*/
# include <sys/time.h> /* gettimeofday*/
# include <pthread.h> 

typedef struct s_data
{
	int	num_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	count_eat;
}		t_data;

int	checker_argc(int ac);
int checker_argv(char **av);
int checker_value_argv(int ac, char **av);
int ft_error(int err_id);
t_data	*ft_init(int ac, char **av);

#endif