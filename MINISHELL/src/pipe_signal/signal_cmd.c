/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 02:22:45 by hena              #+#    #+#             */
/*   Updated: 2022/07/09 00:56:11 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "minishell.h"
#include "utils.h"

void	sig_cmd_int_handler(int signal)
{
	if (signal != SIGINT)
		return ;
	g_minishell.signal = 130;
	_putendl_fd("", 2);
}

void	sig_cmd_quit_handler(int signal)
{
	if (signal != SIGQUIT)
		return ;
	g_minishell.signal = 131;
	_putendl_fd("Quit: 3", 2);
}
