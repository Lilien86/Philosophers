/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:37:55 by lauger            #+#    #+#             */
/*   Updated: 2024/06/21 15:10:10 by lauger           ###   ########.fr       */
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
	data->flag_death = FALSE;
	if (pthread_mutex_init(&data->mutex_print, NULL) != 0)
		error_exit("pthread_mutex_init failed");
	data->nb_threads = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	if (av[5] != NULL)
		data->nb_lunchs = ft_atoi(av[5]);
	else
		data->nb_lunchs = -1;
	if (data->t_die < 60 || data->t_eat < 60 || data->t_sleep < 60)
		error_exit("time must be greater than 60ms");
}

static void	create_threads(t_data *data)
{
	int	i;

	i = 0;
	data->threads = malloc(sizeof(p_threads) * data->nb_threads);
	if (!data->threads)
		error_exit("malloc failed");
	while (i < data->nb_threads)
	{
		data->threads[i].id = i;
		data->threads[i].state = THINKING;
		data->threads[i].data = data;
		if (pthread_create(&data->threads[i].thread,
				NULL, &routine, &data->threads[i]) != 0)
			error_exit("pthread_create failed");
		usleep(1);
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
	is_valid_arguments((const int)ac, (const char **)av);
	init_input_data(data, (const char **)av);
	create_mutex(data);
	create_threads(data);
	print_mutex_each_philo(data);
	while (data->flag_death == FALSE)
	{
		usleep(1000);
		break ;
	}
	join_threads(data);
	free_mutex(data);
	free_data(data);
	return (0);
}
