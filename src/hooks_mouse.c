/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hooks_mouse.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/20 16:31:34 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/20 16:33:18 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_press_hook(int keycode, int x, int y, t_view *v)
{
	if (x > 0 && y > 0 && x < W_WIDTH && y < W_HEIGHT)
	{
		click_toggle(&v->click, keycode, 1);
		v->mouse_x = x;
		v->mouse_y = y;
	}
	return (0);
}

int		mouse_release_hook(int keycode, int x, int y, t_view *v)
{
	click_toggle(&v->click, keycode, 0);
	v->mouse_x = x;
	v->mouse_y = y;
	return (0);
}
