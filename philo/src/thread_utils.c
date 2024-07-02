/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:58:09 by lauger            #+#    #+#             */
/*   Updated: 2024/07/02 11:03:09 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_threads)
	{
		pthread_join(data->threads[i].thread, NULL);
		i++;
	}
	return (0);
}

int	free_data(t_data *data)
{
	int	i;

	i = 0;
	free(data->threads);
	free(data);
	return (0);
}

int	free_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_threads)
	{
		pthread_mutex_destroy(&data->mutex[i]);
		i++;
	}
	free(data->mutex);
	return (0);
}

int	philo_is_die(t_threads *philo)
{
	long long	current_time;

	current_time = get_current_time();
	pthread_mutex_lock(&philo->data->mutex_died);
	if (philo->data->someone_died)
	{
		pthread_mutex_unlock(&philo->data->mutex_died);
		return (TRUE);
	}
	pthread_mutex_lock(&philo->data->mutex_last_lunch);
	if (current_time - philo->last_eat_time > philo->data->t_die
		|| philo->data->nb_threads == 1)
	{
		pthread_mutex_lock(&philo->data->mutex_print);
		printf(RED "[%lld] %d died\n" WHITE,
			get_elapsed_time(philo->data->start_time), philo->id + 1);
		pthread_mutex_unlock(&philo->data->mutex_print);
		philo->data->someone_died = 1;
		pthread_mutex_unlock(&philo->data->mutex_died);
		pthread_mutex_unlock(&philo->data->mutex_last_lunch);
		return (TRUE);
	}
	pthread_mutex_unlock(&philo->data->mutex_last_lunch);
	pthread_mutex_unlock(&philo->data->mutex_died);
	return (FALSE);
}
