/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strskip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:37:01 by juhur             #+#    #+#             */
/*   Updated: 2022/07/09 00:51:36 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	_strskip(char **s, char *charset)
{
	while (**s != '\0' && _strchr(charset, **s))
		++(*s);
}
