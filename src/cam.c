/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cam.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 20:58:06 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/09 15:02:17 by wblondel    ###    #+. /#+    ###.fr     */
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

void	cam_set_height_multiplier(t_cam *cam, int height_multiplier)
{
	cam->height_multiplier = height_multiplier;
	printf("Height multiplier: %d\n", cam->height_multiplier);
}

void	cam_reset(t_cam *cam)
{
	cam->margin_x = 0;
	cam->margin_y = 0;
	cam->scale = 50;
	cam->height_multiplier = 1;
}
