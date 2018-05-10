/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hooks_mouse.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/20 16:31:34 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/10 18:48:19 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

/*
** Function:	mouse_press_hook
** -----------------------------
**		Executes an action when a button on the mouse is pressed.
**
**		keycode: keycode of the pressed button.
**		x: the mouse's X coordinate.
**		y: the mouse's Y coordinate.
**		g: our global structure.
**
**		Returns: 0.
*/

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

/*
** Function:	mouse_release_hook
** -------------------------------
**		Executes an action when a button on the mouse is released.
**
**		keycode: keycode of the released button.
**		x: the mouse's X coordinate.
**		y: the mouse's Y coordinate.
**		g: our global structure.
**
**		Returns: 0.
*/

int		mouse_release_hook(int keycode, int x, int y, t_global *g)
{
	(void)x;
	(void)y;
	click_toggle(&g->click, keycode, 0);
	return (0);
}

/*
** Function:	motion_hook
** ------------------------
**		Executes an action when the mouse is moved.
**
**		x: the mouse's X coordinate.
**		y: the mouse's Y coordinate.
**		g: our global structure.
**
**		Returns: 0.
*/

int		motion_hook(int x, int y, t_global *g)
{
	if (g->click.left)
	{
		if (x < 0 || y < 0 || x > W_WIDTH || y > W_HEIGHT)
		{
			click_toggle(&g->click, CLICK_LEFT, 0);
		}
		else
		{
			if (abs(g->mouse.y - y) < 20)
			{
				if (g->mouse.x < x)
					ft_putstr("Rotating anti-clockwise\n");
				else if (g->mouse.x > x)
					ft_putstr("Rotating clockwise\n");
			}
		}
	}
	g->mouse.x = x;
	g->mouse.y = y;
	return (0);
}
