/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:01:50 by lauger            #+#    #+#             */
/*   Updated: 2024/06/25 12:20:56 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void *arg)
{
	p_threads	*thread;

	if (!arg)
		return (NULL);
	thread = (p_threads *)arg;
	if (thread->data->nb_lunchs == -1)
	{
		while (1)
		{
			pickup_fork(thread->data, thread);
			philo_eat(thread->data, thread);
			putdown_fork(thread->data, thread);
			philo_sleep(thread->data, thread);
			philo_think(thread->data, thread);
			if (philo_is_die(thread))
			{
				break ;
			}
		}
	}
	else
	{
		while (thread->nb_lunchs_philo > 0)
		{
			pickup_fork(thread->data, thread);
			philo_eat(thread->data, thread);
			thread->nb_lunchs_philo--;
			if (philo_is_die(thread))
			{
				pthread_mutex_lock(&thread->data->mutex_died);
				thread->data->someone_died = 1;
				pthread_mutex_unlock(&thread->data->mutex_died);
				break ;
			}
			putdown_fork(thread->data, thread);
			philo_sleep(thread->data, thread);
			philo_think(thread->data, thread);
		}
		pthread_mutex_lock(&thread->data->mutex_finished);
		thread->data->finished_count++;
		pthread_mutex_unlock(&thread->data->mutex_finished);
	}
	return (NULL);
}
