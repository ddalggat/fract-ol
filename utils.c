/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:26:11 by gjailbir          #+#    #+#             */
/*   Updated: 2021/10/26 20:42:51 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_win *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr + (y * win->line_length + x * (win->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_complex	init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

int	ft_get_colors(double t)
{
	int	red;
	int	green;
	int	blue;

	red = (int)(t * 1000);
	green = (int)(t * 210);
	blue = (int)(t * 350);
	return ((int)t << 24 | red << 16 | green << 8 | blue);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = -1;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (++i < n)
	{
		if (!str2[i] && !str1[i])
			return (0);
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	}
	return (0);
}
