/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cam.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 20:58:06 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/13 18:00:44 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

/*
** Function:	cam_set_margin
** ---------------------------
**	Sets the margins of our camera.
**
**	cam: our camera.
**	x: the margin in the X axis.
**	y: the margin in the Y axis.
*/

void	cam_set_margin(t_cam *cam, int x, int y)
{
	cam->shiftx = x;
	cam->shifty = y;
}

/*
** Function:	cam_set_scale
** --------------------------
**	Sets the scale of our map.
**
**	cam: our camera.
**	scale: the scale to set.
*/

void	cam_set_scale(t_cam *cam, int scale)
{
	if (scale < 1)
		scale = 1;
	if (scale > 255)
		scale = 255;
	cam->scale = scale;
}

/*
** Function:	cam_set_height_multiplier
** --------------------------------------
**	Set the height multiplier of our map.
**
**	cam: our camera.
**	height_multiplier: the height multiplier to set.
*/

void	cam_set_height_multiplier(t_cam *cam, int alt_coeff)
{
	cam->alt_coeff = alt_coeff;
}

/*
** Function:	cam_reset
** ----------------------
**	Resets the margins, the scale and the height multiplier to
**	default values.
**
**	cam: our camera.
*/

void	cam_reset(t_cam *cam)
{
	cam->shiftx = 0;
	cam->shifty = 0;
	cam->scale = 50;
	cam->alt_coeff = 1;
}
