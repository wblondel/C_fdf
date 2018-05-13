/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/09 14:19:47 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/13 22:02:12 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

/*
** Function:	new_3dpoint
** ----------------------
**	Returns a new 3D point structure.
**
**	x: X coordinate of the 3D point to create.
**	y: Y coordinate of the 3D point to create.
**	z: Z coordinate of the 3D point to create.
**	color: the color of pixel.
**
**	Returns: a new 3D point structure.
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

/*
** Function:	new_3dp_nc
** -----------------------
**	Returns a new 3D point structure with the color property set to BLACK.
**
**	x: X coordinate of the 3D point to create.
**	y: Y coordinate of the 3D point to create.
**	z: Z coordinate of the 3D point to create.
**
**	Returns: a new 3D point structure.
*/

t_3dpoint	new_3dp_nc(int x, int y, int z)
{
	return (new_3dpoint(x, y, z, BLACK));
}

/*
** Function:	new_2dpoint
** ------------------------
**	Returns a new 2D point structure.
**
**	x: X coordinate of the 2D point to create.
**	y: Y coordinate of the 2D point to create.
**	color: the color the pixel.
**
**	Returns: a new 2D point structure.
*/

t_2dpoint	new_2dpoint(int x, int y, int color)
{
	t_2dpoint point;

	point.x = x;
	point.y = y;
	point.color = color;
	return (point);
}

/*
** Function:	new_2dp_nc
** -----------------------
**	Returns a new 2D point structure with the color property set to BLACK.
**
**	x: X coordinate of the 2D point to create.
**	y: Y coordinate of the 2D point to create.
**
**	Returns: a new 2D point structure.
*/

t_2dpoint	new_2dp_nc(int x, int y)
{
	return (new_2dpoint(x, y, BLACK));
}

/*
** Function:	error
** ------------------
**	Prints an error message and exits with error code 1.
*/

void		error(char *msg)
{
	ft_putendl(msg);
	exit(EXIT_FAILURE);
}
