/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/09 14:46:58 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/09 15:20:29 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

/*
** Draws a pixel.
*/

static int		draw_pixel(int y, int x, int color, int *pixels)
{
	int		ipixel;

	ipixel = y * W_WIDTH + x;
	if (y < W_HEIGHT && y > 0 && x < W_WIDTH && x > 0)
	{
		pixels[ipixel] = color;
		return (0);
	}
	return (-1);
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

void			draw_line(t_point point0, t_point point1, int *pixels)
{
	int		v[6];

	v[0] = abs(point1.x - point0.x);
	v[1] = point0.x < point1.x ? 1 : -1;
	v[2] = abs(point1.y - point0.y);
	v[3] = point0.y < point1.y ? 1 : -1;
	v[4] = (v[0] > v[2] ? v[0] : -v[2]) / 2;
	while (1)
	{
		draw_pixel(point0.y, point0.x, point0.color, pixels);
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
** Draws a rectangle.
*/

void			draw_rectangle(t_point point0, t_point point1, int *pixels)
{
	int		y_start;

	y_start = point0.y;
	while (y_start <= point1.y)
	{
		draw_line(new_point(point0.x, y_start, 0, 0x5856d6),
				new_point(point1.x, y_start, 0, 0x5856d6), pixels);
		y_start++;
	}
}
