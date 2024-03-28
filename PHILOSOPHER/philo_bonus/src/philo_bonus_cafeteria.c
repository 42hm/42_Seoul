/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_cafeteria.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:32:14 by hmoon             #+#    #+#             */
/*   Updated: 2022/06/14 14:37:17 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"
#include <unistd.h>
#include <stdlib.h>

static int	eat(t_philo_arg *p, struct timeval *eat_last)
{
	int			result;
	const int	num = p->num_philo + 1;

	result = 0;
	sem_wait(p->problem->sub_lock);
	sem_wait(p->problem->forks.lock);
	print_doing(p->problem, num, "has taken a fork", 0);
	sem_wait(p->problem->forks.lock);
	sem_post(p->problem->sub_lock);
	sem_wait(p->problem->lock);
	print_doing(p->problem, num, "is eating", 1);
	gettimeofday(eat_last, NULL);
	sem_post(p->problem->lock);
	if (set_delay(p->problem, p->problem->opt.time_to_eat) == 0)
		result = 1;
	sem_post(p->problem->forks.lock);
	sem_post(p->problem->forks.lock);
	return (result);
}

static void	*are_you_alive(void *arg)
{
	t_philo_arg *const	p = arg;
	const int			num = p->num_philo + 1;
	const time_t		out = p->problem->opt.time_to_die;
	int					finished;
	int					died;

	while (1)
	{
		sem_wait(p->problem->lock);
		died = gettimestamp(&p->eat_last) > out;
		finished = p->problem->cancel;
		sem_post(p->problem->lock);
		if (finished)
			break ;
		if (died)
		{
			print_doing(p->problem, num, "died", 0);
			exit(EXIT_FAILURE);
		}
		usleep(500);
	}
	return (NULL);
}

int	table(void *arg)
{
	t_philo_arg *const	p = arg;
	const int			num = p->num_philo + 1;
	pthread_t			thread_id;

	p->eat_last = p->problem->start_time;
	if (pthread_create(&thread_id, NULL, are_you_alive, arg) != 0)
		return (EXIT_FAILURE);
	while (p->eat_count-- > 0)
	{
		if (!eat(p, &p->eat_last))
			return (EXIT_FAILURE);
		print_doing(p->problem, num, "is sleeping", 0);
		if (set_delay(p->problem, p->problem->opt.time_to_sleep))
			return (EXIT_FAILURE);
		print_doing(p->problem, num, "is thinking", 0);
		usleep(500);
	}
	sem_wait(p->problem->lock);
	p->problem->cancel = 1;
	sem_post(p->problem->lock);
	pthread_join(thread_id, NULL);
	return (EXIT_SUCCESS);
}
