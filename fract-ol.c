/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:25:55 by gjailbir          #+#    #+#             */
/*   Updated: 2021/10/26 20:43:19 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_fract *fractol)
{
	int			i;
	t_complex	z;

	i = 0;
	z = init_complex(fractol->c.re, fractol->c.im);
	while ((z.re * z.re) + (z.im * z.im) <= 4
		   && i < fractol->max_iteration)
	{
		z = init_complex(
				(z.re * z.re) - (z.im * z.im) + fractol->k.re,
				2.0 * z.re * z.im + fractol->k.im);
		i++;
	}
	return (i);
}

int	mandelbrot(t_fract *fracts)
{
	t_complex	z;
	int			i;

	z = init_complex(fracts->c.re, fracts->c.im);
	i = 0;
	while ((z.re * z.re) + (z.im * z.im) <= 4
		   && i < fracts->max_iteration)
	{
		z = init_complex(
				(z.re * z.re) - (z.im * z.im) + fracts->c.re,
				2.0 * z.re * z.im + fracts->c.im);
		i++;
	}
	return (i);
}

int	mandelbar(t_fract *fracts)
{
	t_complex	z;
	int			i;

	z = init_complex(fracts->c.re, fracts->c.im);
	i = 0;
	while ((z.re * z.re) + (z.im * z.im) <= 4
		   && i < fracts->max_iteration)
	{
		z = init_complex(
				(z.re * z.re) - (z.im * z.im) + fracts->c.re,
				-2.0 * z.re * z.im + fracts->c.im);
		i++;
	}
	return (i);
}
