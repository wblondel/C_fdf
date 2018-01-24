/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   calculate.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 13:25:33 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 23:38:24 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

/*
** α = 30 degres
** cos(sqrt(3)) = 30 degres
** sin(sqrt(1)) = 30 degres
*/

void			to_isometric_2d(t_point *point, t_cam *cam)
{
	int		x;
	int		y;
	int		z;

	x = point->x;
	y = point->y;
	z = point->z;

	point->x = x * cos(DEGTORAD(cam->angle_x_1)) + y * cos(DEGTORAD(cam->angle_x_2)) +
				z * cos(DEGTORAD(cam->angle_x_3));
	point->y = x * sin(DEGTORAD(cam->angle_y_1)) + y * sin(DEGTORAD(cam->angle_y_2)) +
				z * sin(DEGTORAD(cam->angle_y_3));
	/*point->x = x * cos(DEGTORAD(30)) + y * cos(DEGTORAD(30 + 120)) +
				z * cos(DEGTORAD(30 - 120));
	point->y = x * sin(DEGTORAD(30)) + y * sin(DEGTORAD(30 + 120)) +
				z * sin(DEGTORAD(30 - 120));*/
}

void			calculate_points(t_map *map, t_cam *cam)
{
	int		i;
	int		j;

	map->points = (t_point *)ft_memalloc(map->width * map->height *
					sizeof(t_point));
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->points[i * map->width + j].x = j * cam->scale + cam->margin_x;
			map->points[i * map->width + j].y = i * cam->scale + cam->margin_y;
			map->points[i * map->width + j].z = map->file[i][j] * cam->scale;
			to_isometric_2d(&map->points[i * map->width + j], cam);
			j++;
		}
		i++;
	}
}
