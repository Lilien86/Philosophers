/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:00:31 by lauger            #+#    #+#             */
/*   Updated: 2024/06/28 08:21:38 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_data_state(t_data *data, t_threads *thread)
{
	long long	elapsed_time;

	if (!data || !thread)
		return ;
	pthread_mutex_lock(&data->mutex_print);
	elapsed_time = get_elapsed_time(data->start_time);
	printf(YELLOW "[%lld] ", elapsed_time);
	if (thread->state == THINKING)
	{
		printf(BLUE "%d is thinking\n" WHITE, thread->id + 1);
	}
	else if (thread->state == SLEEPING)
	{
		printf(BLUE "%d is sleeping\n" WHITE, thread->id + 1);
	}
	else if (thread->state == EATING)
	{
		printf(BLUE "%d is eating\n" WHITE, thread->id + 1);
	}
	pthread_mutex_unlock(&data->mutex_print);
}

void	print_data_action(t_data *data, t_threads *thread, char *action)
{
	long long	elapsed_time;

	if (!data || !thread || !action)
		return ;
	elapsed_time = get_elapsed_time(data->start_time);
	pthread_mutex_lock(&data->mutex_print);
	printf(YELLOW "[%lld] ", elapsed_time);
	printf(BLUE "%d %s\n" WHITE, thread->id + 1, action);
	pthread_mutex_unlock(&data->mutex_print);
}
