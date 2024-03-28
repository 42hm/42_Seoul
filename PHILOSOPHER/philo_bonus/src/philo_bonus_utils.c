/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:17:17 by hmoon             #+#    #+#             */
/*   Updated: 2022/06/14 13:52:27 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"
#include <stdlib.h>

static long long	ft_atol(const char *str)
{
	int			sign;
	long long	num;

	num = 0;
	sign = 1;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			sign *= -1;
		str++;
	}
	while ((48 <= *str && *str <= 57) && *str)
		num = num * 10LL + (*str++ - 48);
	return (sign * num);
}

int	option(int argc, char **argv, t_option *opt)
{
	int			i;
	long long	*temp;

	i = -1;
	temp = malloc((argc - 1) * sizeof(long long));
	if (temp)
	{
		while (++i < argc - 1)
		{
			temp[i] = ft_atol(argv[i + 1]);
			if (temp[i] <= 0 || temp[i] > 2147483647)
				opt->iserror += 1;
		}
		opt->number_of_philo = temp[0];
		opt->time_to_die = temp[1];
		opt->time_to_eat = temp[2];
		opt->time_to_sleep = temp[3];
		opt->number_of_must_eat = 2147483647;
		if (argc == 6)
			opt->number_of_must_eat = temp[4];
		free(temp);
		return (0);
	}
	return (1);
}
