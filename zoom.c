/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:26:07 by gjailbir          #+#    #+#             */
/*   Updated: 2021/10/26 20:42:44 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	zoom(int button, int x, int y, t_fract *fracts)
{
	(void ) x;
	(void ) y;
	if (button == 4)
	{
		fracts->factor.re += 0.0001;
		fracts->factor.im += 0.0001;
	}
	else if (button == 5)
	{
		fracts->factor.re -= 0.0001;
		fracts->factor.im -= 0.0001;
	}
	ft_rendering(fracts);
	return (0);
}
