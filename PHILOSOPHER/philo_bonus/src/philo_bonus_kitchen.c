/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_kitchen.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:10:54 by hmoon             #+#    #+#             */
/*   Updated: 2022/06/14 18:27:32 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

time_t	gettimestamp(struct timeval *base)
{
	struct timeval	tv;
	time_t			sec;
	suseconds_t		usec;

	gettimeofday(&tv, NULL);
	sec = tv.tv_sec - base->tv_sec;
	usec = tv.tv_usec - base->tv_usec;
	return (sec * 1000L + usec / 1000L);
}

void	print_doing(t_problem *problem, int num, const char *str,
				int isfinish)
{
	time_t			time_eat;

	if (!isfinish)
		sem_wait(problem->lock);
	time_eat = gettimestamp(&problem->start_time);
	printf("%06ld %03d %s\n", time_eat, num, str);
	if (!isfinish)
		sem_post(problem->lock);
}

int	set_delay(t_problem *problem, time_t delay)
{
	struct timeval	tv;

	(void)problem;
	gettimeofday(&tv, NULL);
	while (gettimestamp(&tv) < delay)
	{
		if (usleep(500) != 0)
			return (-1);
	}
	return (0);
}

void	ft_wait(t_problem *problem, t_philo *philos)
{
	const int		num = problem->opt.number_of_philo;
	pid_t			pid;
	int				i;
	int				status;

	if (!problem->cancel)
		problem->exit = EXIT_SUCCESS;
	problem->cancel = 0;
	i = num;
	while (i-- > 0)
	{
		pid = waitpid(-1, &status, 0);
		(void)pid;
		if (WEXITSTATUS(status) == EXIT_FAILURE)
		{
			if (!problem->cancel)
			{
				i = 0;
				while (i < num)
					kill(philos[i++].id, SIGTERM);
				problem->exit = EXIT_FAILURE;
				problem->cancel = 1;
			}
		}
	}
}
