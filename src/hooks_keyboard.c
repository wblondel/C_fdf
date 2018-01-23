/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hooks_keyboard.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/20 16:31:12 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 19:58:13 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		key_press_hook(int keycode, t_view *v)
{
	key_toggle(&v->key, keycode, 1);
	if (v->key.esc)
	{
		mlx_destroy_window(v->mlx, v->window);
		exit(EXIT_SUCCESS);
	}
	if (v->key.d)
		v->map.margin_x -= 1;
	if (v->key.a)
		v->map.margin_x += 1;
	if (v->key.w)
		v->map.margin_y += 1;
	if (v->key.s)
		v->map.margin_y -= 1;

	if (v->key.f)
		print_map(&v->map);
	if (v->key.p)
		print_points(&v->map);
	return (0);
}

int		key_release_hook(int keycode, t_view *v)
{
	key_toggle(&v->key, keycode, 0);
	return (0);
}
