/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:01:50 by lauger            #+#    #+#             */
/*   Updated: 2024/06/20 11:38:31 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void *arg)
{
	p_threads	*thread;

	if (!arg)
		return (NULL);
	thread = (p_threads *)arg;
	printf(WHITE "hello I'm philo-thread id :" YELLOW " %d\n", thread->id);
	return (NULL);
}