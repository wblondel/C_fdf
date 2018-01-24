/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 09:42:45 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 13:48:41 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void			draw_map(int *pixels, t_point *points, t_map *map)
{
	int i;
	int j;
	int ipixel;
	int pos_x;
	int pos_y;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			pos_y = points[i * map->width + j].y;
			pos_x = points[i * map->width + j].x;
			ipixel = pos_y * W_WIDTH + pos_x;
			if (pos_y < W_HEIGHT && pos_y > 0 && pos_x < W_WIDTH && pos_x > 0)
				pixels[ipixel] = 0x6379FF;
			j++;
		}
		i++;
	}
}

void 		draw_ui(t_global *g)
{
	mlx_string_put(g->mlx, g->window, 10, 570, 0xFFFFFF, "Scale:");
	mlx_string_put(g->mlx, g->window, 80, 570, 0xFFFFFF, ft_itoa(g->cam.scale));

	mlx_string_put(g->mlx, g->window, 120, 570, 0xFFFFFF, "Margin X:");
	mlx_string_put(g->mlx, g->window, 220, 570, 0xFFFFFF, ft_itoa(g->cam.margin_x));
	mlx_string_put(g->mlx, g->window, 260, 570, 0xFFFFFF, "Margin Y:");
	mlx_string_put(g->mlx, g->window, 360, 570, 0xFFFFFF, ft_itoa(g->cam.margin_y));

	mlx_string_put(g->mlx, g->window, 490, 570, 0xFFFFFF, ft_itoa(g->mouse.x));
	mlx_string_put(g->mlx, g->window, 550, 570, 0xFFFFFF, ft_itoa(g->mouse.y));
}

/*
** v[0] = dx
** v[1] = sx
** v[2] = dy
** v[3] = sy
** v[4] = err
** v[5] = e2
**
** https://rosettacode.org/wiki/Bitmap/Bresenham%27s_line_algorithm#C
*/

/*static void		draw_line(t_point point0, t_point point1, int *pixels)
{
	int		v[6];

	v[0] = abs(point1.x - point0.x);
	v[1] = point0.x < point1.x ? 1 : -1;
	v[2] = abs(point1.y - point0.y);
	v[3] = point0.y < point1.y ? 1 : -1;
	v[4] = (v[0] > v[2] ? v[0] : -v[2]) / 2;

	while (1)
	{
		pixels[point0.y * W_WIDTH + point0.x] = 0x6379FF;
		if (point0.x == point1.x && point0.y == point1.y)
			break ;
		v[5] = v[4];
		if (v[5] > -v[0])
		{
			v[4] -= v[2];
			point0.x += v[1];
		}
		if (v[5] < v[2])
		{
			v[4] += v[0];
			point0.y += v[3];
		}
	}
}*/

/*static void 	toIsometric2D(t_point *point)
{
	int isoX;
	int isoY;

	isoX = point->x - point->y;
	isoY = (point->x + point->y) / 2;

	point->x = isoX;
	point->y = isoY;
}*/

/*static void 	draw_square(t_point topleft, int size, int *pixels)
{
	t_point	bottomleft = {topleft.x, topleft.y + size, topleft.z};
	t_point bottomright = {topleft.x + size, topleft.y + size, topleft.z};
	t_point topright = {topleft.x + size, topleft.y, topleft.z};

	toIsometric2D(&topleft);
	toIsometric2D(&bottomleft);
	toIsometric2D(&bottomright);
	toIsometric2D(&topright);

	draw_line(topleft, bottomleft, pixels);
	draw_line(bottomleft, bottomright, pixels);
	draw_line(bottomright, topright, pixels);
	draw_line(topright, topleft, pixels);
}*/
