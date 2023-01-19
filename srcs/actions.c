/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:54:48 by antoine           #+#    #+#             */
/*   Updated: 2023/01/19 16:29:10 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_print(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%lldms %d %s\n", get_time(philo->data), philo->pos, msg);
	pthread_mutex_unlock(&philo->data->print);
}

void	think(t_philo *philo)
{
	if (!dead_or_fed(philo->data))
		ft_print(philo, "is thinking");
}

void	go_to_sleep(t_philo *philo)
{
	if (!dead_or_fed(philo->data))
	{
		ft_print(philo, "is sleeping");
		usleep(philo->data->time_to_sleep);
	}
}

void	eat(t_philo *philo)
{
	pthread_mutex_t first_fork;
	pthread_mutex_t	second_fork;
	
	if (is_even(philo->pos))
	{
		//takes left_fork first
		first_fork = philo->left_fork;
		second_fork = philo->right_fork;
		
	}
	else
	{
		//takes right fork first
		first_fork = philo->right_fork;
		second_fork = philo->left_fork;		
	}
	if (!dead_or_fed(philo->data))
	{
		pthread_mutex_lock(&first_fork);
		ft_print(philo, "has taken a fork");
	}
	if (!dead_or_fed(philo->data))
	{
		pthread_mutex_lock(&second_fork);
		ft_print(philo, "has taken a fork");
		philo->last_meal = get_time(philo->data);
		ft_print(philo, "is eating");
		usleep(philo->data->time_to_eat);
		philo->has_eaten += 1;
		pthread_mutex_unlock(&second_fork);
	}
	pthread_mutex_unlock(&first_fork);
}