/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:57:29 by lauger            #+#    #+#             */
/*   Updated: 2024/06/27 11:19:05 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_eat(t_data *data, p_threads *thread)
{
	if (!data || !thread)
		return ;
	thread->state = EATING;
	thread->last_eat_time = get_current_time();
	ft_usleep(data->t_eat * 1000);
	pthread_mutex_lock(&data->mutex_died);
	if (data->someone_died == 0)
		print_data_state(data, thread);
	pthread_mutex_unlock(&data->mutex_died);
}

void	philo_sleep(t_data *data, p_threads *thread)
{
	if (!data || !thread)
		return ;
	thread->state = SLEEPING;
	ft_usleep(data->t_sleep * 1000);
	pthread_mutex_lock(&data->mutex_died);
	if (data->someone_died == 0)
		print_data_state(data, thread);
	pthread_mutex_unlock(&data->mutex_died);
}

void	philo_think(t_data *data, p_threads *thread)
{
	if (!data || !thread)
		return ;
	thread->state = THINKING;
	if (data->nb_threads == 1)
	{
		if (!data->someone_died)
			print_data_state(data, thread);
		return ;
	}
	pthread_mutex_lock(&data->mutex_died);
	if (data->someone_died == 0)
		print_data_state(data, thread);
	pthread_mutex_unlock(&data->mutex_died);
}

// void	pickup_fork(t_data *data, p_threads *thread)
// {
// 	if (!data || !thread)
// 		return ;
// 	if (data->nb_threads == 1)
// 	{
// 		if (!data->someone_died)
// 			print_data_action(data, thread, "Pickup the fork ");
// 		return ;
// 	}
// 	pthread_mutex_lock(&data->mutex[thread->id]);
// 	pthread_mutex_lock(&data->mutex[(thread->id + 1) % data->nb_threads]);
// 	pthread_mutex_lock(&data->mutex_died);
// 	if (data->someone_died == 0)
// 		print_data_action(data, thread, "Pickup the fork ");
// 	pthread_mutex_unlock(&data->mutex_died);
// }

void pickup_fork(t_data *data, p_threads *thread)
{
	int	first_lock;
	int	second_lock;

	first_lock = 0;
	second_lock = 0;
	if (!data || !thread)
		return;
	if (data->nb_threads == 1)
	{
		if (!data->someone_died)
			print_data_action(data, thread, "Pickup the fork ");
		return;
	}
	if (thread->id < (thread->id + 1) % data->nb_threads)
	{
		first_lock = thread->id;
		second_lock = (thread->id + 1) % data->nb_threads;
	}
	else
	{
		first_lock = (thread->id + 1) % data->nb_threads;
		second_lock = thread->id;
	}
	pthread_mutex_lock(&data->mutex[first_lock]);
	pthread_mutex_lock(&data->mutex[second_lock]);
	pthread_mutex_lock(&data->mutex_died);
	if (data->someone_died == 0)
		print_data_action(data, thread, "Pickup the fork ");
	pthread_mutex_unlock(&data->mutex_died);
}


void	putdown_fork(t_data *data, p_threads *thread)
{
	if (!data || !thread)
		return ;
	pthread_mutex_unlock(&data->mutex[thread->id]);
	pthread_mutex_unlock(&data->mutex[(thread->id + 1) % data->nb_threads]);
	pthread_mutex_lock(&data->mutex_died);
	if (data->someone_died == 0)
		print_data_action(data, thread, "Pickup the fork ");
	pthread_mutex_unlock(&data->mutex_died);
}
