/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:02:17 by lauger            #+#    #+#             */
/*   Updated: 2024/07/02 11:17:26 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	check_threads_status(t_data *data, int i)
{
	while (1)
	{
		i = 0;
		pthread_mutex_lock(&data->mutex_finished);
		if (data->finished_count == data->nb_threads)
		{
			pthread_mutex_unlock(&data->mutex_finished);
			if (clean_exit(data) == 0)
				return (1);
		}
		pthread_mutex_unlock(&data->mutex_finished);
		pthread_mutex_lock(&data->mutex_died);
		if (data->someone_died == 1 || data->nb_threads == 1)
		{
			pthread_mutex_unlock(&data->mutex_died);
			if (clean_exit(data) == 0)
				return (1);
		}
		pthread_mutex_unlock(&data->mutex_died);
		while (i < data->nb_threads)
			if (philo_is_die(&data->threads[i++]) == TRUE)
				break ;
		usleep(10000);
	}
}

int	monitor_threads(t_data *data)
{
	int	i;

	i = 0;
	if (data->nb_threads == 1)
	{
		ft_usleep(data->t_die * 1000);
		philo_is_die(&data->threads[0]);
	}
	else
	{
		if (check_threads_status(data, i) == 1)
			return (1);
	}
	return (0);
}
