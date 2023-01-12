/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:01:29 by anloisea          #+#    #+#             */
/*   Updated: 2023/01/12 15:52:02 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void print_data(t_data *data)
{
	printf("nb of philo = %d\n", data->nb_of_philo);
	printf("time to die = %d\n", data->time_to_die);
	printf("time to eat = %d\n", data->time_to_eat);
	printf("time to sleep = %d\n", data->time_to_sleep);
}

void	*check_vitals(void *arg)
{
	t_philo *philo;
	int		i;

	philo = (t_philo *)arg;
	while (1)
	{
		i = 0;
		while (i < philo->data->nb_of_philo)
		{
			if (get_time(philo->data) - philo[i].last_meal >= philo->data->time_to_die)
			{
				printf("%lldms %d has died\n", get_time(philo->data), philo[i].pos);
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}

int main(int argc, char *argv[])
{
	t_philo		*philos;
	pthread_t 	vitals;

	if (argc < 5 || !(argc >= 5 && argc <= 6))
	{
		ft_putstr_fd("philo: usage: ", 2);
		ft_putstr_fd("number_of_philosophers time_to_die time_to_eat ", 2);
		ft_putstr_fd("time_to_sleep [number_of_time_each_philosopher_must_eat]\n", 2);
		return (1);	
	}
	philos = init_philo(argv);
	if (philos == NULL)
		return (1);
	pthread_create(&vitals, NULL, &check_vitals, philos);
	pthread_detach(vitals);
	while(1)
	{
		if (create_threads(philos) != 0)
			return (1);
		if (join_threads(philos) != 0)
			return (1);
	}
	free_data(philos);
	return (0);
}