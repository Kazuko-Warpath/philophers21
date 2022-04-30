#include "philo.h"

int	ft_philo_sleep(t_philo *philo)
{
	ft_print(philo, SLEEPING);
	usleep(philo->c_time_to_sleep * 1000);
	return (0);
}

int	ft_philo_eat(t_philo *philo, int was_sleeping)
{
	t_fork	*min_fork;
	t_fork	*max_fork;

	min_fork = philo->right;
	max_fork = philo->left;
	if (philo->left->fork_type < philo->right->fork_type)
	{
		min_fork = philo->left;
		max_fork = philo->right;
	}
	ft_fork_lock(min_fork);
	ft_print(philo, TAKING_FORK);
	ft_fork_lock(max_fork);
	ft_print(philo, TAKING_FORK);
	ft_print(philo, EATING);
	usleep(philo->c_time_to_eat * 1000);
	pthread_mutex_lock(&philo->condition_mutex);
	philo->eating_times++;
	ft_update_last_time_eat(&philo->last_time_eat, philo, was_sleeping);
	pthread_mutex_unlock(&philo->condition_mutex);
	ft_fork_unlock(max_fork);
	ft_fork_unlock(min_fork);
	return (0);
}

int	ft_philo_think(t_philo *philo)
{
	ft_print(philo, THINKING);
	return (0);
}

int	ft_philo_was_died(t_philo *philo, t_data_ph *util)
{
	t_timeval	current_time;

	gettimeofday(&current_time, 0);
	pthread_mutex_lock(&philo->condition_mutex);
	if ((current_time.tv_sec - philo->last_time_eat.tv_sec) * 1000
		+ (current_time.tv_usec - philo->last_time_eat.tv_usec + 500) / 1000
		>= util->time_die)
	{
		pthread_mutex_unlock(&philo->condition_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->condition_mutex);
	return (0);
}
