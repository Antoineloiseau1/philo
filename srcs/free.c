/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:30:37 by anloisea          #+#    #+#             */
/*   Updated: 2023/01/20 17:43:36 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_data(t_philo *philo)
{
	int	i;
	int	nb_of_philo;

	nb_of_philo = philo->data->nb_of_philo;
	i = 0;
	while (i < nb_of_philo)
	{
		pthread_mutex_destroy(&philo[i].right_fork);
		i++;
	}
	// pthread_mutex_destroy(&philos->data->print);
	// free(philos->data);
	free(philo);
}