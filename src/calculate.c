/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   calculate.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 13:25:33 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/10 16:16:43 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

/*
** Function:	to_isometric_2d
** ----------------------------
**		Converts a 3D point to a 2D point in an isometric projection.
**
**		point: the point to convert
*/

static void		to_isometric_2d(t_point *point)
{
	int		x;
	int		y;
	int		z;

	x = point->x;
	y = point->y;
	z = point->z;
	point->x = x * cos(DEGTORAD(30)) + y * cos(DEGTORAD(30 + 120))
									+ z * cos(DEGTORAD(30 - 120));
	point->y = x * sin(DEGTORAD(30)) + y * sin(DEGTORAD(30 + 120))
									+ z * sin(DEGTORAD(30 - 120));
}

/*
** Function:	calculate_points
** -----------------------------
**		Calculates the coordinates of each point, based on the given scale
**		and the given margins, and converts them into isometric 2D.
**
**		map: our map struct
**		cam: our cam struct
*/

void			calculate_points(t_map *map, t_cam *cam)
{
	int		i;
	int		j;

	if (!map->points)
		map->points = (t_point *)ft_memalloc(map->width * map->height *
															sizeof(t_point));
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->points[i * map->width + j].x = j * cam->scale +
								cam->margin_x + cam->margin_y + W_WIDTH / 2;
			map->points[i * map->width + j].y = i * cam->scale +
								cam->margin_y - cam->margin_x;
			map->points[i * map->width + j].z = map->file[i][j] * cam->scale *
								((float)cam->height_multiplier / 30);
			map->points[i * map->width + j].color = 0x6379FF;
			to_isometric_2d(&map->points[i * map->width + j]);
			j++;
		}
		i++;
	}
}
