/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   debug.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/22 10:22:40 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/22 11:03:04 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void 				print_map(t_map *map)
{
	int i;
	int j;

	i = 0;
	ft_putstr("Height: ");
	ft_putnbr(map->height);
	ft_putstr("; Width: ");
	ft_putnbr(map->width);
	ft_putchar('\n');

	while (i < map->height)
	{
		j = 0;
		while (j <  map->width)
		{
			ft_putnbr(map->file[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
