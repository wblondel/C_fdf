/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/09 14:19:47 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/11 15:45:07 by wblondel    ###    #+. /#+    ###.fr     */
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
** Function:	error
** ------------------
**		Prints an error message and exits with error code 1.
**
*/

void		error(char *msg)
{
	ft_putendl(msg);
	exit(EXIT_FAILURE);
}
