/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hooks_keyboard.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/20 16:31:12 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/22 10:27:40 by wblondel    ###    #+. /#+    ###.fr     */
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
		ft_putstr("Moving map to the left.\n");
	if (v->key.a)
		ft_putstr("Moving map to the right.\n");
	if (v->key.w)
		ft_putstr("Moving map down.\n");
	if (v->key.s)
		ft_putstr("Moving map up.\n");
	if (v->key.p)
		print_map(&v->map);
	return (0);
}

int		key_release_hook(int keycode, t_view *v)
{
	key_toggle(&v->key, keycode, 0);
	return (0);
}
