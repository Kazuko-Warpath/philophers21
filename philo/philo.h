/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwarpath <kwarpath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:18:41 by kwarpath          #+#    #+#             */
/*   Updated: 2022/05/07 13:13:39 by kwarpath         ###   ########.fr       */
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

# define PHILO_MAX 200
# define EATING 1
# define THINKING 2
# define SLEEPING 3
# define TAKING_FORK 4
# define DYING 5

typedef pthread_mutex_t	t_mutex;
typedef struct timeval	t_timeval;

typedef struct s_fork
{
	int		fork_type;
	int		is_busy;
	t_mutex	mutex;
}	t_fork;

typedef struct s_philo
{
	int			philo_type;
	t_fork		*left;
	t_fork		*right;
	t_mutex		*stdout_mutex;
	t_mutex		condition_mutex;
	int			eating_times;
	t_timeval	last_time_eat;
	long int	c_time_to_eat;
	long int	c_time_to_sleep;
	t_timeval	c_program_start_time;
}	t_philo;

typedef struct s_data_ph
{
	int	i;
	int	num_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	count_eat;
	int	eating_times_flag;
	t_mutex		stdout_mutex;
	t_timeval	program_start_time;
}		t_data_ph;

int		checker_argc(int ac);
int		checker_argv(char **av);
int		checker_value_argv(int ac, char **av);
int		ft_error(int err_id);
int		ft_init(int ac, char **av, t_data_ph *data);
int		ft_fork_lock(t_fork *fork);
int		ft_fork_unlock(t_fork *fork);
int		ft_forks_destroy(t_fork *forks, int forks_count);
void	simulate(t_fork *forks, t_philo *philos, t_data_ph *util);
int		ft_philo_sleep(t_philo *philo);
int		ft_philo_eat(t_philo *philo, int was_sleeping);
int		ft_philo_think(t_philo *philo);
int		ft_philo_was_died(t_philo *philo, t_data_ph *util);
long	ft_get_current_time(t_philo *philo);
int		ft_print(t_philo *philo, int condition);
void	ft_update_last_time_eat(t_timeval *tv, t_philo *philo, int was_sleeping);
int		ft_forks_init(t_fork *forks, int forks_count);
void	*ft_philo(void *data);
int		ft_philos_init(t_philo *philo, int philo_count,
	t_fork *forks, t_data_ph *util);
#endif