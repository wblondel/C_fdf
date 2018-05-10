/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hooks_keyboard.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/20 16:31:12 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/10 18:46:23 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

/*
** Function:	key_press_hook
** ---------------------------
**		Executes an action when a key on the keyboard is pressed.
**
**		keycode: keycode of the pressed key.
**		g: our global structure.
**
**		Returns: 0.
*/

int		key_press_hook(int keycode, t_global *g)
{
	key_toggle(&g->key, keycode, 1);
	if (g->key.esc)
		exit_hook(keycode, g);
	if (g->key.a)
		cam_set_margin(&g->cam, g->cam.margin_x += 15, g->cam.margin_y);
	if (g->key.w)
		cam_set_margin(&g->cam, g->cam.margin_x, g->cam.margin_y += 15);
	if (g->key.s)
		cam_set_margin(&g->cam, g->cam.margin_x, g->cam.margin_y -= 15);
	if (g->key.d)
		cam_set_margin(&g->cam, g->cam.margin_x -= 15, g->cam.margin_y);
	if (g->key.plus)
		cam_set_height_multiplier(&g->cam, g->cam.height_multiplier + 1);
	if (g->key.minus)
		cam_set_height_multiplier(&g->cam, g->cam.height_multiplier - 1);
	if (g->key.r)
		cam_reset(&g->cam);
	if (g->key.m)
		print_map(&g->map);
	if (g->key.p)
		print_points(&g->map);
	return (0);
}

/*
** Function:	key_release_hook
** -----------------------------
**		Executes an action when a key on the keyboard is released.
**
**		keycode: keycode of the released key.
**		g: our global structure.
**
**		Returns: 0.
*/

int		key_release_hook(int keycode, t_global *g)
{
	key_toggle(&g->key, keycode, 0);
	return (0);
}
