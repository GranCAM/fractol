/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chose_the_fractal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:38:39 by vzhadan           #+#    #+#             */
/*   Updated: 2025/01/05 14:45:38 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	draw_leaf(void *p);

/* void	chose_julia(t_fr *fr, char *set)
{
	if (set[1] == '1')
	{
		fr->julia_x = 0.285;
		fr->julia_y = 0.01;
	}
	else if (set[1] == '2')
	{
		fr->julia_x = 0.0;
		fr->julia_y = 0.8;
	}
	else if (set[1] == '3')
	{
		fr->julia_x = -0.8;
		fr->julia_y = 0.156;
	}
	fr->type = 'J';
	mlx_loop_hook(fr->mlx, draw_julia, fr);
} */

void	fr_chose(char *set, t_fr *fr)
{
	if (set[0] == 'j')
	{
		fr->julia_x = -0.7;
		fr->julia_y = 0.265;
		fr->type = 'J';
		mlx_loop_hook(fr->mlx, draw_julia, fr);
	}
	else if (set[0] == 'm')
	{
		fr->type = 'M';
		mlx_loop_hook(fr->mlx, draw_mandelbrot, fr);
	}
	else if (set[0] == 'l')
	{
		fr->type = 'L';
		mlx_loop_hook(fr->mlx, draw_leaf, fr);
	}
}

int32_t	ft_fr(char *set)
{
	t_fr	*fr;

	(void)set;
	fr = malloc(sizeof(t_fr));
	fr_init(fr);
	fr->mlx = mlx_init(fr->w_size, fr->w_size, "Fract", true);
	if (!fr->mlx)
		return (EXIT_FAILURE);
	fr->img = mlx_new_image(fr->mlx, fr->w_size, fr->w_size);
	if (!fr->img || (mlx_image_to_window(fr->mlx, fr->img, 0, 0) < 0))
		return (EXIT_FAILURE);
	mlx_loop_hook(fr->mlx, hook, fr);
	fr_chose(set, fr);
	mlx_scroll_hook(fr->mlx, scrollfunc, fr);
	mlx_loop_hook(fr->mlx, color_shift, fr);
	mlx_loop_hook(fr->mlx, move_julia, fr);
	mlx_loop(fr->mlx);
	mlx_delete_image(fr->mlx, fr->img);
	mlx_close_window(fr->mlx);
	mlx_terminate(fr->mlx);
	free(fr);
	return (EXIT_SUCCESS);
}

void	ft_print_error(void)
{
	ft_printf("\nFractol:\n\n");
	ft_printf("Type mandelbrot to display Mandelbrot set\n");
	ft_printf("Type julia to display Julia set\n");
	ft_printf("Z, X, C and V: change Julia set parameters\n");
	ft_printf("SPACE: color shift\n");
	ft_printf("ARROWS KEYS: move the view\n");
	ft_printf("MOUSE SCROLL: zoom in and out\n\n");
	ft_printf("Type E to exit\n\n");
}
