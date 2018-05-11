/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   debug.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/22 10:22:40 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/11 22:14:04 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

/*
** Function:	print_map
** ----------------------
**	Prints the map as read from the file.
**
**	map: the map.
*/

void	print_map(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	ft_putstr("Height: ");
	ft_putnbr(map->height);
	ft_putstr("; Width: ");
	ft_putnbr(map->width);
	ft_putchar('\n');
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			ft_putnbr(map->file[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}

/*
** Function:	print_points
** -------------------------
**	Prints the points' coordinates.
**
**	map: the map.
*/

void	print_points(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			ft_putnbr(map->points[i * map->width + j].x);
			ft_putstr(", ");
			ft_putnbr(map->points[i * map->width + j].y);
			ft_putstr(", ");
			ft_putnbr(map->points[i * map->width + j].z);
			ft_putstr(" | ");
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}
