/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hooks_keyboard.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/20 16:31:12 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 23:26:11 by wblondel    ###    #+. /#+    ###.fr     */
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

	if (g->key.one)
		g->cam.angle_x_1 += 1;
	if (g->key.two)
		g->cam.angle_x_1 -= 1;
	if (g->key.three)
		g->cam.angle_x_2 += 1;
	if (g->key.four)
		g->cam.angle_x_2 -= 1;
	if (g->key.five)
		g->cam.angle_x_3 += 1;
	if (g->key.six)
		g->cam.angle_x_3 -= 1;
	if (g->key.seven)
		g->cam.angle_x_4 += 1;
	if (g->key.eight)
		g->cam.angle_x_4 -= 1;
	if (g->key.nine)
		g->cam.angle_x_5 += 1;
	if (g->key.zero)
		g->cam.angle_x_5 -= 1;

		if (g->key.e)
			g->cam.angle_y_1 += 1;
		if (g->key.r)
			g->cam.angle_y_1 -= 1;
		if (g->key.t)
			g->cam.angle_y_2 += 1;
		if (g->key.y)
			g->cam.angle_y_2 -= 1;
		if (g->key.u)
			g->cam.angle_y_3 += 1;
		if (g->key.i)
			g->cam.angle_y_3 -= 1;
		if (g->key.o)
			g->cam.angle_y_4 += 1;
		if (g->key.p)
			g->cam.angle_y_4 -= 1;
		if (g->key.brace_l)
			g->cam.angle_y_5 += 1;
		if (g->key.brace_r)
			g->cam.angle_y_5 -= 1;

	/*if (g->key.f)
		print_map(&g->map);
	if (g->key.p)
		print_points(&g->map);*/
	return (0);
}

int		key_release_hook(int keycode, t_global *g)
{
	key_toggle(&g->key, keycode, 0);
	return (0);
}
