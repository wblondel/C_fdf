/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   render.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 09:42:45 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/22 16:27:58 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"
#include <time.h>
#include <stdlib.h>

#define degreesToRadians(angleDegrees) ((angleDegrees) * M_PI / 180.0)
#define radiansToDegrees(angleRadians) ((angleRadians) * 180.0 / M_PI)

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

static void		draw_line(t_point point0, t_point point1, int *pixels)
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
}

static void 	toIsometric2D(t_point *point)
{
	int isoX;
	int isoY;

	isoX = point->x - point->y;
	isoY = (point->x + point->y) / 2;

	point->x = isoX;
	point->y = isoY;
}

static void 	draw_square(t_point topleft, int size, int *pixels)
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
}


void			render_map(int *pixels)
{
	t_point topleft1 = {150, 0, 0};
	t_point topleft2 = {200, 0, 0};
	t_point topleft3 = {250, 0, 0};
	t_point topleft4 = {150, 50, 0};

	draw_square(topleft1, 50, pixels);
	draw_square(topleft2, 50, pixels);
	draw_square(topleft3, 50, pixels);
	draw_square(topleft4, 50, pixels);

}
