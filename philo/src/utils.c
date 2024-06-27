/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:45:58 by lauger            #+#    #+#             */
/*   Updated: 2024/06/27 11:44:55 by lauger           ###   ########.fr       */
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
