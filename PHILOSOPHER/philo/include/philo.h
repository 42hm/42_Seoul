/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:22:17 by hmoon             #+#    #+#             */
/*   Updated: 2022/06/14 08:05:37 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>

typedef struct s_option
{
	int		iserror;
	int		number_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_must_eat;
}				t_option;

typedef struct s_problem
{
	int				exit;
	int				isdead;
	t_option		opt;
	pthread_mutex_t	lock;
	struct timeval	start_time;
}	t_problem;

typedef struct s_fork
{
	pthread_mutex_t	lock;
	int				taken;
}	t_fork;

typedef struct s_philo_arg
{
	int			philo_num;
	int			eat_count;
	t_problem	*problem;
	t_fork		*fork[2];
}	t_philo_arg;

typedef struct s_philo
{
	pthread_t	id;
	t_philo_arg	arg;
	void		*status;
}	t_philo;

void	*table(void *arg);
int		option(int argc, char **argv, t_option *opt);
void	fork_put_down(t_fork *fork, int num);
int		fork_try(t_fork *fork, int num, struct timeval *time, time_t out);
time_t	gettimestamp(struct timeval *base);
int		set_delay(t_problem *problem, time_t delay, struct timeval *time,
			time_t out);

#endif
