/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:14:26 by antoine           #+#    #+#             */
/*   Updated: 2023/01/23 14:44:40 by antoine          ###   ########.fr       */
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

// void	msleep(long long int ms)
// {
// 	struct timeval	time;
// 	long long int	start_time;
// 	long long int	current_time;

// 	gettimeofday(&time, NULL);
// 	start_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
// 	current_time = start_time;
// 	while (current_time - start_time < ms)
// 	{
// 		gettimeofday(&time, NULL);
// 		current_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
// 		usleep(150);
// 	}
// }

void msleep(long long ms)
{
    struct timeval start;
	struct timeval end;
	
    gettimeofday(&start, NULL);
    end.tv_sec = start.tv_sec + (ms / 1000);
    end.tv_usec = start.tv_usec + (ms % 1000) * 1000;
    if (end.tv_usec >= 1000000)
	{
        end.tv_sec++;
        end.tv_usec -= 1000000;
    }
    while (gettimeofday(&start, NULL) == 0 && (start.tv_sec < end.tv_sec || (start.tv_sec == end.tv_sec && start.tv_usec < end.tv_usec))) {
        usleep(150);
    }
}

