/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 00:48:20 by hmoon             #+#    #+#             */
/*   Updated: 2022/03/25 19:33:11 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_split_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != 0)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

static long long	ft_atol(const char *str)
{
	long long	ret;
	int			minus;
	int			i;

	ret = 0;
	i = 0;
	minus = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = ret * 10 + str[i] - '0';
		i++;
	}
	return (ret * minus);
}

void	is_duplicate(t_stack *stack)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	while (i < stack->len)
	{
		temp = stack->data[i];
		j = i + 1;
		while (j < stack->len)
		{
			if (temp == stack->data[j++])
				print_error();
		}
		i++;
	}
}

static void	is_possible(char **str)
{
	int	i;
	int	j;

	i = 0;
	if (*str == NULL || !str)
		print_error();
	while (str[i] != 0)
	{
		j = 0;
		while (str[i][j] != 0)
		{
			if (!((str[i][j] >= '0' && str[i][j] <= '9') || \
				(str[i][j] == '+' || str[i][j] == '-')))
				print_error();
			if ((str[i][j] == '+' || str[i][j] == '-') && \
				(str[i][j + 1] == '\0'))
				print_error();
			if (j > 0 && (str[i][j] == '+' || str[i][j] == '-'))
				print_error();
			j++;
		}
		i++;
	}
}

void	parse_num(t_stack *stack, char **argv)
{
	int			i;
	int			j;
	char		**arr;
	long long	num;

	i = 1;
	while (argv[i] != 0)
	{
		if (ft_strcmp(argv[i], "") == 0)
			print_error();
		j = 0;
		arr = ft_split(argv[i++], 32);
		is_possible(arr);
		while (arr[j] != 0)
		{
			num = ft_atol(arr[j++]);
			if (num > INT_MAX || num < INT_MIN)
				print_error();
			make_stack_a(stack, (int)num);
		}
		ft_split_free(arr);
	}
}
