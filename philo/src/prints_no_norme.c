/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints_no_norme.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:14:36 by lauger            #+#    #+#             */
/*   Updated: 2024/06/21 15:11:49 by lauger           ###   ########.fr       */
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
