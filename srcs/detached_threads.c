/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detached_threads.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:52:03 by antoine           #+#    #+#             */
/*   Updated: 2023/01/24 17:45:30 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_time_to_die(t_philo *philo, int i)
{
	int	j;

	pthread_mutex_lock(&philo->data->lock_value);
	if (get_time(philo->data) - philo[i].last_meal >= philo->data->time_to_die)
	{
		j = 0;
		pthread_mutex_unlock(&philo->data->lock_value);
		pthread_mutex_lock(&philo->data->dorf);
		while (j < philo->data->nb_of_philo)
		{
			philo[j].data->someone_died = true;
			j++;
		}
		pthread_mutex_unlock(&philo->data->dorf);
		pthread_mutex_lock(&philo->data->print);
		printf("%lld %d has died\n", get_time(philo->data), philo[i].pos);
		pthread_mutex_unlock(&philo->data->print);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->lock_value);
	return (0);
}

int	is_all_fed(t_philo *philo, int fed_philos)
{
	int	i;

	if (fed_philos == philo->data->nb_of_philo)
	{
		i = 0;
		pthread_mutex_lock(&philo->data->dorf);
		while (i < philo->data->nb_of_philo)
		{
			philo[i].data->all_fed = true;
			i++;
		}
		pthread_mutex_unlock(&philo->data->dorf);
		return (1);
	}
	return (0);
}
