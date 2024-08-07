/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:59:43 by lauger            #+#    #+#             */
/*   Updated: 2024/06/26 14:55:59 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long long	get_current_time(void)
{
	struct timeval	tv;
	long long		current_time;

	gettimeofday(&tv, NULL);
	current_time = (tv.tv_sec * 1000LL + tv.tv_usec / 1000LL);
	return (current_time);
}

long long	ft_time(void)
{
	struct timeval	tv;
	long long		current_time;

	gettimeofday(&tv, NULL);
	current_time = (tv.tv_sec * 1000000LL + tv.tv_usec);
	return (current_time);
}

long long	get_elapsed_time(long long start_time)
{
	long long	elapsed_time;

	elapsed_time = get_current_time() - start_time;
	return (elapsed_time);
}

void	ms_to_us_sleep(unsigned int ms)
{
	unsigned int	us;

	us = ms * 1000;
	usleep(us);
}

void	ft_usleep(long long time)
{
	long long	start;

	start = ft_time();
	while (ft_time() - start < time)
		usleep(30);
}
