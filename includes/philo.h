/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:04:22 by anloisea          #+#    #+#             */
/*   Updated: 2023/01/12 15:08:43 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>
# include "utils.h"

typedef struct 		s_data
{
	long long		start_time;
	int				nb_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
}					t_data;

typedef struct 		s_philo
{
	t_data			*data;
	pthread_t		thread;
	pthread_mutex_t	fork;
	int				pos;
	long long int	last_meal;
}					t_philo;


//DATA_INIT
t_data			*init_data(char *argv[]);
t_philo			*init_philo(char *argv[]);
long long int	get_time(t_data *data);

//THREADS
int				create_threads(t_philo *philos);
int				join_threads(t_philo *philos);

//FREE
void			free_data(t_philo *philos);
void			free_threads(t_philo *philos);

#endif