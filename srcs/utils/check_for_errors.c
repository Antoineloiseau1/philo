/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:26:48 by antoine           #+#    #+#             */
/*   Updated: 2023/01/23 12:40:38 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int	check_for_errors(int argc, char *argv[])
{
	if (argc < 5 || !(argc >= 5 && argc <= 6))
	{
		ft_putstr_fd("philo: usage: ", 2);
		ft_putstr_fd("number_of_philosophers time_to_die time_to_eat ", 2);
		ft_putstr_fd("time_to_sleep ", 2);
		ft_putstr_fd("[number_of_time_each_philosopher_must_eat]\n", 2);
		return (1);
	}
	if (search_for_alpha(argv))
		return (1);
	else if (check_for_invalid_values(argv))
		return (1);
	else
		return (0);
}

int	search_for_alpha(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (is_alpha(argv[i][j]))
			{
				ft_putstr_fd("philo: only takes numeric argumets\n", 2);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_for_invalid_values(char *argv[])
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) <= 0)
		{
			ft_putstr_fd("philo: strictly takes positive integers\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}
