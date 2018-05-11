/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/09 14:46:58 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/11 22:14:42 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

/*
** Function:	draw_pixel
** -----------------------
**	Draws a pixel.
**
**	y: the point's Y coordinate.
**	x: the point's X coordinate.
**	color: the point's color (RGB - hexadecimal).
**	pixels: our array of pixels.
**
**	Returns: 0 if the point was drawn,
**			 1 if the coordinates are out of the window.
*/

static int	draw_pixel(int y, int x, int color, int *pixels)
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
** Function:	draw_line
** ----------------------
**	Draws a line between 2 points.
**
**	point0: the point where we start drawing.
**	point1: the point where we stop drawing.
**	pixels: our array of pixels.
**
**	v[0] = dx; v[1] = sx; v[2] = dy
**	v[3] = sy; v[4] = err; v[5] = e2
**	https://rosettacode.org/wiki/Bitmap/Bresenham%27s_line_algorithm#C
*/

void		draw_line(t_3dpoint point0, t_3dpoint point1, int *pixels)
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
** Function:	draw_rectangle
** ---------------------------
**	Draws a rectangle.
**
**	point0: the top-left corner's coordinates.
**	point1: the bottom-right corner's coordinates.
**	pixels: our array of pixels.
*/

void		draw_rectangle(t_3dpoint point0, t_3dpoint point1, int *pixels)
{
	int		y_start;

	y_start = point0.y;
	while (y_start <= point1.y)
	{
		draw_line(new_3dpoint(point0.x, y_start, 0, 0x5856d6),
				new_3dpoint(point1.x, y_start, 0, 0x5856d6), pixels);
		y_start++;
	}
}
