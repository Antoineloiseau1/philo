/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:04:22 by anloisea          #+#    #+#             */
/*   Updated: 2023/01/10 12:14:29 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include "utils.h"

typedef struct 		s_data
{
	int				nb_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
}					t_data;

typedef struct 		s_philo
{
	t_data			*data;
	pthread_t		philo;
	pthread_mutex_t	fork;
	int				pos;
}					t_philo;


//DATA_INIT
t_philo	*init_philo(char *argv[]);
t_data	*init_data(char *argv[]);

//THREADS
int	create_threads(t_philo *philos);
int	join_threads(t_philo *philos);

//FREE
void	free_data(t_philo *philos);

#endif