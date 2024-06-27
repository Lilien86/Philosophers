/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:37:55 by lauger            #+#    #+#             */
/*   Updated: 2024/06/27 10:48:31 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	is_valid_arguments(const int nb_args, const char **args)
{
	if (nb_args != 5 && nb_args != 6)
	{
		printf(RED "Error:\nnumber of arguments is incorect:\n");
		exit (1);
	}
	if (is_numbers((const int)nb_args, (const char **)args) != 0)
	{
		printf(RED "Error:\nbad syntax\n");
		exit (1);
	}
}

static void	init_input_data(t_data *data, const char **av)
{
	if (!data || !av)
		return ;
	data->finished_count = 0;
	data->someone_died = 0;
	data->start_time = 0;
	pthread_mutex_init(&data->mutex_died, NULL);
	pthread_mutex_init(&data->mutex_print, NULL);
	pthread_mutex_init(&data->mutex_finished, NULL);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	if (av[5] != NULL)
		data->nb_lunchs = ft_atoi(av[5]);
	else
		data->nb_lunchs = -1;
	data->nb_threads = ft_atoi(av[1]);
	if (data->t_die < 60 || data->t_eat < 60 || data->t_sleep < 60)
		error_exit("time must be greater than 60ms");
	if (data->t_die > 2147483647 || data->t_eat > 2147483647
		|| data->t_sleep > 2147483647)
		error_exit("time must be less than 2147483647ms");
}

static void	create_threads(t_data *data)
{
	int	i;

	
	
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
			error_exit("pthread_create failed");
		usleep(10);
		i++;
	}
}

static void	create_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->mutex = malloc(sizeof(pthread_mutex_t) * data->nb_threads);
	while (i < data->nb_threads)
	{
		if (pthread_mutex_init(&data->mutex[i], NULL) != 0)
			error_exit("pthread_mutex_init failed");
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		error_exit("malloc failed");
	is_valid_arguments((const int)ac, (const char **)av);
	init_input_data(data, (const char **)av);
	create_mutex(data);
	create_threads(data);
	monitor_threads(data);
	join_threads(data);
	free_mutex(data);
	free_data(data);
	return (0);
}
