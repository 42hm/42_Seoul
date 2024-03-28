/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:27:41 by hmoon             #+#    #+#             */
/*   Updated: 2022/06/14 08:03:46 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

static int	ft_pthread_error(t_problem *problem, int iserror, int judge)
{
	if (iserror == judge)
	{
		problem->exit = 1;
		problem->isdead = 1;
		return (0);
	}
	return (1);
}

static void	start(t_problem *problem, t_philo *philos, t_fork *forks)
{
	const int	n = problem->opt.number_of_philo;
	int			iserror;
	int			i;

	pthread_mutex_lock(&problem->lock);
	i = -1;
	while (++i < n)
	{
		iserror = pthread_create(&philos[i].id, NULL, table, &philos[i].arg);
		if (!ft_pthread_error(problem, iserror, -1))
			break ;
	}
	gettimeofday(&problem->start_time, NULL);
	pthread_mutex_unlock(&problem->lock);
	while (i-- > 0)
		pthread_join(philos[i].id, &philos[i].status);
	i = -1;
	while (++i < n)
		pthread_mutex_destroy(&forks[i].lock);
	pthread_mutex_destroy(&problem->lock);
}

static int	init(t_problem *problem, t_philo *philos, t_fork *forks)
{
	const int	n = problem->opt.number_of_philo;
	int			iserror;
	int			i;

	iserror = pthread_mutex_init(&problem->lock, NULL);
	i = -1;
	while (++i < n)
	{
		if (!ft_pthread_error(problem, iserror, -1))
			return (0);
		philos[i].arg.philo_num = i;
		philos[i].arg.eat_count = problem->opt.number_of_must_eat;
		philos[i].arg.problem = problem;
		philos[i].arg.fork[!!(i & 1)] = &forks[i];
		philos[i].arg.fork[!(i & 1)] = &forks[(i + 1) % n];
		iserror = pthread_mutex_init(&forks[i].lock, NULL);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_problem	problem;
	t_philo		*philos;
	t_fork		*forks;

	memset(&problem, 0, sizeof(t_problem));
	if (!(argc > 4 && argc < 7 && option(argc, argv, &problem.opt) == 0
			&& problem.opt.iserror == 0))
	{
		printf("Usage: %s number_of_philosophers time_to_die time_to_eat \
time_to_sleep [number_of_times_each_philosopher_must_eat]\n", argv[0]);
		return (1);
	}
	philos = malloc(problem.opt.number_of_philo * sizeof(t_philo));
	forks = malloc(problem.opt.number_of_philo * sizeof(t_fork));
	if (philos && forks)
	{
		memset(philos, 0, problem.opt.number_of_philo * sizeof(t_philo));
		memset(forks, 0, problem.opt.number_of_philo * sizeof(t_fork));
		if (init(&problem, philos, forks))
		{
			start(&problem, philos, forks);
			free(philos);
			free(forks);
		}
	}
	return (problem.exit);
}
