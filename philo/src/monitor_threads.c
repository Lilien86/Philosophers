/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:47:35 by lauger            #+#    #+#             */
/*   Updated: 2024/06/26 17:04:49 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	monitor_threads(t_data *data)
{
	while (1)
	{
		pthread_mutex_lock(&data->mutex_died);
		if (data->someone_died == 1 || data->nb_threads == 1)
		{
			pthread_mutex_unlock(&data->mutex_died);
			clean_exit(data);
		}
		pthread_mutex_unlock(&data->mutex_died);
		pthread_mutex_lock(&data->mutex_finished);
		if (data->finished_count == data->nb_threads)
		{
			pthread_mutex_unlock(&data->mutex_finished);
			clean_exit(data);
		}
		pthread_mutex_unlock(&data->mutex_finished);
		usleep(10);
	}
}
