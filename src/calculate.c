/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   calculate.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 13:25:33 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 13:26:19 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void 			calculate_points(t_map *map, t_cam *cam)
{
	int		i;
	int		j;

	map->points = (t_point *)ft_memalloc(map->width * map->height * sizeof(t_point));

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->points[i * map->width + j].x = j * cam->scale + cam->margin_x;
			map->points[i * map->width + j].y = i * cam->scale + cam->margin_y;
			map->points[i * map->width + j].z = map->file[i][j];
			j++;
		}
		i++;
	}
}
