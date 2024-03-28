/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remover.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:33:40 by juhur             #+#    #+#             */
/*   Updated: 2022/07/09 00:52:54 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parse.h"
#include "utils.h"

void	data_remover(void *ptr)
{
	char	*s;

	if (ptr == NULL)
		return ;
	s = ptr;
	_free((void **)&s);
}

void	envp_remover(void *ptr)
{
	t_envp	*envp;

	if (ptr == NULL)
		return ;
	envp = ptr;
	_free((void **)&envp->key);
	_free((void **)&envp->value);
	_free((void **)&envp);
}

void	heredoc_remover(void *ptr)
{
	t_heredoc	*heredoc;

	if (ptr == NULL)
		return ;
	heredoc = ptr;
	_free((void **)&heredoc->file_name);
	_free((void **)&heredoc->end_string);
	_free((void **)&heredoc);
}

void	node_remover(void *ptr)
{
	t_node	*node;

	if (ptr == NULL)
		return ;
	node = ptr;
	_free((void **)&node->file_name);
	_free((void **)&node);
}

void	exec_remover(void *ptr)
{
	t_exec	*exec;

	if (ptr == NULL)
		return ;
	exec = ptr;
	_free((void **)&exec->cmd);
	_free((void **)&exec->cmd_path);
	_free_double_pointer((void ***)&exec->cmd_argv);
	remove_ast((void *)exec->root);
	_free((void **)&exec);
}
