/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 02:10:53 by hmoon             #+#    #+#             */
/*   Updated: 2022/03/23 17:54:40 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->len - 1)
	{
		if (a->data[i] < a->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	make_index(t_stack *a)
{
	int	*temp;
	int	i;
	int	j;

	i = 0;
	temp = (int *)malloc(sizeof(int) * a->len);
	if (temp == NULL)
		print_error();
	while (i < a->len)
	{
		j = 0;
		temp[i] = 0;
		while (j < a->len)
		{
			if (a->data[i] > a->data[j])
				temp[i]++;
			j++;
		}
		i++;
	}
	free(a->data);
	a->data = NULL;
	a->data = temp;
}

void	make_stack_b(t_stack *b, int size)
{
	b->data = malloc(sizeof(int) * size);
	if (!b->data)
		print_error();
	b->len = 0;
	b->size = size;
}

void	make_stack_a(t_stack *a, int num)
{
	int	*temp;
	int	i;

	i = a->len;
	if (a->len >= a->size)
	{
		temp = malloc(sizeof(int) * (a->size << 1));
		if (!temp)
			print_error();
		ft_memcpy(temp, a->data, (a->len * sizeof(int)));
		free(a->data);
		a->data = temp;
		a->size <<= 1;
	}
	while (i > 0)
	{
		a->data[i] = a->data[i - 1];
		i--;
	}
	a->data[0] = num;
	a->len++;
}

void	init_stack(t_stack *stack)
{
	stack->data = malloc(sizeof(int) * 100);
	if (!stack->data)
		print_error();
	stack->len = 0;
	stack->size = 1;
}
