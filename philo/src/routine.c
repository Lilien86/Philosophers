/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:01:50 by lauger            #+#    #+#             */
/*   Updated: 2024/06/21 15:10:27 by lauger           ###   ########.fr       */
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
		}
	}
	else
	{
		while (thread->data->nb_lunchs > 0)
		{
			pickup_fork(thread->data, thread);
			philo_eat(thread->data, thread);
			putdown_fork(thread->data, thread);
			philo_sleep(thread->data, thread);
			philo_think(thread->data, thread);
		}
	}
	return (NULL);
}
