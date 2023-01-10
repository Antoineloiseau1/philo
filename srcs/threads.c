/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:58:30 by anloisea          #+#    #+#             */
/*   Updated: 2023/01/10 16:25:51 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (philo->pos == 0)
	{
		if(!pthread_mutex_lock(&(philo + (philo->data->nb_of_philo -1))->fork))
		{
			printf("%d has taken fork %d\n", philo->pos, philo->pos + philo->data->nb_of_philo -1);
			if (!pthread_mutex_lock(&philo->fork))
			{
				printf("%d has taken fork %d\n", philo->pos, philo->pos);
				printf("%d is eating\n", philo->pos);
				usleep(philo->data->time_to_eat);
				pthread_mutex_unlock(&(philo + (philo->data->nb_of_philo - 1))->fork);
				//printf("philo %d has realeased fork %d\n", philo->pos, philo->pos + philo->data->nb_of_philo - 1);
				pthread_mutex_unlock(&philo->fork);
				//printf("philo %d has realeased fork %d\n", philo->pos, philo->pos);
				printf("%d is sleeping\n", philo->pos);
				usleep(philo->data->time_to_sleep);
			}
			else
			{
				pthread_mutex_unlock(&(philo + (philo->data->nb_of_philo - 1))->fork);
				//printf("philo %d has realeased fork %d\n", philo->pos, philo->pos);
				printf("%d is thinking\n", philo->pos);
			}
		}
		else
		{
			printf("%d is thinking\n", philo->pos);
			usleep(philo->data->time_to_die);
		}
	}
	else
	{
		if(!pthread_mutex_lock(&(philo - 1)->fork))
		{
			printf("%d has taken fork %d\n", philo->pos, philo->pos -1);
			if (!pthread_mutex_lock(&philo->fork))
			{
				printf("%d has taken fork %d\n", philo->pos, philo->pos);
				printf("%d is eating\n", philo->pos);
				usleep(philo->data->time_to_eat);
				pthread_mutex_unlock(&(philo - 1)->fork);
				//printf("philo %d has realeased fork %d\n", philo->pos, philo->pos - 1);
				pthread_mutex_unlock(&philo->fork);
				//printf("philo %d has realeased fork %d\n", philo->pos, philo->pos);		
				printf("%d is sleeping\n", philo->pos);
				usleep(philo->data->time_to_sleep);
			}
			else
			{
				pthread_mutex_unlock(&(philo - 1)->fork);
				//printf("philo %d has realeased fork %d\n", philo->pos, philo->pos - 1);
				printf("%d is thinking\n", philo->pos);
			}
		}
		else
		{
			printf("%d is thinking\n", philo->pos);
			usleep(philo->data->time_to_die);
		}
	}
	return (NULL);
}

int	create_threads(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->data->nb_of_philo)
	{
		if(pthread_create(&(philos + i)->philo, NULL, &routine, (philos + i)) != 0)
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
		if (pthread_join((philos + i)->philo, NULL) != 0)
		{
			ft_putstr_fd("Failed to join thread\n", 2);
			return(1);
		}
		i++;
	}
	return (0);
}