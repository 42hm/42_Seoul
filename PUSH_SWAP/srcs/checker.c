/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:13:37 by hmoon             #+#    #+#             */
/*   Updated: 2022/03/25 18:56:16 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

enum e_order	get_order2(char *command)
{
	if (ft_strcmp(command, "ra") == 0)
		return (ra);
	else if (ft_strcmp(command, "rb") == 0)
		return (rb);
	else if (ft_strcmp(command, "rr") == 0)
		return (rr);
	else if (ft_strcmp(command, "rra") == 0)
		return (rra);
	else if (ft_strcmp(command, "rrb") == 0)
		return (rrb);
	else if (ft_strcmp(command, "rrr") == 0)
		return (rrr);
	else
		print_error();
	return (1);
}

enum e_order	get_order(char *command)
{
	if (ft_strcmp(command, "sa") == 0)
		return (sa);
	else if (ft_strcmp(command, "sb") == 0)
		return (sb);
	else if (ft_strcmp(command, "ss") == 0)
		return (ss);
	else if (ft_strcmp(command, "pa") == 0)
		return (pa);
	else if (ft_strcmp(command, "pb") == 0)
		return (pb);
	else
		return (get_order2(command));
}

static void	print_check(t_stack *a, t_stack *b)
{
	if (is_sorted(a) && is_empty(b))
	{
		free(a->data);
		free(b->data);
		write(1, "OK\n", 3);
		exit(0);
	}
	else
	{
		free(a->data);
		free(b->data);
		write(1, "KO\n", 3);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	*command;

	if (argc < 2)
		return (0);
	init_stack(&a);
	parse_num(&a, argv);
	is_duplicate(&a);
	make_stack_b(&b, a.len);
	while (get_next_line(0, &command))
	{
		order(&a, &b, get_order(command), NOPRINT);
		free(command);
	}
	print_check(&a, &b);
	return (0);
}
