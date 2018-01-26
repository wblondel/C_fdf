/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 09:36:18 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/26 20:40:39 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

/*
** First you need to call mlx_init and store its return value.
** Now do the same with mlx_new_window
** One more time with mlx_new_image
*/

t_global	*init_global(void)
{
	t_global	*g;

	if ((g = (t_global *)ft_memalloc(sizeof(t_global))) == NULL)
		error("error: malloc() for g failed");
	if ((g->mlx = mlx_init()) == NULL)
		error("error: mlx_init() failed");
	if ((g->window = mlx_new_window(g->mlx, W_WIDTH, W_HEIGHT,
						"FdF Reader")) == NULL)
		error("error: mlx_new_window() failed");
	mlx_create_image(g->mlx, &g->image);

	g->cam.margin_x = 0;
	g->cam.margin_y = 0;
	g->cam.scale = 50;

	g->map.width = 0;
	g->map.height = 0;
	g->map.depth_min = 0;
	g->map.depth_max = 0;
	keys_init(&g->key);
	clicks_init(&g->click);
	return (g);
}
