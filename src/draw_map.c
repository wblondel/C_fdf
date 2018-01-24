/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw_map.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 09:42:45 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 21:45:51 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

/*
** Draws a pixel.
*/

void		draw_pixel(int y, int x, int *pixels)
{
	int ipixel;

	ipixel = y * W_WIDTH + x;
	if (y < W_HEIGHT && y > 0 && x < W_WIDTH && x > 0)
		pixels[ipixel] = 0x6379FF;
}

/*
** Draws a line between 2 points.
** v[0] = dx
** v[1] = sx
** v[2] = dy
** v[3] = sy
** v[4] = err
** v[5] = e2
**
** https://rosettacode.org/wiki/Bitmap/Bresenham%27s_line_algorithm#C
*/

void		draw_line(t_point point0, t_point point1, int *pixels)
{
	int		v[6];

	v[0] = abs(point1.x - point0.x);
	v[1] = point0.x < point1.x ? 1 : -1;
	v[2] = abs(point1.y - point0.y);
	v[3] = point0.y < point1.y ? 1 : -1;
	v[4] = (v[0] > v[2] ? v[0] : -v[2]) / 2;
	while (1)
	{
		draw_pixel(point0.y, point0.x, pixels);
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
}

/*
** Draws all the lines between points.
*/

void		draw_lines(int *pixels, t_point *points, t_map *map)
{
	int		i;
	int		j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width - 1)
			draw_line(points[i * map->width + j],
				points[i * map->width + j + 1], pixels);
	}
	i = -1;
	while (++i < map->height - 1)
	{
		j = -1;
		while (++j < map->width)
			draw_line(points[i * map->width + j],
				points[(i + 1) * map->width + j], pixels);
	}
}

/*
** Draws all the single points.
*/

void		draw_points(int *pixels, t_point *points, t_map *map)
{
	int i;
	int j;
	int pos_x;
	int pos_y;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			pos_x = points[i * map->width + j].x;
			pos_y = points[i * map->width + j].y;
			draw_pixel(pos_y, pos_x, pixels);
			j++;
		}
		i++;
	}
}

/*
** Entry point for drawing the map.
** It first draws the points, and then the lines.
*/

void		draw_map(int *pixels, t_point *points, t_map *map)
{
	draw_points(pixels, points, map);
	draw_lines(pixels, points, map);
}
