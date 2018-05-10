/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw_map.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 09:42:45 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/10 18:14:07 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

/*
** Function:	draw_horizontal_lines
** ----------------------------------
**		Draws the horizontal lines between all the points.
**
**		pixels: our array of pixels.
**		points: our array of points.
**		map: our map.
*/

static void		draw_horizontal_lines(int *pixels, t_point *points, t_map *map)
{
	int		i;
	int		j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width - 1)
		{
			if ((points[i * map->width + j + 1].y < W_HEIGHT &&
				points[i * map->width + j + 1].y > 0 &&
				points[i * map->width + j + 1].x < W_WIDTH &&
				points[i * map->width + j + 1].x > 0) ||
				(points[i * map->width + j].y < W_HEIGHT &&
				points[i * map->width + j].y > 0 &&
				points[i * map->width + j].x < W_WIDTH &&
				points[i * map->width + j].x > 0))
			{
				draw_line(points[i * map->width + j],
						points[i * map->width + j + 1], pixels);
			}
		}
	}
}

/*
** Function:	draw_vertical_lines
** --------------------------------
**		Draws the vertical lines between all the points.
**
**		pixels: our array of pixels.
**		points: our array of points.
**		map: our map.
*/

static void		draw_vertical_lines(int *pixels, t_point *points, t_map *map)
{
	int		i;
	int		j;

	i = -1;
	while (++i < map->height - 1)
	{
		j = -1;
		while (++j < map->width)
		{
			if ((points[(i + 1) * map->width + j].y < W_HEIGHT &&
				points[(i + 1) * map->width + j].y > 0 &&
				points[(i + 1) * map->width + j].x < W_WIDTH &&
				points[(i + 1) * map->width + j].x > 0) ||
				(points[i * map->width + j].y < W_HEIGHT &&
				points[i * map->width + j].y > 0 &&
				points[i * map->width + j].x < W_WIDTH &&
				points[i * map->width + j].x > 0))
			{
				draw_line(points[i * map->width + j],
						points[(i + 1) * map->width + j], pixels);
			}
		}
	}
}

/*
** Function:	draw_map
** ---------------------
**		Draws the lines between all the points.
**
**		pixels: our array of pixels.
**		points: our array of points.
**		map: our map.
*/

void			draw_map(int *pixels, t_point *points, t_map *map)
{
	draw_horizontal_lines(pixels, points, map);
	draw_vertical_lines(pixels, points, map);
}
