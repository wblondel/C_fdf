/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw_ui.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 20:37:40 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 20:57:09 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

/*
** Draws the UI.
*/

void			draw_ui(t_global *g)
{
	mlx_string_put(g->mlx, g->window, 10, W_HEIGHT - 30, 0xFFFFFF,
					"Scale:");
	mlx_string_put(g->mlx, g->window, 80, W_HEIGHT - 30, 0xFFFFFF,
					ft_itoa(g->cam.scale));
	mlx_string_put(g->mlx, g->window, 120, W_HEIGHT - 30, 0xFFFFFF,
					"Margin X:");
	mlx_string_put(g->mlx, g->window, 220, W_HEIGHT - 30, 0xFFFFFF,
					ft_itoa(g->cam.margin_x));
	mlx_string_put(g->mlx, g->window, 260, W_HEIGHT - 30, 0xFFFFFF,
					"Margin Y:");
	mlx_string_put(g->mlx, g->window, 360, W_HEIGHT - 30, 0xFFFFFF,
					ft_itoa(g->cam.margin_y));
	mlx_string_put(g->mlx, g->window, 490, W_HEIGHT - 30, 0xFFFFFF,
					ft_itoa(g->mouse.x));
	mlx_string_put(g->mlx, g->window, 550, W_HEIGHT - 30, 0xFFFFFF,
					ft_itoa(g->mouse.y));
}
