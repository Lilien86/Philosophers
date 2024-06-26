/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:57:29 by lauger            #+#    #+#             */
/*   Updated: 2024/06/26 14:25:00 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_eat(t_data *data, p_threads *thread)
{
	if (!data || !thread)
		return ;
	thread->state = EATING;
	thread->last_eat_time = get_current_time();
	ms_to_us_sleep(data->t_eat);
	pthread_mutex_lock(&data->mutex_died);
	if (!data->someone_died)
	{
		print_data_state(data, thread);
		pthread_mutex_unlock(&data->mutex_died);
	}
	else
		pthread_mutex_unlock(&data->mutex_died);
}

void	philo_sleep(t_data *data, p_threads *thread)
{
	if (!data || !thread)
		return ;
	thread->state = SLEEPING;
	ms_to_us_sleep(data->t_sleep);
	pthread_mutex_lock(&data->mutex_died);
	if (!data->someone_died)
	{
		print_data_state(data, thread);
		pthread_mutex_unlock(&data->mutex_died);
	}
	else
		pthread_mutex_unlock(&data->mutex_died);
}

void	philo_think(t_data *data, p_threads *thread)
{
	if (!data || !thread)
		return ;
	thread->state = THINKING;
	pthread_mutex_lock(&data->mutex_died);
	if (!data->someone_died)
	{
		print_data_state(data, thread);
		pthread_mutex_unlock(&data->mutex_died);
	}
	else
		pthread_mutex_unlock(&data->mutex_died);
}

void	pickup_fork(t_data *data, p_threads *thread)
{
	if (!data || !thread)
		return ;
	pthread_mutex_lock(&data->mutex[thread->id]);
	pthread_mutex_lock(&data->mutex[(thread->id + 1) % data->nb_threads]);
	pthread_mutex_lock(&data->mutex_died);
	if (!data->someone_died)
	{
		print_data_action(data, thread, "Pickup the fork ");
		pthread_mutex_unlock(&data->mutex_died);
	}
	else
		pthread_mutex_unlock(&data->mutex_died);
}

void	putdown_fork(t_data *data, p_threads *thread)
{
	if (!data || !thread)
		return ;
	pthread_mutex_unlock(&data->mutex[thread->id]);
	pthread_mutex_unlock(&data->mutex[(thread->id + 1) % data->nb_threads]);
}
