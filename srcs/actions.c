/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:54:48 by antoine           #+#    #+#             */
/*   Updated: 2023/01/24 14:52:07 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_print(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->print);
	if (!dead_or_fed(philo->data))
		printf("%lld %d %s\n", get_time(philo->data), philo->pos, msg);
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
		msleep(philo->data->time_to_sleep);
	}
}

void	eat(t_philo *philo)
{
	if (!dead_or_fed(philo->data))
	{
		pthread_mutex_lock(philo->left_fork);
		ft_print(philo, "has taken a fork");
	}
	else
		return ;
	if (!dead_or_fed(philo->data))
	{
		pthread_mutex_lock(&philo->right_fork);
		ft_print(philo, "has taken a fork");
		philo->last_meal = get_time(philo->data);
		ft_print(philo, "is eating");
		msleep(philo->data->time_to_eat);
		pthread_mutex_unlock(&philo->right_fork);
		philo->has_eaten++;
	}
	pthread_mutex_unlock(philo->left_fork);
}
