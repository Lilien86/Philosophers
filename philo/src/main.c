/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:37:55 by lauger            #+#    #+#             */
/*   Updated: 2024/07/02 10:52:49 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	is_valid_arguments(const int nb_args, const char **args,
	t_data *data)
{
	if (nb_args != 5 && nb_args != 6)
		if (error_exit("bad number of arguments", data) == 0)
			return (1);
	if (is_numbers((const int)nb_args, (const char **)args) != 0)
		if (error_exit("arguments must be numbers", data) == 0)
			return (1);
	return (0);
}

static int	init_input_data(t_data *data, const char **av)
{
	if (!data || !av)
		return (1);
	data->finished_count = 0;
	data->someone_died = 0;
	data->start_time = 0;
	pthread_mutex_init(&data->mutex_died, NULL);
	pthread_mutex_init(&data->mutex_print, NULL);
	pthread_mutex_init(&data->mutex_finished, NULL);
	pthread_mutex_init(&data->mutex_last_lunch, NULL);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	if (av[5] != NULL)
		data->nb_lunchs = ft_atoi(av[5]);
	else
		data->nb_lunchs = -1;
	data->nb_threads = ft_atoi(av[1]);
	if (data->t_die > 2147483647 || data->t_eat > 2147483647
		|| data->t_sleep > 2147483647)
		if (error_exit("time must be less than 2147483647ms", data) == 0)
			return (1);
	if (data->t_die < 60 || data->t_eat < 60 || data->t_sleep < 60)
		if (error_exit("time must be greater than 60ms", data) == 0)
			return (1);
	return (0);
}

static int	create_threads(t_data *data)
{
	int	i;

	data->threads = malloc(sizeof(t_threads) * data->nb_threads);
	if (!data->threads)
		if (error_exit("malloc failed", data) == 0)
			return (1);
	data->start_time = get_current_time();
	i = 0;
	while (i < data->nb_threads)
	{
		data->threads[i].id = i;
		data->threads[i].state = THINKING;
		data->threads[i].data = data;
		data->threads[i].nb_lunchs_philo = data->nb_lunchs;
		data->threads[i].last_eat_time = data->start_time;
		if (pthread_create(&data->threads[i].thread, NULL,
				&routine, &data->threads[i]) != 0)
			if (error_exit("pthread_create failed", data) == 0)
				return (1);
		usleep(10);
		i++;
	}
	return (0);
}

static int	create_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->mutex = malloc(sizeof(pthread_mutex_t) * data->nb_threads);
	if (!data->mutex)
		if (error_exit("malloc failed", data) == 0)
			return (1);
	while (i < data->nb_threads)
	{
		if (pthread_mutex_init(&data->mutex[i], NULL) != 0)
			if (error_exit("pthread_mutex_init failed", data) == 0)
				return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		if (error_exit("malloc failed", NULL) == 0)
			return (0);
	data->threads = NULL;
	data->mutex = NULL;
	if (is_valid_arguments((const int)ac, (const char **)av, data)
		||init_input_data(data, (const char **)av)
		|| create_mutex(data)
		|| create_threads(data)
		|| monitor_threads(data)
		|| join_threads(data)
		|| free_mutex(data)
		|| free_data(data))
		return (1);
	return (0);
}
