/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwarpath <kwarpath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:08:32 by kwarpath          #+#    #+#             */
/*   Updated: 2022/04/28 15:49:24 by kwarpath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	checker_argc(int ac)
{
	if(ac >= 5 && ac <=6)
		return (0);
	return(ft_error(1));
}

int checker_argv(char **av)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while(av[i])
	{
		tmp = ft_strdup(av[i]);
		if(!tmp)
			return(-1);
		j = 0;
		while(tmp[j])
		{
			if(!ft_isdigit(tmp[j]))
			{	
				free(tmp);
				return(ft_error(2));
			}
			j++;
		}
		free(tmp);
		tmp = NULL;
		i++;
	}
	return (0);
}