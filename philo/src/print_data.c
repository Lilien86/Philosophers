/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:00:31 by lauger            #+#    #+#             */
/*   Updated: 2024/06/24 14:16:49 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_data_state(t_data *data, p_threads *thread)
{
	if (!data || !thread)
		return ;
	pthread_mutex_lock(&data->mutex_print);
	printf(WHITE "data-thread id:" YELLOW " %d" GREEN" | ", thread->id);
	printf(WHITE"--State: ");
	if (thread->state == THINKING)
	{
		printf(YELLOW "Thinking" GREEN"  | ");
		printf(WHITE "Thinking time: " YELLOW "%lld\n",
			get_elapsed_time(thread->last_eat_time));
	}
	else if (thread->state == SLEEPING)
	{
		printf(YELLOW "Sleeping" GREEN"  | ");
		printf(WHITE "Sleeping time: " YELLOW "%lld\n",
			get_elapsed_time(thread->last_eat_time));
	}
	else if (thread->state == EATING)
	{
		printf(YELLOW "Eating" GREEN"    | ");
		printf(WHITE "Eating   time: " YELLOW "%lld\n",
			get_elapsed_time(thread->last_eat_time));
	}
	pthread_mutex_unlock(&data->mutex_print);
}

void	print_data_action(t_data *data, p_threads *thread, char *action)
{
	if (!data || !thread || !action)
		return ;
	pthread_mutex_lock(&data->mutex_print);
	printf(WHITE "data-thread id:" YELLOW " %d" GREEN" | ", thread->id);
	printf(MAGENTA "--%s " GREEN"| ", action);
	printf(WHITE "Get fork time: " YELLOW "%lld\n",
		get_elapsed_time(thread->last_eat_time));
	pthread_mutex_unlock(&data->mutex_print);
}
