/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 07:53:49 by hmoon             #+#    #+#             */
/*   Updated: 2022/06/14 14:54:49 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <semaphore.h>
# include <pthread.h>
# include <sys/time.h>

# define MAIN_SEM "main"
# define SUB_SEM "sub"
# define FORKS_SEM "forks"

typedef struct s_option
{
	int		iserror;
	int		number_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_must_eat;
}				t_option;

typedef struct s_forks
{
	const char	*name;
	sem_t		*lock;
}	t_forks;

typedef struct s_problem
{
	int				exit;
	int				cancel;
	const char		*name;
	const char		*sub_name;
	sem_t			*lock;
	sem_t			*sub_lock;
	struct timeval	start_time;
	t_forks			forks;
	t_option		opt;
}	t_problem;

typedef struct s_philo_arg
{
	int				num_philo;
	int				eat_count;
	t_problem		*problem;
	struct timeval	eat_last;
}	t_philo_arg;

typedef struct s_philo
{
	pid_t		id;
	t_philo_arg	arg;
}	t_philo;

int		option(int argc, char **argv, t_option *opt);

int		ft_sem_init(const char *name, int value, sem_t **sem_ptr);
int		ft_sem_open(const char *name, sem_t **sem_ptr);
void	ft_sem_close(sem_t *s1, sem_t *s2, sem_t *s3);
void	ft_sem_unlink(const char *s1, const char *s2, const char *s3);

int		table(void *arg);
void	ft_wait(t_problem *problem, t_philo *philos);
int		set_delay(t_problem *problem, time_t delay);
void	print_doing(t_problem *problem, int num, const char *str, int isdead);
time_t	gettimestamp(struct timeval *tv_base);

#endif
