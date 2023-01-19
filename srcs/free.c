/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:30:37 by anloisea          #+#    #+#             */
/*   Updated: 2023/01/19 16:13:41 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_threads(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->data->nb_of_philo)
	{
		free(&philos[i].thread);
		i++;
	}
}

void	free_data(t_philo *philos)
{
	int	i;
	int	nb_of_philo;

	nb_of_philo = philos->data->nb_of_philo;
	i = 0;
	while (i < nb_of_philo)
	{
		pthread_mutex_destroy(&philos[i].right_fork);
		i++;
	}
	// pthread_mutex_destroy(&philos->data->print);
	// free(philos->data);
	free(philos);
}