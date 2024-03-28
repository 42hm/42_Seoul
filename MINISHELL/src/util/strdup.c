/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 04:05:08 by juhur             #+#    #+#             */
/*   Updated: 2022/07/09 00:51:36 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*_strdup(char *s)
{
	char	*new;
	char	*ptr;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = _strlen(s);
	new = _calloc(s_len + 1, sizeof(char));
	ptr = new;
	while (s_len--)
		*(ptr++) = *(s++);
	return (new);
}
