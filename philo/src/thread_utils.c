/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:58:09 by lauger            #+#    #+#             */
/*   Updated: 2024/06/24 14:17:45 by lauger           ###   ########.fr       */
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

int	philo_is_die(p_threads *philo)
{
	long long	current_time;

	current_time = get_current_time();
	if (philo->data->someone_died)
		return (TRUE);
	if (current_time - philo->last_eat_time > philo->data->t_die)
	{
		pthread_mutex_lock(&philo->data->mutex_print);
		printf(RED "Philosopher %d has died.\n", philo->id);
		pthread_mutex_unlock(&philo->data->mutex_print);
		pthread_mutex_lock(&philo->data->mutex_died);
		philo->data->someone_died = 1;
		pthread_mutex_unlock(&philo->data->mutex_died);
		return (1);
	}
	return (FALSE);
}