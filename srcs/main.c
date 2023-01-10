/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:01:29 by anloisea          #+#    #+#             */
/*   Updated: 2023/01/10 16:18:09 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int main(int argc, char *argv[])
{
	t_philo	*philos;

	(void)argc;
	// if (argc < 5 || !(argc >= 5 && argc <= 6))
	// 	return (1);
	philos = init_philo(argv);
	if (philos == NULL)
		return (1);
	while (1)
	{
		if (create_threads(philos) != 0)
			return (1);
		if (join_threads(philos) != 0)
			return (1);
	}
	free_data(philos);
	return (0);
}