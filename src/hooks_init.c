/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hooks_init.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 09:16:08 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/07 10:35:04 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"
#include <unistd.h>

void	set_hooks(t_global *g)
{
	mlx_do_key_autorepeaton(g->mlx);
	mlx_hook(g->window, 2, 0, key_press_hook, g);
	mlx_hook(g->window, 3, 0, key_release_hook, g);
	mlx_hook(g->window, 4, 0, mouse_press_hook, g);
	mlx_hook(g->window, 5, 0, mouse_release_hook, g);
	mlx_hook(g->window, 6, 0, motion_hook, g);
	mlx_hook(g->window, 17, 0, exit_hook, g);
}
