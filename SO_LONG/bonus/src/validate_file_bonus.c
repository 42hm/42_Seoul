/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:01:40 by hmoon             #+#    #+#             */
/*   Updated: 2022/05/25 17:27:54 by hmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	is_file_compatibility(int ac, char **av)
{
	if (ac != 2)
		ft_error_exit("Error\nInvalid argument");
	if (ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".ber", 4) != 0)
		ft_error_exit("Error\nInvalid file extension");
	if (ft_strlen(av[1]) < 5)
		ft_error_exit("Error\nInvalid file name");
}
