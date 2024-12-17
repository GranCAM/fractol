/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:35:25 by carbon-m          #+#    #+#             */
/*   Updated: 2024/12/17 17:29:04 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include "libft.h"
# include "./MLX42/include/MLX42/MLX42.h"
# include <math.h>
# ifndef WIDTH
#  define WIDTH 720
# endif
# ifndef HEIGHT
#  define HEIGHT 480
# endif
# ifndef MAXITER
#  define MAXITER 250
# endif

typedef struct s_fractol
{
	int			type;
	mlx_t		*mlx;
	mlx_image_t	*img;
	int32_t 	width;
	int32_t 	height;
	int			x;
	int			y;
	long		real;
	long		imaginary;
	int			cred;
	int			cgreen;
	int			cblue;
	int			zoom;
} t_fractol;


#endif
