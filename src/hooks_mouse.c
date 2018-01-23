/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hooks_mouse.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/20 16:31:34 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 20:30:35 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_press_hook(int keycode, int x, int y, t_view *v)
{
	if (x > 0 && y > 0 && x < W_WIDTH && y < W_HEIGHT)
	{
		click_toggle(&v->click, keycode, 1);
		if (v->click.zoom)
		{
			v->map.scale = MIN(255, v->map.scale + 1);
			click_toggle(&v->click, keycode, 0);
		}
		if (v->click.unzoom)
		{
			v->map.scale = MAX(1, v->map.scale - 1);
			click_toggle(&v->click, keycode, 0);
		}
	}
	return (0);
}

int		mouse_release_hook(int keycode, int x, int y, t_view *v)
{
	(void)x;
	(void)y;
	click_toggle(&v->click, keycode, 0);
	return (0);
}
