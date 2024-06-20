/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:37:55 by lauger            #+#    #+#             */
/*   Updated: 2024/06/20 12:46:37 by lauger           ###   ########.fr       */
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

static void	init_input_data(t_philo *philo, const char **av)
{
	if (!philo || !av)
		return ;
	philo->nb_threads = ft_atoi(av[1]);
	philo->t_die = ft_atoi(av[2]);
	philo->t_eat = ft_atoi(av[3]);
	philo->t_sleep = ft_atoi(av[4]);
	if (av[5] != NULL)
		philo->nb_lunchs = ft_atoi(av[5]);
}

static void	create_threads(t_philo *philo)
{
	int	i;

	i = 0;
	philo->threads = malloc(sizeof(p_threads) * philo->nb_threads);
	if (!philo->threads)
		error_exit("malloc failed");
	while (i < philo->nb_threads)
	{
		philo->threads[i].id = i;
		if (pthread_create(&philo->threads[i].thread, NULL, &routine, &philo->threads[i]) != 0)
			error_exit("pthread_create failed");
		i++;
	}
}

int	main(int ac, char **av)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	is_valid_arguments((const int)ac, (const char **)av);
	init_input_data(philo, (const char **)av);
	create_threads(philo);
	while (philo->flag_death == FALSE)
	{
		usleep(1000);
		break ;
	}
	join_threads(philo);
	//destroy_threads(philo);
	free_philo(philo);
	return (0);
}
