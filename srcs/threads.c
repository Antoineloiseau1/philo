/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:58:30 by anloisea          #+#    #+#             */
/*   Updated: 2023/01/19 15:40:47 by antoine          ###   ########.fr       */
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
	while (!dead_or_fed(philo->data))
	{
		eat(philo);
		go_to_sleep(philo);
		think(philo);
	}
	return (NULL);
}

int	create_threads(t_philo *philos)
{
	int	i;

	i = 0;
	while (i< philos->data->nb_of_philo)
	{
		philos[i].data->start_time = get_time(philos->data);
		i++;
	}
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