/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw_map.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 09:42:45 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/13 22:11:37 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

/*
** Function:	dotheycross
** ------------------------------
**	Checks if two segments intersect.
**
**	start1: start point of the first segment.
**	end1: end point of the first segment.
**	start2: start point of the second segment.
**	end2: end point of the second segment.
**
**	Returns: 1 if the segments intersect, 0 if not.
*/

static int		dotheycross(t_3dpoint start1, t_3dpoint end1,
					t_2dpoint start2, t_2dpoint end2)
{
	float	denom;
	float	numer;
	float	r;
	float	numer2;
	float	s;

	denom = ((end1.x - start1.x) * (end2.y - start2.y)) -
		((end1.y - start1.y) * (end2.x - start2.x));
	if (denom == 0)
		return (0);
	numer = ((start1.y - start2.y) * (end2.x - start2.x)) -
		((start1.x - start2.x) * (end2.y - start2.y));
	r = numer / denom;
	numer2 = ((start1.y - start2.y) * (end1.x - start1.x)) -
		((start1.x - start2.x) * (end1.y - start1.y));
	s = numer2 / denom;
	if ((r < 0 || r > 1) || (s < 0 || s > 1))
		return (0);
	return (1);
}

/*
** Function:	line_crosses_image
** -------------------------------
**	Checks if the line crosses the image.
**
**	pointa: the first point.
**	pointb: the second point.
**
**	Returns: 1 if the line crosses the image, 0 if not.
**
** 1) if the two points are in the window: return 1
** 2) if the two points are outside the window in the same side: return 0
** 3) if the two points intersect with a border: return 1
** 4) return 0
*/

static int		line_crosses_image(t_3dpoint *pta, t_3dpoint *ptb)
{
	if ((pta->y < W_HEIGHT && pta->y > 0 && pta->x < W_WIDTH && pta->x > 0) ||
		(ptb->y < W_HEIGHT && ptb->y > 0 && ptb->x < W_WIDTH && ptb->x > 0))
		return (1);
	if ((pta->x < 0 && ptb->x < 0) || (pta->x > W_WIDTH && ptb->x > W_WIDTH) ||
		(pta->y < 0 && ptb->y < 0) || (pta->y > W_HEIGHT && ptb->y > W_HEIGHT))
		return (0);
	if (dotheycross(*pta, *ptb, new_2dp_nc(0, 0), new_2dp_nc(0, W_HEIGHT)))
		return (1);
	else if (dotheycross(*pta, *ptb, new_2dp_nc(W_WIDTH, 0),
				new_2dp_nc(W_WIDTH, W_HEIGHT)))
		return (1);
	else if (dotheycross(*pta, *ptb, new_2dp_nc(0, 0), new_2dp_nc(W_WIDTH, 0)))
		return (1);
	else if (dotheycross(*pta, *ptb, new_2dp_nc(0, W_HEIGHT),
				new_2dp_nc(W_WIDTH, W_HEIGHT)))
		return (1);
	return (0);
}

/*
** Function:	draw_horizontal_lines
** ----------------------------------
**	Draws the horizontal lines between all the points.
**
**	pixels: our array of pixels.
**	points: our array of points.
**	map: our map.
*/

static void		draw_horizontal_lines(int *pixels, t_3dpoint *points,
		t_map *map)
{
	int			i;
	int			j;
	t_3dpoint	pointa;
	t_3dpoint	pointb;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width - 1)
		{
			pointa = points[i * map->width + j];
			pointb = points[i * map->width + j + 1];
			if (line_crosses_image(&pointa, &pointb))
				draw_line(pointa, pointb, pixels);
		}
	}
}

/*
** Function:	draw_vertical_lines
** --------------------------------
**	Draws the vertical lines between all the points.
**
**	pixels: our array of pixels.
**	points: our array of points.
**	map: our map.
*/

static void		draw_vertical_lines(int *pixels, t_3dpoint *points, t_map *map)
{
	int			i;
	int			j;
	t_3dpoint	pointa;
	t_3dpoint	pointb;

	i = -1;
	while (++i < map->height - 1)
	{
		j = -1;
		while (++j < map->width)
		{
			pointa = points[i * map->width + j];
			pointb = points[(i + 1) * map->width + j];
			if (line_crosses_image(&pointa, &pointb))
				draw_line(pointa, pointb, pixels);
		}
	}
}

/*
** Function:	draw_map
** ---------------------
**	Draws the lines between all the points.
**
**	pixels: our array of pixels.
**	points: our array of points.
**	map: our map.
*/

void			draw_map(int *pixels, t_3dpoint *points, t_map *map)
{
	draw_horizontal_lines(pixels, points, map);
	draw_vertical_lines(pixels, points, map);
}
