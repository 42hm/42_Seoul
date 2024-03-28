/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 07:53:25 by hmoon             #+#    #+#             */
/*   Updated: 2022/06/14 18:28:59 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <unistd.h>

static int	ft_sem_error(t_problem *problem, int iserror, int judge)
{
	if (iserror == judge)
	{
		problem->exit = 1;
		problem->cancel = 1;
		return (0);
	}
	return (1);
}

static int	init_child(t_problem *problem, int *iserror)
{
	int	open_ret;

	problem->lock = NULL;
	problem->sub_lock = NULL;
	problem->forks.lock = NULL;
	*iserror = EXIT_FAILURE;
	open_ret = ft_sem_open(problem->name, &problem->lock);
	if (!ft_sem_error(problem, open_ret, -1))
		return (0);
	open_ret = ft_sem_open(problem->sub_name, &problem->sub_lock);
	if (!ft_sem_error(problem, open_ret, -1))
		return (0);
	open_ret = ft_sem_open(problem->forks.name, &problem->forks.lock);
	if (!ft_sem_error(problem, open_ret, -1))
		return (0);
	*iserror = EXIT_SUCCESS;
	return (1);
}

static void	start(t_problem *problem, t_philo *philos)
{
	int		i;
	int		iserror;
	pid_t	pid;

	gettimeofday(&problem->start_time, NULL);
	i = 0;
	while (i < problem->opt.number_of_philo)
	{
		pid = fork();
		if (!ft_sem_error(problem, pid, -1))
			break ;
		if (pid)
		{
			philos[i++].id = pid;
			continue ;
		}
		if (init_child(problem, &iserror))
			iserror = table(&philos[i].arg);
		ft_sem_close(problem->lock, problem->sub_lock, problem->forks.lock);
		exit(iserror);
	}
	ft_wait(problem, philos);
}

static int	init(t_problem *problem, t_philo *philos)
{
	int	i;

	i = -1;
	problem->name = MAIN_SEM;
	if (!ft_sem_init(problem->name, 1, &problem->lock))
		return (0);
	problem->sub_name = SUB_SEM;
	if (!ft_sem_init(problem->sub_name, 1, &problem->sub_lock))
		return (0);
	problem->forks.name = FORKS_SEM;
	if (!ft_sem_init(problem->forks.name, problem->opt.number_of_philo,
			&problem->forks.lock))
		return (0);
	while (++i < problem->opt.number_of_philo)
	{
		philos[i].arg.num_philo = i;
		philos[i].arg.eat_count = problem->opt.number_of_must_eat;
		philos[i].arg.problem = problem;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_problem	problem;
	t_philo		*philos;

	memset(&problem, 0, sizeof(t_problem));
	if (!(argc > 4 && argc < 7 && option(argc, argv, &problem.opt) == 0
			&& problem.opt.iserror == 0))
	{
		printf("Usage: %s number_of_philosophers time_to_die time_to_eat \
time_to_sleep [number_of_times_each_philosopher_must_eat]\n", argv[0]);
		return (1);
	}
	ft_sem_unlink(MAIN_SEM, SUB_SEM, FORKS_SEM);
	philos = malloc(problem.opt.number_of_philo * sizeof(t_philo));
	if (philos)
	{
		memset(philos, 0, problem.opt.number_of_philo * sizeof(t_philo));
		if (init(&problem, philos))
		{
			start(&problem, philos);
			free(philos);
		}
		ft_sem_unlink(MAIN_SEM, SUB_SEM, FORKS_SEM);
	}
	return (problem.exit);
}
