/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:58:30 by anloisea          #+#    #+#             */
/*   Updated: 2023/01/09 18:22:35 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *arg)
{
	t_philo *data = arg;
	pthread_mutex_lock(data->fork);
	printf("Philo has taken a fork\n");
	pthread_mutex_destroy(data->fork);
	return (NULL);
}

int	create_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_of_philo)
	{
		if(pthread_create(&data->philo[i]->th, NULL, &routine, data->philo[i]) != 0)
		{
			ft_putstr_fd("Failed to create thread\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	join_threads(t_philo *data)
{
	int		i;

	i = 0;
	while (i < data->nb_of_philo)
	{
		if (pthread_join(data->philo[i], NULL) != 0)
		{
			ft_putstr_fd("Failed to join thread\n", 2);
			return(1);
		}
		i++;
	}
	return (0);
}