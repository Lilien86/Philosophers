/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints_no_norme.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:14:36 by lauger            #+#    #+#             */
/*   Updated: 2024/06/24 12:53:18 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_mutex_each_philo(t_data *data)
{
	int	i;

	i = 0;
	printf (YELLOW "\n--------------------\n\n");
	while (i < data->nb_threads)
	{
		printf(WHITE "Hey I'm chopstick --> " CYAN "%d " WHITE "left_chopstick " CYAN "%p " WHITE "right_chopstick " CYAN"%p\n",
			data->threads[i].id, &data->mutex[i], &data->mutex[(i + 1) % data->nb_threads]);
		i++;
	}
}

void	print_input_data(t_data *data)
{
	printf (YELLOW "\n--------------------\n\n");
	printf(WHITE "Number of philosophers: " CYAN "%d\n", data->nb_threads);
	printf(WHITE "Time to die: " CYAN "%d\n", data->t_die);
	printf(WHITE "Time to eat: " CYAN "%d\n", data->t_eat);
	printf(WHITE "Time to sleep: " CYAN "%d\n", data->t_sleep);
	if (data->nb_lunchs != -1)
		printf(WHITE "Number of lunchs: " CYAN "%d\n", data->nb_lunchs);
	else
		printf(WHITE "Number of lunchs: " CYAN "infinite\n");
	printf (YELLOW "\n--------------------\n\n");
}
