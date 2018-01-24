/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hooks_mouse.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/20 16:31:34 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 12:39:27 by wblondel    ###    #+. /#+    ###.fr     */
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
			g->cam.scale = MIN(255, g->cam.scale + 1);
			click_toggle(&g->click, keycode, 0);
		}
		if (g->click.unzoom)
		{
			g->cam.scale = MAX(1, g->cam.scale - 1);
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
