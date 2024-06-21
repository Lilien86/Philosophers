/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:57:29 by lauger            #+#    #+#             */
/*   Updated: 2024/06/21 15:09:26 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_eat(t_data *data, p_threads *thread)
{
	if (!data || !thread)
		return ;
	pthread_mutex_lock(&data->mutex_print);
	thread->state = EATING;
	pthread_mutex_unlock(&data->mutex_print);
	if (data->nb_lunchs > 0)
		data->nb_lunchs--;
	ms_to_us_sleep(data->t_eat);
	pthread_mutex_lock(&data->mutex_print);
	print_data_state(data, thread);
	pthread_mutex_unlock(&data->mutex_print);
}

void	philo_sleep(t_data *data, p_threads *thread)
{
	if (!data || !thread)
		return ;
	pthread_mutex_lock(&data->mutex_print);
	thread->state = SLEEPING;
	pthread_mutex_unlock(&data->mutex_print);
	ms_to_us_sleep(data->t_sleep);
	print_data_state(data, thread);
}

void	philo_think(t_data *data, p_threads *thread)
{
	if (!data || !thread)
		return ;
	pthread_mutex_lock(&data->mutex_print);
	thread->state = THINKING;
	pthread_mutex_unlock(&data->mutex_print);
	ms_to_us_sleep(data->t_die);
	print_data_state(data, thread);
}

void	pickup_fork(t_data *data, p_threads *thread)
{
	if (!data || !thread)
		return ;
	pthread_mutex_lock(&data->mutex[thread->id]);
	pthread_mutex_lock(&data->mutex[(thread->id + 1) % data->nb_threads]);
	print_data_action(data, thread, "Pickup the fork");
}

void	putdown_fork(t_data *data, p_threads *thread)
{
	if (!data || !thread)
		return ;
	pthread_mutex_unlock(&data->mutex[thread->id]);
	pthread_mutex_unlock(&data->mutex[(thread->id + 1) % data->nb_threads]);
	print_data_action(data, thread, "Putdown the fork");
}
