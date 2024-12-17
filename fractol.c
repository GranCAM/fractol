/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:38:43 by carbon-m          #+#    #+#             */
/*   Updated: 2024/12/17 17:42:16 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "./MLX42/include/MLX42/MLX42.h"

/* int	ferror(void)
{
	write(1,'ERROR',5);
	return (-1);
} */
void	input_manage(int args, char **input, t_fractol fractol)
{
	if(args != 2)
		return ;
	if(ft_strncmp(input[1], "julia", 5) == 0)
		fractol.type = 1;
	else if(ft_strncmp(input[1], "mandelbrot", 10) == 0)
		fractol.type = 2;
	else if(ft_strncmp(input[1], "burningship", 11) == 0)
		fractol.type = 3;
	return ;
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;
	
	fractol.mlx = mlx_init(WIDTH, HEIGHT, "fractol", false);
	if (!fractol.mlx)
		return(0);
	fractol.img = mlx_new_image(fractol.mlx, WIDTH, HEIGHT);
	if (!fractol.img || fractol.img < 0)
		return(0);
	input_manage(argc, argv, fractol);
	return (0);
}
