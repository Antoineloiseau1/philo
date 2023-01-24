/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:04:22 by anloisea          #+#    #+#             */
/*   Updated: 2023/01/24 17:41:43 by anloisea         ###   ########.fr       */
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
# include <stdbool.h>
# include "utils.h"

typedef struct s_data
{
	long long		start_time;
	int				nb_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	bool			someone_died;
	bool			all_fed;
	pthread_mutex_t	print;
	pthread_mutex_t	dorf;
	pthread_mutex_t	lock_value;
}					t_data;

typedef struct s_philo
{
	t_data			*data;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	right_fork;
	int				pos;
	int				has_eaten;
	bool			is_fed;
	long long int	last_meal;
}					t_philo;

//DATA_INIT
t_data			*init_data(char *argv[]);
t_philo			*init_philo(char *argv[]);

//TIME
void			msleep(long long int ms);
long long int	get_time(t_data *data);

//THREADS
int				create_threads(t_philo *philos);
int				join_threads(t_philo *philos);
int				dead_or_fed(t_data *data);
int				is_time_to_die(t_philo *philo, int i);
int				is_all_fed(t_philo *philo, int fed_philos);

//ACTIONS
void			eat(t_philo *philo);
void			go_to_sleep(t_philo *philo);
void			think(t_philo *philo);
void			ft_print(t_philo *philo, char *msg);

//FREE
void			free_data(t_philo *philo);

#endif