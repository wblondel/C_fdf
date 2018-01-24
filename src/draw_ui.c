/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw_ui.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 20:37:40 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 23:38:51 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_point			new_point(x, y, z)
{
	t_point point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

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

	mlx_string_put(g->mlx, g->window, W_WIDTH - 260, 0, 0xFFFFFF, "Angles pour calc x:");
	mlx_string_put(g->mlx, g->window, W_WIDTH - 260, 20, 0xFFFFFF, "Angle 1    ++    --");
	mlx_string_put(g->mlx, g->window, W_WIDTH - 260, 40, 0xFFFFFF, "Angle 2    ++    --");
	mlx_string_put(g->mlx, g->window, W_WIDTH - 260, 60, 0xFFFFFF, "Angle 3    ++    --");
/*	mlx_string_put(g->mlx, g->window, W_WIDTH - 260, 80, 0xFFFFFF, "Angle 4    ++    --");
	mlx_string_put(g->mlx, g->window, W_WIDTH - 260, 100, 0xFFFFFF, "Angle 5    ++    --");*/

	mlx_string_put(g->mlx, g->window, W_WIDTH - 40, 20, 0xFFFFFF, ft_itoa(g->cam.angle_x_1));
	mlx_string_put(g->mlx, g->window, W_WIDTH - 40, 40, 0xFFFFFF, ft_itoa(g->cam.angle_x_2));
	mlx_string_put(g->mlx, g->window, W_WIDTH - 40, 60, 0xFFFFFF, ft_itoa(g->cam.angle_x_3));
	/*mlx_string_put(g->mlx, g->window, W_WIDTH - 40, 80, 0xFFFFFF, ft_itoa(g->cam.angle_x_4));
	mlx_string_put(g->mlx, g->window, W_WIDTH - 40, 100, 0xFFFFFF, ft_itoa(g->cam.angle_x_5));*/

	mlx_string_put(g->mlx, g->window, W_WIDTH - 260, 130, 0xFFFFFF, "Angles pour calc y:");
	mlx_string_put(g->mlx, g->window, W_WIDTH - 260, 150, 0xFFFFFF, "Angle 1    ++    --");
	mlx_string_put(g->mlx, g->window, W_WIDTH - 260, 170, 0xFFFFFF, "Angle 2    ++    --");
	mlx_string_put(g->mlx, g->window, W_WIDTH - 260, 190, 0xFFFFFF, "Angle 3    ++    --");
	/*mlx_string_put(g->mlx, g->window, W_WIDTH - 260, 210, 0xFFFFFF, "Angle 4    ++    --");
	mlx_string_put(g->mlx, g->window, W_WIDTH - 260, 230, 0xFFFFFF, "Angle 5    ++    --");*/

	mlx_string_put(g->mlx, g->window, W_WIDTH - 40, 150, 0xFFFFFF, ft_itoa(g->cam.angle_y_1));
	mlx_string_put(g->mlx, g->window, W_WIDTH - 40, 170, 0xFFFFFF, ft_itoa(g->cam.angle_y_2));
	mlx_string_put(g->mlx, g->window, W_WIDTH - 40, 190, 0xFFFFFF, ft_itoa(g->cam.angle_y_3));
	/*mlx_string_put(g->mlx, g->window, W_WIDTH - 40, 210, 0xFFFFFF, ft_itoa(g->cam.angle_y_4));
	mlx_string_put(g->mlx, g->window, W_WIDTH - 40, 230, 0xFFFFFF, ft_itoa(g->cam.angle_y_5));*/
}

void			draw_ui2(t_global *g)
{
	draw_line(new_point(W_WIDTH - 270, 0, 0), new_point(W_WIDTH - 270, W_HEIGHT, 0), g->image.pixels);

	draw_line(new_point(W_WIDTH - 270, 130, 0), new_point(W_WIDTH, 130, 0), g->image.pixels);
	draw_line(new_point(W_WIDTH - 270, 260, 0), new_point(W_WIDTH, 260, 0), g->image.pixels);
}
