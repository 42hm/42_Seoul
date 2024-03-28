/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:11:46 by hmoon             #+#    #+#             */
/*   Updated: 2022/03/23 20:33:02 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# define PRINT 1
# define NOPRINT 0

# define INT_MAX 2147483647LL
# define INT_MIN -2147483648LL

typedef struct s_stack
{
	int			*data;
	int			len;
	int			size;
}				t_stack;

enum	e_order
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
};

int			is_sorted(t_stack *a);
void		init_stack(t_stack *stack);
void		make_stack_b(t_stack *b, int size);
void		make_stack_a(t_stack *a, int num);
void		make_index(t_stack *a);
int			is_empty(t_stack *stack);
int			bottom_stack(t_stack *stack);
int			top_stack(t_stack *stack);
void		order(t_stack *a, t_stack *b, enum e_order set, int printable);
void		print_error(void);
void		parse_num(t_stack *stack, char **argv);
void		push_swap(t_stack *a, t_stack *b);
void		solve_small(t_stack *a, t_stack *b);
void		is_duplicate(t_stack *stack);

#endif
