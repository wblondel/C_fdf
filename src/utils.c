/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/09 14:19:47 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/11 18:44:22 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

/*
** Function:	new_point
** ----------------------
**		Returns a new Point structure.
**
**		x: X coordinate of the point to create.
**		y: Y coordinate of the point to create.
**		z: Z coordinate of the point to create.
**		color: the color of pixel.
**
**		Returns a new Point object
*/

t_3dpoint	new_3dpoint(int x, int y, int z, int color)
{
	t_3dpoint point;

	point.x = x;
	point.y = y;
	point.z = z;
	point.color = color;
	return (point);
}

t_2dpoint	new_2dpoint(int x, int y, int color)
{
	t_2dpoint point;

	point.x = x;
	point.y = y;
	point.color = color;
	return (point);
}

t_2dpoint	new_2dp_nc(int x, int y)
{
	return (new_2dpoint(x, y, WHITE));
}

/*
** Function:	error
** ------------------
**		Prints an error message and exits with error code 1.
*/

void		error(char *msg)
{
	ft_putendl(msg);
	exit(EXIT_FAILURE);
}
