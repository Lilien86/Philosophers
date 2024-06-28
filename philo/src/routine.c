/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:01:50 by lauger            #+#    #+#             */
/*   Updated: 2024/06/28 08:21:38 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	take_actions(t_threads *thread)
{
	pickup_fork(thread->data, thread);
	philo_eat(thread->data, thread);
	putdown_fork(thread->data, thread);
	philo_sleep(thread->data, thread);
	philo_think(thread->data, thread);
}

static void	handle_single_thread(t_threads *thread)
{
	pickup_fork(thread->data, thread);
	philo_think(thread->data, thread);
	if (philo_is_die(thread))
		return ;
}

static void	handle_multiple_threads(t_threads *thread)
{
	if (thread->data->nb_lunchs == -1)
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
}

static void	handle_thread_actions(t_threads *thread)
{
	if (thread->data->nb_threads == 1)
	{
		handle_single_thread(thread);
	}
	else
	{
		handle_multiple_threads(thread);
	}
}

void	*routine(void *arg)
{
	t_threads	*thread;

	if (!arg)
		return (NULL);
	thread = (t_threads *)arg;
	handle_thread_actions(thread);
	return (NULL);
}
