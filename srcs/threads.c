/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:58:30 by anloisea          #+#    #+#             */
/*   Updated: 2023/01/20 17:47:24 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	dead_or_fed(t_data *data)
{
	if (data->all_fed || data->someone_died)
		return (1);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (is_even(philo->pos) && !dead_or_fed(philo->data))
	{
		think(philo);
		msleep(1);
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
	int	i;

	i = 0;
	while (i < philos->data->nb_of_philo)
	{
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
	int	i;

	i = 0;
	while (i < philos->data->nb_of_philo)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
		{
			ft_putstr_fd("Failed to join thread\n", 2);
			return(1);
		}
		i++;
	}
	return (0);
}