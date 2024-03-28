/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 22:18:28 by hmoon             #+#    #+#             */
/*   Updated: 2022/08/02 17:21:28 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_calloc(size_t size)
{
	void			*p;

	p = ft_malloc(sizeof(size_t) * size);
	ft_memset(p, 0x00, size);
	return (p);
}
