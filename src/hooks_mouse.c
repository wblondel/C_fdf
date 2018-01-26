/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hooks_mouse.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/20 16:31:34 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/26 19:48:05 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_press_hook(int keycode, int x, int y, t_global *g)
{
	if (x > 0 && y > 0 && x < W_WIDTH && y < W_HEIGHT)
	{
		click_toggle(&g->click, keycode, 1);
		if (g->click.zoom)
		{
			cam_set_scale(&g->cam, g->cam.scale + 1);
			click_toggle(&g->click, keycode, 0);
		}
		if (g->click.unzoom)
		{
			cam_set_scale(&g->cam, g->cam.scale - 1);
			click_toggle(&g->click, keycode, 0);
		}
	}
	return (0);
}

int		mouse_release_hook(int keycode, int x, int y, t_global *g)
{
	(void)x;
	(void)y;
	click_toggle(&g->click, keycode, 0);
	return (0);
}

int		motion_hook(int x, int y, t_global *g)
{
	g->mouse.x = x;
	g->mouse.y = y;
	return (0);
}
