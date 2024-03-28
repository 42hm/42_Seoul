/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 03:06:39 by hmoon             #+#    #+#             */
/*   Updated: 2022/03/23 17:05:10 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	swap(t_stack *a, t_stack *b, enum e_order set)
{
	int	temp;

	if (set == sa || set == ss)
	{
		temp = top_stack(a);
		a->data[a->len - 1] = a->data[a->len - 2];
		a->data[a->len - 2] = temp;
	}
	if (set == sb || set == ss)
	{
		temp = top_stack(b);
		b->data[b->len - 1] = b->data[b->len - 2];
		b->data[b->len - 2] = temp;
	}
	return (1);
}

static int	push(t_stack *src, t_stack *dest)
{
	int	temp;

	temp = top_stack(src);
	if (!is_empty(src))
	{
		src->len--;
		dest->data[dest->len] = temp;
		dest->len++;
	}
	return (1);
}

static int	rotate(t_stack *stack)
{
	int	temp;
	int	i;

	i = stack->len - 1;
	temp = top_stack(stack);
	while (i > 0)
	{
		stack->data[i] = stack->data[i - 1];
		i--;
	}
	stack->data[0] = temp;
	return (1);
}

static int	reverse_rotate(t_stack *stack)
{
	int	temp;
	int	i;

	i = 0;
	temp = bottom_stack(stack);
	while (i < stack->len - 1)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->data[stack->len - 1] = temp;
	return (1);
}

void	order(t_stack *a, t_stack *b, enum e_order set, int printable)
{
	const char	*str[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb",
			"rr,", "rra", "rrb", "rrr"};

	if (set == sa || set == sb || set == ss)
		swap(a, b, set);
	else if (set == pa)
		push(b, a);
	else if (set == pb)
		push(a, b);
	else if (set == ra)
		rotate(a);
	else if (set == rb)
		rotate(b);
	else if (set == rr)
		rotate(a) && rotate(b);
	else if (set == rra)
		reverse_rotate(a);
	else if (set == rrb)
		reverse_rotate(b);
	else if (set == rrr)
		reverse_rotate(a) && reverse_rotate(b);
	else
		print_error();
	if (printable)
		ft_putendl_fd(str[set], 1);
}
