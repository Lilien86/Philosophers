/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:00:31 by lauger            #+#    #+#             */
/*   Updated: 2024/06/21 15:09:10 by lauger           ###   ########.fr       */
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
		printf(YELLOW "Thinking\n");
	else if (thread->state == SLEEPING)
		printf(YELLOW "Sleeping\n");
	else if (thread->state == EATING)
		printf(YELLOW "Eating\n");
	pthread_mutex_unlock(&data->mutex_print);
}

void	print_data_action(t_data *data, p_threads *thread, char *action)
{
	if (!data || !thread || !action)
		return ;
	pthread_mutex_lock(&data->mutex_print);
	printf(WHITE "data-thread id:" YELLOW " %d" GREEN" | ", thread->id);
	printf(WHITE"--%s\n", action);
	pthread_mutex_unlock(&data->mutex_print);
}
