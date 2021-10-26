/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:25:51 by gjailbir          #+#    #+#             */
/*   Updated: 2021/10/26 20:43:03 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close(t_fract *fract)
{
	mlx_destroy_window(fract->mlx, fract->win);
	exit(0);
}

static void	ft_motion(int keycode, t_fract *fract, double tmp)
{
	if (keycode == 124)
	{
		tmp = fabs(fract->max.re - fract->min.re);
		fract->min.re -= tmp * 0.01;
		fract->max.re -= tmp * 0.01;
	}
	else if (keycode == 123)
	{
		tmp = fabs(fract->max.re - fract->min.re);
		fract->min.re += tmp * 0.01;
		fract->max.re += tmp * 0.01;
	}
	else if (keycode == 125)
	{
		tmp = fabs(fract->max.im - fract->min.im);
		fract->min.im += tmp * 0.01;
		fract->max.im += tmp * 0.01;
	}
	else if (keycode == 126)
	{
		tmp = fabs(fract->max.im - fract->min.im);
		fract->min.im -= tmp * 0.01;
		fract->max.im -= tmp * 0.01;
	}
	ft_rendering(fract);
}

int	ft_key_hook(int keycode, t_fract *fract)
{
	double	tmp;

	tmp = 0;
	if (keycode == 53)
		ft_close(fract);
	else
		ft_motion(keycode, fract, tmp);
	return (0);
}

int	julia_motion(int x, int y, t_fract *fract)
{
	fract->k = init_complex(
			2.0 *((double)x / WIDTH - 0.5),
			2.0 *((double)(HEIGHT - y) / HEIGHT - 0.5));
	ft_rendering(fract);
	return (0);
}
