/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:55:49 by vzhadan           #+#    #+#             */
/*   Updated: 2024/12/30 17:19:53 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

int32_t	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!(ft_strncmp(argv[1], "julia", 5)) || !(ft_strncmp(argv[1], "mandel", 6))
			|| !(ft_strncmp(argv[1], "L", 2)))
			return (ft_fr(argv[1]));
		else
			ft_print_error();
	}
	else
		ft_print_error();
	return (0);
}
