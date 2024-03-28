/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_kitchen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 06:41:15 by hmoon             #+#    #+#             */
/*   Updated: 2022/06/14 08:05:10 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
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

int	fork_try(t_fork *fork, int num, struct timeval *time, time_t out)
{
	int	taken;

	taken = 0;
	while (!(gettimestamp(time) > out))
	{
		pthread_mutex_lock(&fork->lock);
		if (!fork->taken)
		{
			fork->taken = num;
			taken = 1;
		}
		pthread_mutex_unlock(&fork->lock);
		if (taken)
			return (0);
		if (usleep(100) != 0)
			return (-1);
	}
	return (1);
}

void	fork_put_down(t_fork *fork, int num)
{
	pthread_mutex_lock(&fork->lock);
	if (fork->taken == num)
		fork->taken = 0;
	pthread_mutex_unlock(&fork->lock);
	usleep(500);
}

int	set_delay(t_problem *problem, time_t delay, struct timeval *time,
	time_t out)
{
	int *const		token = &problem->isdead;
	struct timeval	tv;
	int				interrupt;

	gettimeofday(&tv, NULL);
	while (gettimestamp(&tv) < delay && !(gettimestamp(time) > out))
	{
		pthread_mutex_lock(&problem->lock);
		interrupt = *token;
		pthread_mutex_unlock(&problem->lock);
		if (interrupt)
			return (1);
		if (usleep(500) != 0)
			return (-1);
	}
	return (0);
}
