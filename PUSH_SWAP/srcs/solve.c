/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:26:24 by hmoon             #+#    #+#             */
/*   Updated: 2022/03/25 19:30:14 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	make_chunks(t_stack *a, t_stack *b, int pivot)
{
	int	num;

	num = 0;
	while (!is_empty(a))
	{
		if (top_stack(a) <= num)
		{
			order(a, b, pb, PRINT);
			num++;
		}
		else if (num < top_stack(a) && top_stack(a) <= num + pivot)
		{
			order(a, b, pb, PRINT);
			order(a, b, rb, PRINT);
			num++;
		}
		else if (num + pivot < top_stack(a))
		{
			order(a, b, ra, PRINT);
		}
	}
}

static void	sort_b(t_stack *b, int num)
{
	int	i;

	i = 0;
	while (i < b->len && b->data[i] != num)
		i++;
	while (i < b->len / 2 && i >= 0)
	{
		order(NULL, b, rrb, PRINT);
		i--;
	}
	while (i >= b->len / 2 && i < b->len - 1)
	{
		order(NULL, b, rb, PRINT);
		i++;
	}
}

static void	put_b_to_a(t_stack *a, t_stack *b)
{
	int	num;

	num = b->len - 1;
	while (!is_empty(b))
	{
		sort_b(b, num);
		order(a, b, pa, PRINT);
		num--;
	}
}

static void	find_pivot(t_stack *a, t_stack *b)
{
	int		pivot;
	double	alpha;
	double	beta;

	alpha = 5.29427309e-7;
	beta = 0.024;
	pivot = (alpha * (a->len * a->len)) + (beta * (a->len)) + 15;
	make_chunks(a, b, pivot);
	put_b_to_a(a, b);
}

void	push_swap(t_stack *a, t_stack *b)
{
	if (a->len <= 5)
		solve_small(a, b);
	else
		find_pivot(a, b);
}
