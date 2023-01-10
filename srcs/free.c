/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:30:37 by anloisea          #+#    #+#             */
/*   Updated: 2023/01/10 11:11:04 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_data(t_philo *philos)
{
	int	i;
	int	nb_of_philo;

	nb_of_philo = philos->data->nb_of_philo;
	i = 0;
	while (i < nb_of_philo)
	{
		free((philos + i)->data);
		pthread_mutex_destroy(&(philos + i)->fork);
		i++;
	}
	free(philos);
}