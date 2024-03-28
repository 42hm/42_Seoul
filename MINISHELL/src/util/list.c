/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:02:31 by juhur             #+#    #+#             */
/*   Updated: 2022/07/09 00:52:35 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "utils.h"

t_list	*create_list(void *data)
{
	t_list	*new;

	new = _calloc(sizeof(t_list), 1);
	new->data = data;
	return (new);
}

t_list	*get_last_list(t_list *list)
{
	t_list	*last;

	if (list == NULL)
		return (NULL);
	last = list;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

void	add_list_back(t_list **list, t_list *new)
{
	t_list	*last;

	if (list == NULL || new == NULL)
		return ;
	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	last = get_last_list(*list);
	last->next = new;
}

int	count_list_node(t_list *list)
{
	int	count;

	if (list == NULL)
		return (0);
	count = 1;
	while (list->next != NULL)
	{
		++count;
		list = list->next;
	}
	return (count);
}

void	remove_all_list(t_list **list, void (*remove)(void *))
{
	t_list	*cur;
	t_list	*next;

	if (list == NULL)
		return ;
	cur = *list;
	while (cur != NULL)
	{
		next = cur->next;
		if (remove != NULL)
			remove(cur->data);
		_free((void **)&cur);
		cur = next;
	}
	*list = NULL;
}
