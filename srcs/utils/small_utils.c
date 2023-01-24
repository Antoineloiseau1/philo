/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:33:12 by antoine           #+#    #+#             */
/*   Updated: 2023/01/24 17:42:54 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	is_even(int nb)
{
	if (nb % 2 == 0)
		return (1);
	else
		return (0);
}

int	is_alpha(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

int	dead_or_fed(t_data *data)
{
	pthread_mutex_lock(&data->dorf);
	if (data->all_fed || data->someone_died)
	{
		pthread_mutex_unlock(&data->dorf);
		return (1);
	}
	pthread_mutex_unlock(&data->dorf);
	return (0);
}
