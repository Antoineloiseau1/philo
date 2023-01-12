/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:58:30 by anloisea          #+#    #+#             */
/*   Updated: 2023/01/12 15:48:09 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	go_to_sleep(t_philo *philo)
{
	printf("%lldms %d is sleeping\n", get_time(philo->data), philo->pos);
	usleep(philo->data->time_to_sleep);
}

int	eat(t_philo *philo)
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
	pthread_mutex_unlock(&second_fork);
	pthread_mutex_unlock(&first_fork);
	philo->last_meal = get_time(philo->data);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	eat(philo);
	go_to_sleep(philo);
	printf("%lldms %d is thinking\n", get_time(philo->data), philo->pos);
	return (arg);
}

int	create_threads(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->data->nb_of_philo)
	{
		memset(&philos[i].thread, 0, sizeof(pthread_t));
		if(pthread_create(&philos[i].thread, NULL, &routine, &philos[i]) != 0)
		{
			ft_putstr_fd("Failed to create thread\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	join_threads(t_philo *philos)
{
	int		i;
	void	*death;

	i = 0;
	while (i < philos->data->nb_of_philo)
	{
		if (pthread_join(philos[i].thread, &death) != 0)
		{
			ft_putstr_fd("Failed to join thread\n", 2);
			return(1);
		}
		if (death == NULL)
		{
			free_threads(philos);
			return (1);
		}
		i++;
	}
	free_threads(philos);
	return (0);
}