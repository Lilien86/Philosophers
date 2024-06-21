/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:11:58 by lauger            #+#    #+#             */
/*   Updated: 2024/06/21 11:44:39 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

typedef enum
{
	THINKING,
	SLEEPING,
	EATING
} t_state;

typedef struct s_threads
{
	int					id;
	t_state				state;
	pthread_t			thread;
	pthread_mutex_t		left_chopstick;
	pthread_mutex_t		right_chopstick;
}	p_threads;

typedef struct s_philo
{
	p_threads		*threads;
	//pthread_mutex_t	*mutex;
	int				nb_threads;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nb_lunchs;
	int				flag_death;
}	t_philo;

#define TRUE 1
#define FALSE 0

//COLORS--------------------
#define BLACK	"\033[0;30m"
#define RED		"\033[0;31m"
#define GREEN	"\033[0;32m"
#define YELLOW	"\033[0;33m"
#define BLUE	"\033[0;34m"
#define MAGENTA	"\033[0;35m"
#define CYAN	"\033[0;36m"
#define WHITE	"\033[0;37m"

//TEMPORARY PRINTS --------------- NO NORM
void	print_mutex_each_philo(t_philo *philo);

//UTILS
int		is_numbers(const int nb_args, const char **args);
int		ft_atoi(const char* str);
void	error_exit(const char *msg);
void	ms_to_us_sleep(unsigned int ms);

//THREADS UTILS
void	join_threads(t_philo *philo);
void	destroy_threads(t_philo *philo);
void	free_philo(t_philo *philo);

//STATES
void	philo_think(t_philo *philo, p_threads *thread);
void	philo_sleep(t_philo *philo, p_threads *thread);
void	philo_eat(t_philo *philo, p_threads *thread);

//MAIN
void	*routine(void *arg);