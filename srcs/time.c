/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:14:26 by antoine           #+#    #+#             */
/*   Updated: 2023/01/24 14:47:40 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long int	get_time(t_data *data)
{
	long long int	current_time;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	current_time = (1000 * tv.tv_sec) + (tv.tv_usec / 1000);
	current_time = (current_time - data->start_time);
	return (current_time);
}

void	msleep(long long int ms)
{
	struct timeval	time;
	long long int	start_time;
	long long int	current_time;

	gettimeofday(&time, NULL);
	start_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	current_time = start_time;
	while (current_time - start_time < ms)
	{
		gettimeofday(&time, NULL);
		current_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
		usleep(150);
	}
}
