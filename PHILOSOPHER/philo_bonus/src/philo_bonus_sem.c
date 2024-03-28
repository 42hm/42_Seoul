/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_sem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:32:31 by hmoon             #+#    #+#             */
/*   Updated: 2022/06/14 14:07:40 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"
#include <sys/stat.h>

int	ft_sem_init(const char *name, int value, sem_t **sem_ptr)
{
	sem_t	*sem;

	sem = sem_open(name, O_CREAT, S_IRWXU, value);
	if (sem == SEM_FAILED)
		return (0);
	*sem_ptr = sem;
	return (1);
}

int	ft_sem_open(const char *name, sem_t **sem_ptr)
{
	sem_t	*sem;

	sem = sem_open(name, O_RDWR);
	if (sem == SEM_FAILED)
		return (0);
	*sem_ptr = sem;
	return (1);
}

void	ft_sem_close(sem_t *s1, sem_t *s2, sem_t *s3)
{
	sem_close(s1);
	sem_close(s2);
	sem_close(s3);
}

void	ft_sem_unlink(const char *s1, const char *s2, const char *s3)
{
	sem_unlink(s1);
	sem_unlink(s2);
	sem_unlink(s3);
}
