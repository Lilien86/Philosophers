/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:11:58 by lauger            #+#    #+#             */
/*   Updated: 2024/06/21 13:09:52 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

struct	s_data;
struct	s_threads;

typedef	enum
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
	struct s_data		*data;
	int					nb_lunchs_philo;
	long long			last_eat_time;
}	p_threads;

typedef struct s_data
{
	p_threads		*threads;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	mutex_print;
	int				nb_threads;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nb_lunchs;
	pthread_mutex_t	mutex_finished;
	int				finished_count;
	pthread_mutex_t	mutex_died;
	int				someone_died;
	long long		start_time;
}	t_data;

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
void		print_mutex_each_philo(t_data *data);
void		print_input_data(t_data *data);

//UTILS
int			is_numbers(const int nb_args, const char **args);
int			ft_atoi(const char* str);
void		error_exit(const char *msg);
void		clean_exit(t_data *data);

//THREADS UTILS
void		join_threads(t_data *data);
void		destroy_threads(t_data *data);
void		free_data(t_data *data);
void		free_mutex(t_data *data);
int			philo_is_die(p_threads *philo);
int			philo_is_die_for_main(p_threads *philo);

//TIME UTILS
long long	get_elapsed_time(long long start_time);
void		ms_to_us_sleep(unsigned int ms);
long long	get_current_time(void);
void		ft_usleep(long long time);
long long	ft_time(void);


//STATES_and_ACTIONS
void		philo_think(t_data *data, p_threads *thread);
void		philo_sleep(t_data *data, p_threads *thread);
void		philo_eat(t_data *data, p_threads *thread);
void		pickup_fork(t_data *data, p_threads *thread);
void		putdown_fork(t_data *data, p_threads *thread);

//MAIN
void		*routine(void *arg);
void		print_data_state(t_data *data, p_threads *thread);
void		print_data_action(t_data *data, p_threads *thread, char *action);
void		monitor_threads(t_data *data);