/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints_no_norme.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:14:36 by lauger            #+#    #+#             */
/*   Updated: 2024/06/21 11:24:19 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_mutex_each_philo(t_philo *philo)
{
	int	i;

	i = 0;
	printf (YELLOW "\n--------------------\n\n");
	while (i < philo->nb_threads)
	{
		printf(WHITE "Hey I'm chopstick --> " CYAN "%d " WHITE "left_chopstick " CYAN "%p " WHITE "right_chopstick " CYAN"%p\n",
			philo->threads[i].id, &philo->threads[i].left_chopstick, &philo->threads[i].right_chopstick);
		i++;
	}
}