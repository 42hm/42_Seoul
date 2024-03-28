/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:40:41 by hmoon             #+#    #+#             */
/*   Updated: 2022/03/23 17:00:45 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	top_stack(t_stack *stack)
{
	return (stack->data[stack->len - 1]);
}

int	bottom_stack(t_stack *stack)
{
	return (stack->data[0]);
}

int	is_empty(t_stack *stack)
{
	if (stack->len > 0)
		return (0);
	else
		return (1);
}
