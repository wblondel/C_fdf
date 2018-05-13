/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 09:36:18 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/13 18:01:56 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

/*
** Function:	init_values
** ------------------------
**	Initializes the parameters of the camera and the map.
**
**	g: our global structure.
*/

static void	init_values(t_global *g)
{
	g->cam.shiftx = 0;
	g->cam.shifty = 0;
	g->cam.scale = 50;
	g->cam.alt_coeff = 1;
	g->map.width = -1;
	g->map.height = 0;
	g->map.alt_min = 2147483647;
	g->map.alt_max = -2147483648;
}

/*
** Function:	init_global
** ------------------------
**	Creates a new global structure.
**
**	Returns: a new global structure.
**
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
	init_values(g);
	keys_init(&g->key);
	clicks_init(&g->click);
	return (g);
}
