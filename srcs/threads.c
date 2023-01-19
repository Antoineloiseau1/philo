/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:58:30 by anloisea          #+#    #+#             */
/*   Updated: 2023/01/18 17:55:14 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		think(philo);
		if (philo->data->someone_died || philo->data->all_fed)
			return (NULL);
		eat(philo);
		if (philo->data->someone_died || philo->data->all_fed)
			return (NULL);
		go_to_sleep(philo);
		if (philo->data->someone_died || philo->data->all_fed)
			return (NULL);
	}
	return (NULL);
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