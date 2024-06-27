/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:45:58 by lauger            #+#    #+#             */
/*   Updated: 2024/06/27 12:29:13 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	error_exit(const char *msg, t_data *data)
{
	if (data)
	{
		if (data->threads)
			join_threads(data);
		if (data->mutex)
			free_mutex(data);
		free_data(data);
	}
	printf(RED "Error:\n%s\n" WHITE, msg);
	exit (1);
}

int	is_numbers(const int nb_args, const char **args)
{
	int	i;
	int	j;

	i = 1;
	while (i < nb_args)
	{
		j = 0;
		while (args[i][j])
		{
			if (!((args[i][j] >= '0' && args[i][j] <= '9')))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' && (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

void	clean_exit(t_data *data)
{
	join_threads(data);
	free_mutex(data);
	free_data(data);
	exit (0);
}

void	choice_first_and_second_lock(p_threads *thread, t_data *data)
{
	int	first_lock;
	int	second_lock;

	first_lock = 0;
	second_lock = 0;
	if (thread->id < (thread->id + 1) % data->nb_threads)
	{
		first_lock = thread->id;
		second_lock = (thread->id + 1) % data->nb_threads;
	}
	else
	{
		first_lock = (thread->id + 1) % data->nb_threads;
		second_lock = thread->id;
	}
	pthread_mutex_lock(&data->mutex[first_lock]);
	pthread_mutex_lock(&data->mutex[second_lock]);
}
