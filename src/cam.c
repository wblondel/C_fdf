/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cam.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 20:58:06 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 21:56:24 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	cam_set_margin(t_cam *cam, int x, int y)
{
	cam->margin_x = x;
	cam->margin_y = y;
}

void	cam_set_scale(t_cam *cam, int scale)
{
	if (scale < 1)
		scale = 1;
	if (scale > 255)
		scale = 255;
	cam->scale = scale;
}
