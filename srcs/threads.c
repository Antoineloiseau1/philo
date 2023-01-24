/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:58:30 by anloisea          #+#    #+#             */
/*   Updated: 2023/01/24 17:46:26 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*check_all_fed(void *arg)
{
	t_philo	*philos;
	int		i;
	int		fed_philos;

	philos = (t_philo *)arg;
	fed_philos = 0;
	while (!dead_or_fed(philos->data))
	{
		i = 0;
		while (i < philos->data->nb_of_philo)
		{
			pthread_mutex_lock(&philos->data->lock_value);
			if (philos[i].has_eaten == philos->data->must_eat \
				&& philos[i].is_fed == false)
			{
				pthread_mutex_unlock(&philos->data->lock_value);
				fed_philos++;
				philos[i].is_fed = true;
			}
			else
				pthread_mutex_unlock(&philos->data->lock_value);
			i++;
		}
		if (is_all_fed(philos, fed_philos))
			return (NULL);
	}
	return (NULL);
}

void	*check_vitals(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	while (!dead_or_fed(philo->data))
	{
		i = 0;
		while (i < philo->data->nb_of_philo)
		{
			if (is_time_to_die(philo, i))
				return (NULL);
			i++;
		}
	}
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (is_even(philo->pos) && !dead_or_fed(philo->data))
	{
		think(philo);
		msleep(2);
	}
	while (!dead_or_fed(philo->data))
	{
		if (!dead_or_fed(philo->data))
			eat(philo);
		if (!dead_or_fed(philo->data))
			go_to_sleep(philo);
		if (!dead_or_fed(philo->data))
			think(philo);
	}
	return (NULL);
}

int	create_threads(t_philo *philos)
{
	pthread_t	vitals;
	pthread_t	check_meals;
	int			i;

	i = 0;
	while (i < philos->data->nb_of_philo)
	{
		if (pthread_create(&philos[i].thread, NULL, &routine, &philos[i]) != 0)
		{
			ft_putstr_fd("Failed to create thread\n", 2);
			return (1);
		}
		i++;
	}	
	if (pthread_create(&vitals, NULL, &check_vitals, philos) != 0)
		return (1);
	pthread_detach(vitals);
	if (pthread_create(&check_meals, NULL, &check_all_fed, philos) != 0)
		return (1);
	pthread_detach(check_meals);
	return (0);
}

int	join_threads(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->data->nb_of_philo)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
		{
			ft_putstr_fd("Failed to join thread\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}
