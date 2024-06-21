/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:58:09 by lauger            #+#    #+#             */
/*   Updated: 2024/06/21 15:09:22 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_threads)
	{
		pthread_join(data->threads[i].thread, NULL);
		i++;
	}
}

void	destroy_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_threads)
	{
		pthread_detach(data->threads[i].thread);
		i++;
	}
}

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	free(data->threads);
	free(data);
}

void	free_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_threads)
	{
		pthread_mutex_destroy(&data->mutex[i]);
		i++;
	}
	free(data->mutex);
}
