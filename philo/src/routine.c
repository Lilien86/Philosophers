/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:01:50 by lauger            #+#    #+#             */
/*   Updated: 2024/06/27 09:15:33 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	take_actions(p_threads *thread)
{
	pickup_fork(thread->data, thread);
	philo_eat(thread->data, thread);
	putdown_fork(thread->data, thread);
	philo_sleep(thread->data, thread);
	philo_think(thread->data, thread);
}

void	*routine(void *arg)
{
	p_threads	*thread;

	if (!arg)
		return (NULL);
	thread = (p_threads *)arg;
	if (thread->data->nb_threads == 1)
	{
		pickup_fork(thread->data, thread);
		philo_think(thread->data, thread);
		if (philo_is_die(thread))
				return (NULL);
	}
	else if (thread->data->nb_lunchs == -1)
	{
		while (1)
		{
			take_actions(thread);
			if (philo_is_die(thread))
				break ;
		}
	}
	else
	{
		while (thread->nb_lunchs_philo > 0)
		{
			take_actions(thread);
			if (philo_is_die(thread))
				break ;
			thread->nb_lunchs_philo--;
		}
		pthread_mutex_lock(&thread->data->mutex_finished);
		thread->data->finished_count++;
		pthread_mutex_unlock(&thread->data->mutex_finished);
	}
	return (NULL);
}
