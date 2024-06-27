/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:58:09 by lauger            #+#    #+#             */
/*   Updated: 2024/06/27 10:05:30 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_threads)
	{
		pthread_join(data->threads[i].thread, NULL);
		i++;
	}
}

void	destroy_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_threads)
	{
		pthread_detach(data->threads[i].thread);
		i++;
	}
}

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	free(data->threads);
	free(data);
}

void	free_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_threads)
	{
		pthread_mutex_destroy(&data->mutex[i]);
		i++;
	}
	free(data->mutex);
}

int	philo_is_die(p_threads *philo)
{
	long long	current_time;

	current_time = get_current_time();
	pthread_mutex_lock(&philo->data->mutex_died);
	if (philo->data->someone_died)
	{
		pthread_mutex_unlock(&philo->data->mutex_died);
		return (TRUE);
	}
	if (current_time - philo->last_eat_time > philo->data->t_die
		|| philo->data->nb_threads == 1)
	{
		pthread_mutex_lock(&philo->data->mutex_print);
		ft_usleep(philo->data->t_die * 1000);
		printf(RED "data-thread id: %d | "
			"--State: DIE       | Die      time: %lld\n" WHITE,
			philo->id, get_elapsed_time(philo->data->start_time));
		pthread_mutex_unlock(&philo->data->mutex_print);
		philo->data->someone_died = 1;
		pthread_mutex_unlock(&philo->data->mutex_died);
		return (TRUE);
	}
	pthread_mutex_unlock(&philo->data->mutex_died);
	return (FALSE);
}

int philo_is_die_for_main(p_threads *philo)
{
	long long current_time;

	current_time = get_current_time();

	if (philo->data->someone_died)
	{
		return (TRUE);
	}
	if (current_time - philo->last_eat_time > philo->data->t_die || philo->data->nb_threads == 1)
	{
		pthread_mutex_lock(&philo->data->mutex_print);
		if (philo->data->nb_threads == 1)
			ft_usleep(philo->data->t_die * 1000);
		printf(RED "data-thread id: %d | "
			"--State: DIE       | Die      time: %lld\n" WHITE,
			philo->id, get_elapsed_time(philo->data->start_time));
		pthread_mutex_unlock(&philo->data->mutex_print);
		philo->data->someone_died = 1;
		return (TRUE);
	}

	return (FALSE);
}

