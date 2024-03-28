/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_cafeteria.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 06:37:31 by hmoon             #+#    #+#             */
/*   Updated: 2022/06/14 08:05:12 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <stdio.h>
#include <unistd.h>

static void	print_doing(t_problem *problem, int num, const char *str,
		int deadflag)
{
	time_t	time;

	if (!deadflag)
		pthread_mutex_lock(&problem->lock);
	if (!problem->isdead)
	{
		time = gettimestamp(&problem->start_time);
		printf("%06ld %03d %s\n", time, num, str);
	}
	if (!deadflag)
		pthread_mutex_unlock(&problem->lock);
}

static void	dead(t_philo_arg *p)
{
	const int	num = p->philo_num + 1;

	pthread_mutex_lock(&p->problem->lock);
	print_doing(p->problem, num, "died", 1);
	p->problem->isdead = 1;
	pthread_mutex_unlock(&p->problem->lock);
}

static int	eat(t_philo_arg *p, struct timeval *eat_last)
{
	int				ret;
	const int		num = p->philo_num + 1;
	const time_t	out = p->problem->opt.time_to_die;
	time_t			delay;

	ret = 0;
	if (fork_try(p->fork[0], num, eat_last, out) == 0)
	{
		print_doing(p->problem, num, "has taken a fork", 0);
		if (fork_try(p->fork[1], num, eat_last, out) == 0)
		{
			print_doing(p->problem, num, "is eating", 0);
			gettimeofday(eat_last, NULL);
			delay = p->problem->opt.time_to_eat;
			if (set_delay(p->problem, delay, eat_last, out) == 0)
				ret = 1;
			fork_put_down(p->fork[1], num);
		}
		else
			dead(p);
		fork_put_down(p->fork[0], num);
	}
	else
		dead(p);
	return (ret);
}

void	*table(void *arg)
{
	t_philo_arg *const	p = arg;
	const int			num = p->philo_num + 1;
	const time_t		out = p->problem->opt.time_to_die;
	struct timeval		eat_last;
	time_t				delay;

	pthread_mutex_lock(&p->problem->lock);
	eat_last = p->problem->start_time;
	pthread_mutex_unlock(&p->problem->lock);
	if (num & 1)
		usleep(1500);
	while (p->eat_count-- > 0)
	{
		if (!eat(p, &eat_last))
			break ;
		print_doing(p->problem, num, "is sleeping", 0);
		delay = p->problem->opt.time_to_sleep;
		if (set_delay(p->problem, delay, &eat_last, out))
			break ;
		print_doing(p->problem, num, "is thinking", 0);
		set_delay(p->problem, 1000, &eat_last, out * 0.8);
	}
	return (NULL);
}
