/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:25:45 by gjailbir          #+#    #+#             */
/*   Updated: 2021/10/26 20:48:04 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_rendering(t_fract *fracts)
{
	int			x;
	int			y;
	double		t;

	y = 0;
	while (y < HEIGHT)
	{
		fracts->c.im = fracts->max.im - y * fracts->factor.im;
		x = 0;
		while (x < WIDTH)
		{
			fracts->c.re = fracts->min.re + x * fracts->factor.re;
			t = (double)fracts->formula(fracts);
			t /= (double)fracts->max_iteration;
			my_mlx_pixel_put(&fracts->data, x, y, ft_get_colors(t));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fracts->mlx, fracts->win, fracts->data.img, 0, 0);
}

void	init_variables(t_fract *fracts)
{
	fracts->mlx = mlx_init();
	fracts->win = mlx_new_window(fracts->mlx, WIDTH, HEIGHT, \
		"This is my fractal");
	fracts->data.img = mlx_new_image(fracts->mlx, WIDTH, HEIGHT);
	fracts->data.addr = (
			mlx_get_data_addr(fracts->data.img, &fracts->data.bits_per_pixel,
				&fracts->data.line_length, &fracts->data.endian));
	fracts->min = init_complex(-2.0, -2.0);
	fracts->max.re = 2.0;
	fracts->max.im = (
			fracts->min.im + (fracts->max.re - fracts->min.re) * \
				HEIGHT / WIDTH);
	fracts->factor = init_complex(
			(fracts->max.re - fracts->min.re) / (WIDTH - 1),
			(fracts->max.im - fracts->min.im) / (HEIGHT - 1));
	fracts->max_iteration = 100;
}

static	int	ft_parse(t_fract *fracts, char *arg)
{
	if (ft_strncmp("Julia", arg, 100) == 0 || \
			ft_strncmp("julia", arg, 100) == 0)
		fracts->formula = &julia;
	else if (ft_strncmp("Mandelbrot", arg, 100) == 0 || \
			 ft_strncmp("mandelbrot", arg, 100) == 0)
		fracts->formula = &mandelbrot;
	else if (ft_strncmp("Mandelbar", arg, 100) == 0 || \
			 ft_strncmp("mandelbar", arg, 100) == 0)
		fracts->formula = &mandelbar;
	else
	{
		printf("./fractol [ Mandelbrot /  Mandelbar / Julia ]\n");
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_fract	fracts;

	if (argc != 2)
		return (printf("./fractol [ Mandelbrot /  Mandelbar / Julia ]\n"));
	ft_parse(&fracts, argv[1]);
	init_variables(&fracts);
	ft_rendering(&fracts);
	mlx_hook(fracts.win, 2, 1L << 0, ft_key_hook, &fracts);
	mlx_hook(fracts.win, 17, 0, close, &fracts);
	mlx_hook(fracts.win, 4, 0, zoom, &fracts);
	mlx_hook(fracts.win, 6, 0, julia_motion, &fracts);
	mlx_loop(fracts.mlx);
}
