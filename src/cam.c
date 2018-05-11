/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cam.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 20:58:06 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/11 22:12:59 by wblondel    ###    #+. /#+    ###.fr     */
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
	cam->margin_x = x;
	cam->margin_y = y;
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

void	cam_set_height_multiplier(t_cam *cam, int height_multiplier)
{
	cam->height_multiplier = height_multiplier;
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
	cam->margin_x = 0;
	cam->margin_y = 0;
	cam->scale = 50;
	cam->height_multiplier = 1;
}
