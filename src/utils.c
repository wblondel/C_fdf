/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/09 14:19:47 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/09 15:07:27 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

/*
** Returns a new Point object
*/

t_point		new_point(int x, int y, int z, int color)
{
	t_point point;

	point.x = x;
	point.y = y;
	point.z = z;
	point.color = color;
	return (point);
}

/*
** Prints an error message and exits with error code 1.
*/

void		error(char *msg)
{
	ft_putendl(msg);
	exit(EXIT_FAILURE);
}
