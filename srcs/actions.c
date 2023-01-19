/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:54:48 by antoine           #+#    #+#             */
/*   Updated: 2023/01/18 17:57:05 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	think(t_philo *philo)
{
	printf("%lldms %d is thinking\n", get_time(philo->data), philo->pos);
}

void	go_to_sleep(t_philo *philo)
{
	printf("%lldms %d is sleeping\n", get_time(philo->data), philo->pos);
	usleep(philo->data->time_to_sleep);
}

void	eat(t_philo *philo)
{
	pthread_mutex_t first_fork;
	pthread_mutex_t	second_fork;
	
	if (is_even(philo->pos % philo->data->nb_of_philo))
	{
		//takes left_fork first
		first_fork = (philo + ((philo->pos + 1) % philo->data->nb_of_philo))->fork;
		second_fork = philo->fork;
		
	}
	else
	{
		//takes right fork first
		first_fork = philo->fork;
		second_fork = (philo + ((philo->pos + 1) % philo->data->nb_of_philo))->fork;		
	}
	pthread_mutex_lock(&first_fork);
	printf("%lldms %d has taken a fork\n", get_time(philo->data), philo->pos);
	pthread_mutex_lock(&second_fork);
	printf("%lldms %d has taken a fork\n", get_time(philo->data), philo->pos);
	printf("%lldms %d is eating\n", get_time(philo->data), philo->pos);
	usleep(philo->data->time_to_eat);
	philo->has_eaten += 1;
	pthread_mutex_unlock(&second_fork);
	pthread_mutex_unlock(&first_fork);
	philo->last_meal = get_time(philo->data);
}