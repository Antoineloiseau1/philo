/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:01:29 by anloisea          #+#    #+#             */
/*   Updated: 2023/01/23 14:46:23 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	one_philo(t_philo *philo)
{
	printf("%lld %d has taken a fork\n", get_time(philo->data), philo->pos);
	msleep(philo->data->time_to_die);
	printf("%lld %d has died\n", get_time(philo->data), philo->pos);
	free_data(philo);
}

int	main(int argc, char *argv[])
{
	t_philo		*philo;

	if (check_for_errors(argc, argv))
		return (1);
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
	if (join_threads(philo) != 0)
	{
		free_data(philo);
		return (1);
	}
	free_data(philo);
	return (0);
}
