/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:04:22 by anloisea          #+#    #+#             */
/*   Updated: 2023/01/09 18:25:12 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include "utils.h"

typedef struct s_philo
{
	pthread_t		th;
	pthread_mutex_t	fork;
	int				pos;
}				t_philo;


typedef struct 		s_data
{
	t_philo			*philo;
	struct timeval	time_of_the_day;
	int				nb_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
}					t_data;

//THREADS
int	create_threads(t_data *data);
int	join_threads(t_data *data);

//FREE
void	free_data(t_data *data);

#endif