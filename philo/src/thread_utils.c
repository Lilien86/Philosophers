/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:58:09 by lauger            #+#    #+#             */
/*   Updated: 2024/06/20 11:20:41 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	join_threads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->nb_threads)
	{
		pthread_join(philo->threads[i].thread, NULL);
		i++;
	}
}

void	destroy_threads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->nb_threads)
	{
		pthread_detach(philo->threads[i].thread);
		i++;
	}
}

void	free_philo(t_philo *philo)
{
	int	i;

	i = 0;
	free(philo->threads);
	free(philo);
}