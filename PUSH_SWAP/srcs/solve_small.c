/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_small.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:59:23 by hmoon             #+#    #+#             */
/*   Updated: 2022/03/23 17:01:20 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort(t_stack *a)
{
	if (a->data[0] > a->data[1] && a->data[1] < a->data[2] && \
		a->data[2] < a->data[0])
		order(a, NULL, sa, PRINT);
	else if (a->data[0] < a->data[1] && a->data[1] < a->data[2] && \
		a->data[2] > a->data[0])
	{
		order(a, NULL, sa, PRINT);
		order(a, NULL, rra, PRINT);
	}
	else if (a->data[0] > a->data[1] && a->data[1] < a->data[2] && \
		a->data[2] > a->data[0])
		order(a, NULL, ra, PRINT);
	else if (a->data[0] < a->data[1] && a->data[1] > a->data[2] && \
		a->data[2] < a->data[0])
	{
		order(a, NULL, sa, PRINT);
		order(a, NULL, ra, PRINT);
	}
	else if (a->data[0] < a->data[1] && a->data[1] > a->data[2] && \
		a->data[2] > a->data[0])
		order(a, NULL, rra, PRINT);
}

static int	find_mid(t_stack *a)
{
	int	i;
	int	j;
	int	pb;

	i = 0;
	while (i < a->len)
	{
		j = 0;
		pb = 0;
		while (j < a->len)
		{
			if (a->data[j] - a->data[i] > 0)
				pb++;
			j++;
		}
		if (pb == 2)
			return (a->data[i]);
		i++;
	}
	return (1);
}

void	solve_small(t_stack *a, t_stack *b)
{
	while (3 < a->len)
	{
		while (top_stack(a) >= find_mid(a))
			order(a, b, ra, PRINT);
		order(a, b, pb, PRINT);
	}
	if (a->len == 3)
		sort(a);
	while (b->len > 0)
		order(a, b, pa, PRINT);
	if (a->len == 2 || top_stack(a) > a->data[a->len - 2])
		order(a, b, sa, PRINT);
}
