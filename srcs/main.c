/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:01:29 by anloisea          #+#    #+#             */
/*   Updated: 2023/01/09 18:14:38 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_philo	*init_philo(t_data *data)
{
	t_philo	*philo;
	int i;

	i = 0;
	philo = malloc(sizeof(t_philo) * data->nb_of_philo);
	while (i < data->nb_of_philo)
	{
		(philo + i)->pos = i;
		pthread_mutex_init(&(philo + i)->fork, NULL);
		i++;
	}
	return (philo);
}

t_data	*init_data(char *argv[])
{
	t_data	*data;
	int		nb_of_philo;
	
	nb_of_philo = ft_atoi(argv[1]);
	if (nb_of_philo <= 0)
	{
		ft_putstr_fd("philo: invalid number of philosophers\n", 2);
		return (NULL);
	}
	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	data->nb_of_philo = nb_of_philo;
	data->philo = init_philo(data);
	// data->time_to_die = ft_atoi(argv[2]);
	// data->time_to_eat = ft_atoi(argv[3]);
	// data->time_to_sleep = ft_atoi(argv[4]);
	// if (argv[5])
	// 	data->must_eat = ft_atoi(argv[5]);
	return (data);
}

int main(int argc, char *argv[])
{
	t_data	*data;

	(void)argc;
	// if (argc < 5 || !(argc >= 5 && argc <= 6))
	// 	return (1);
	data = init_data(argv);
	if (data == NULL)
		return (1);
	if (create_threads(data) != 0)
		return (1);
	if (join_threads(data) != 0)
		return (1);
	free_data(data);
	//system("leaks philo");
	return (0);
}