/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:14:26 by antoine           #+#    #+#             */
/*   Updated: 2023/01/12 12:17:34 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long int	get_time(t_data *data)
{
	long long int	current_time;
	struct timeval tv;
	
	gettimeofday(&tv, NULL);
	current_time = 1000000 * tv.tv_sec + tv.tv_usec;
	current_time = (current_time - data->start_time) / 1000;
	return (current_time);		
}