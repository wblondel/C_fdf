/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hooks_keyboard.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/20 16:31:12 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 21:02:58 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		key_press_hook(int keycode, t_global *g)
{
	key_toggle(&g->key, keycode, 1);
	if (g->key.esc)
	{
		mlx_destroy_window(g->mlx, g->window);
		exit(EXIT_SUCCESS);
	}
	if (g->key.d)
		cam_set_margin(&g->cam, g->cam.margin_x -= 15, g->cam.margin_y += 15);
	if (g->key.a)
		cam_set_margin(&g->cam, g->cam.margin_x += 15, g->cam.margin_y -= 15);
	if (g->key.w)
		cam_set_margin(&g->cam, g->cam.margin_x += 15, g->cam.margin_y += 15);
	if (g->key.s)
		cam_set_margin(&g->cam, g->cam.margin_x -= 15, g->cam.margin_y -= 15);
	if (g->key.f)
		print_map(&g->map);
	if (g->key.p)
		print_points(&g->map);
	return (0);
}

int		key_release_hook(int keycode, t_global *g)
{
	key_toggle(&g->key, keycode, 0);
	return (0);
}
