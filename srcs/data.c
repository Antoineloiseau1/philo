/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:01:49 by antoine           #+#    #+#             */
/*   Updated: 2023/01/12 14:23:41 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_philo	*init_philo(char *argv[])
{
	t_philo	*philo;
	t_data	*data;
	int 	i;

	data = init_data(argv);
	if (!data)
		return (NULL);
	philo = malloc(sizeof(t_philo) * data->nb_of_philo);
	if (!philo)							
		return (NULL);
	i = 0;
	while (i < data->nb_of_philo)
	{
		philo[i].data = data;
		philo[i].pos = i + 1;
		pthread_mutex_init(&philo[i].fork, NULL);
		philo[i].last_meal = 0;
		i++;
	}
	return (philo);
}

t_data	*init_data(char *argv[])
{
	t_data			*data;
	struct timeval	tv;
	
	if (check_for_errors(argv))
		return (NULL);
	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	gettimeofday(&tv, NULL);
	data->start_time = 1000000 * tv.tv_sec + tv.tv_usec;
	data->nb_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = (ft_atoi(argv[3]) * 1000);
	data->time_to_sleep = (ft_atoi(argv[4]) * 1000);
	if (argv[5])
		data->must_eat = ft_atoi(argv[5]);
	return (data);
}
