/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:47:35 by lauger            #+#    #+#             */
/*   Updated: 2024/06/24 12:50:14 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void monitor_threads(t_data *data)
{
	while (1)
	{
		pthread_mutex_lock(&data->mutex_died);
		if (data->someone_died == 1)
		{
			pthread_mutex_unlock(&data->mutex_died);
			join_threads(data);
			free_mutex(data);
			free_data(data);
			exit (0);
		}
		pthread_mutex_unlock(&data->mutex_died);

		pthread_mutex_lock(&data->mutex_finished);
		if (data->finished_count == data->nb_threads)
		{
			pthread_mutex_unlock(&data->mutex_finished);
			join_threads(data);
			free_mutex(data);
			free_data(data);
			exit (0);
		}
		pthread_mutex_unlock(&data->mutex_finished);
		usleep(10);
	}
}
