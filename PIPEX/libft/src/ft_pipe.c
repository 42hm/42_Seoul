/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:43:19 by hmoon             #+#    #+#             */
/*   Updated: 2022/04/29 05:02:57 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <errno.h>
#include <stdlib.h>

int	ft_pipe(int pipefd[2])
{
	if (pipe(pipefd) == -1)
	{
		ft_perror("pipe", errno);
		exit(EXIT_FAILURE);
	}
	return (1);
}
