/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:57:29 by lauger            #+#    #+#             */
/*   Updated: 2024/06/21 10:11:08 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_eat(t_philo *philo, p_threads *thread)
{
	if (!philo || !thread)
		return ;
	thread->state = EATING;
	ms_to_us_sleep(philo->t_eat);
	printf(WHITE "philo-thread id:"
		YELLOW " %d " WHITE"State: " YELLOW"%d\n", thread->id, thread->state);
}

void	philo_sleep(t_philo *philo, p_threads *thread)
{
	if (!philo || !thread)
		return ;
	thread->state = SLEEPING;
	ms_to_us_sleep(philo->t_sleep);
	printf(WHITE "philo-thread id:"
		YELLOW " %d " WHITE"State: " YELLOW"%d\n", thread->id, thread->state);
}

void	philo_think(t_philo *philo, p_threads *thread)
{
	if (!philo || !thread)
		return ;
	thread->state = THINKING;
	ms_to_us_sleep(philo->t_die);
	printf(WHITE "philo-thread id:"
		YELLOW " %d " WHITE"State: " YELLOW"%d\n", thread->id, thread->state);
}