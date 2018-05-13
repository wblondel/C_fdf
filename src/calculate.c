/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   calculate.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 13:25:33 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/13 18:57:15 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

/*
** Function:	to_isometric_2d
** ----------------------------
**	Converts a 3D point to a 2D point in an isometric projection.
**
**	point: the point to convert
*/

static void		to_isometric_2d(t_3dpoint *point)
{
	int		x;
	int		y;
	int		z;

	x = point->x;
	y = point->y;
	z = point->z;
	point->x = ceil(x * cos(DEGTORAD(30.0)) + y * cos(DEGTORAD(30.0 + 120.0))
									+ z * cos(DEGTORAD(30.0 - 120.0)));
	point->y = ceil(x * sin(DEGTORAD(30.0)) + y * sin(DEGTORAD(30.0 + 120.0))
									+ z * sin(DEGTORAD(30.0 - 120.0)));
}

/*
** Function:	alt2color
** ----------------------
**	Returns a color based on a point altitude.
**
**	alt: the point altitude.
**	min_alt: the map's minimum altitude.
**	max_alt: the map's maximum altitude.
**
**	Returns: a color as an int (RGB - hex).
*/

static int		alt2color(const int alt, const int min_alt, const int max_alt)
{
	int		color;

	(void)alt;
	(void)min_alt;
	(void)max_alt;
	color = 0x6379FF;
	return (color);
}

/*
** Function:	calc_colors
** ------------------------
**	Fill the color property of all points of the map.
**
**	map: our map struct.
**	min_height: the min altitude of the map.
**	max_height: the max altitude of the map.
*/

static void		calc_colors(t_map *map)
{
	int			i;
	int			j;
	t_3dpoint	*point;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			point = &map->points[i * map->width + j];
			point->color = alt2color(point->z, map->alt_min, map->alt_max);
		}
	}
}

/*
** Function:	calculate_points
** -----------------------------
**	Calculates the coordinates of each point, based on the given scale
**	and the given margins, and converts them into isometric 2D.
**
**	map: our map struct
**	cam: our cam struct
*/

void			calculate_points(t_map *map, t_cam *cam)
{
	int			i;
	int			j;
	t_3dpoint	*point;

	if (!map->points)
		map->points = ft_memalloc(map->width * map->height * sizeof(t_3dpoint));
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			point = &map->points[i * map->width + j];
			point->x = j * cam->scale + cam->shiftx + cam->shifty + W_WIDTH / 2;
			point->y = i * cam->scale + cam->shifty - cam->shiftx;
			point->z = map->file[i][j] * cam->scale * (cam->alt_coeff / 30);
			to_isometric_2d(point);
		}
	}
	calc_colors(map);
}
