/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:01:29 by anloisea          #+#    #+#             */
/*   Updated: 2023/01/20 17:44:14 by anloisea         ###   ########.fr       */
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

void	*check_all_fed(void *arg)
{
	t_philo	*philos;
	int		i;
	int		fed_philos;
	
	philos = (t_philo *)arg;
	fed_philos = 0;
	while (!dead_or_fed(philos->data))
	{
		i = 0;
		while (i < philos->data->nb_of_philo)
		{
			if (philos[i].has_eaten == philos->data->must_eat && philos[i].is_fed == false)
			{
				fed_philos++;
				philos[i].is_fed = true;
			}
			i++;
		}
		if (fed_philos == philos->data->nb_of_philo)
		{
			i = 0;
			while (i < philos->data->nb_of_philo)
			{
				philos[i].data->all_fed = true;
				i++;
			}
			return (NULL);
		}
	}
	return (NULL);
}

void	*check_vitals(void *arg)
{
	t_philo *philo;
	int		i;

	philo = (t_philo *)arg;
	while (!dead_or_fed(philo->data))
	{
		i = 0;
		while (i < philo->data->nb_of_philo)
		{
			if (get_time(philo->data) - philo[i].last_meal >= philo->data->time_to_die)
			{
				ft_print(&philo[i], "has died");
				i = 0;
				while (i < philo->data->nb_of_philo)
				{
					philo[i].data->someone_died = true;
					i++;
					
				}
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}

void	one_philo(t_philo *philo)
{
	ft_print(philo, "has taken a fork");
	msleep(philo->data->time_to_die);
	ft_print(philo, "has died");
	pthread_mutex_destroy(&philo->data->print);
	free_data(philo);
}

int main(int argc, char *argv[])
{
	t_philo		*philo;
	pthread_t 	vitals;
	pthread_t	check_meals;

	if (argc < 5 || !(argc >= 5 && argc <= 6))
	{
		ft_putstr_fd("philo: usage: ", 2);
		ft_putstr_fd("number_of_philosophers time_to_die time_to_eat ", 2);
		ft_putstr_fd("time_to_sleep [number_of_time_each_philosopher_must_eat]\n", 2);
		return (1);	
	}
	philo = init_philo(argv);
	if (philo == NULL)
		return (1);
	if (philo->data->nb_of_philo == 1)
	{
		one_philo(philo);
		return (0);
	}
	if (create_threads(philo) != 0)
	{
		free_data(philo);
		return (1);
	}
	pthread_create(&vitals, NULL, &check_vitals, philo);
	pthread_detach(vitals);
	pthread_create(&check_meals, NULL, &check_all_fed, philo);
	pthread_detach(check_meals);
	if (join_threads(philo) != 0)
	{
		free_data(philo);
		return (1);
	}
	free_data(philo);
	return (0);
}