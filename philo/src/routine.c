/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:01:50 by lauger            #+#    #+#             */
/*   Updated: 2024/06/26 16:01:21 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// void	take_actions(p_threads *thread)
// {
// 	if (philo_is_die(thread))
// 				break ;
// 	pickup_fork(thread->data, thread);
// 	if (philo_is_die(thread))
// 				break ;
// 	philo_eat(thread->data, thread);
// 	if (philo_is_die(thread))
// 				break ;
// 	putdown_fork(thread->data, thread);
// 	if (philo_is_die(thread))
// 				break ;
// 	philo_sleep(thread->data, thread);
// 	if (philo_is_die(thread))
// 				break ;
// 	philo_think(thread->data, thread);
// }

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
			if (philo_is_die(thread))
				break ;
			pickup_fork(thread->data, thread);
			if (philo_is_die(thread))
						break ;
			philo_eat(thread->data, thread);
			if (philo_is_die(thread))
						break ;
			putdown_fork(thread->data, thread);
			if (philo_is_die(thread))
						break ;
			philo_sleep(thread->data, thread);
			if (philo_is_die(thread))
						break ;
			philo_think(thread->data, thread);
			if (philo_is_die(thread))
				break ;
		}
	}
	// else
	// {
	// 	while (thread->nb_lunchs_philo > 0)
	// 	{
	// 		take_actions(thread);
	// 		thread->nb_lunchs_philo--;
	// 		if (philo_is_die(thread))
	// 			break ;
	// 	}
	// 	pthread_mutex_lock(&thread->data->mutex_finished);
	// 	thread->data->finished_count++;
	// 	pthread_mutex_unlock(&thread->data->mutex_finished);
	// }
	return (NULL);
}
