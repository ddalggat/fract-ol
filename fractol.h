/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:25:59 by gjailbir          #+#    #+#             */
/*   Updated: 2021/10/26 20:40:16 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH		1000
# define HEIGHT		1000
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

typedef struct s_win {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_win;

typedef struct s_complex {
	double			re;
	double			im;
}					t_complex;

typedef struct s_fract {
	void		*mlx;
	void		*win;
	int			max_iteration;
	t_complex	min;
	t_complex	max;
	t_complex	factor;
	int			(*formula)(struct s_fract*);
	t_complex	c;
	t_complex	k;
	t_win		data;
}				t_fract;

void		ft_rendering(t_fract *fracts);

int			ft_close(t_fract *fracts);
int			ft_key_hook(int keycode, t_fract *fracts);
int			julia_motion(int x, int y, t_fract *fracts);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

t_complex	init_complex(double re, double im);
void		my_mlx_pixel_put(t_win *data, int x, int y, int color);
int			ft_get_colors(double t);

int			zoom(int button, int x, int y, t_fract *fracts);

int			julia(t_fract *fractol);
int			mandelbrot(t_fract *fracts);
int			mandelbar(t_fract *fracts);

#endif
