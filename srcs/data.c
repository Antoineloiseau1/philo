/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:01:49 by antoine           #+#    #+#             */
/*   Updated: 2023/01/10 15:02:48 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_philo	*init_philo(char *argv[])
{
	t_philo	*philo;
	int 	i;
	int		nb_of_philo;

	nb_of_philo = ft_atoi(argv[1]);
	if (nb_of_philo <= 0)
	{
		ft_putstr_fd("philo: invalid number of philosophers\n", 2);
		return (NULL);
	}
	philo = malloc(sizeof(t_philo) * nb_of_philo);
	if (!philo)							
		return (NULL);
	i = 0;
	while (i < nb_of_philo)
	{
		(philo + i)->data = init_data(argv);
		(philo + i)->pos = i;
		pthread_mutex_init(&(philo + i)->fork, NULL);
		i++;
	}
	return (philo);
}

t_data	*init_data(char *argv[])
{
	t_data	*data;
	
	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	data->nb_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->must_eat = ft_atoi(argv[5]);
	return (data);
}
