/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hooks_others.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/20 16:32:52 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/11 19:32:57 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

/*
** Function:	get_time
** ---------------------
**		Returns the current timestamp.
*/

static int64_t		get_time(void)
{
	struct timespec t;

	clock_gettime(CLOCK_REALTIME, &t);
	return (t.tv_sec * INT64_C(1000) + t.tv_nsec / 1000000);
}

/*
** Function:	loop_hook
** ----------------------
**		Perform actions until the program is exited.
**
**		g: our global structure.
**
**		Returns: 0 (never reached).
**
**		It looks like the minilibx limits the FPS to 60. Good.
*/

int					loop_hook(t_global *g)
{
	g->ts_mlx_create_image = get_time();
	mlx_create_image(g->mlx, &g->image);
	g->ts_mlx_create_image = get_time() - g->ts_mlx_create_image;
	if (g->key.tab)
		draw_ui_help(g);
	g->ts_calculate_points = get_time();
	calculate_points(&g->map, &g->cam);
	g->ts_calculate_points = get_time() - g->ts_calculate_points;
	g->ts_draw_map = get_time();
	draw_map(g->image.pixels, g->map.points, &g->map);
	g->ts_draw_map = get_time() - g->ts_draw_map;
	g->ts_mlx_put_image_to_window = get_time();
	mlx_put_image_to_window(g->mlx, g->window, g->image.ptr, 0, 0);
	g->ts_mlx_put_image_to_window = get_time() - g->ts_mlx_put_image_to_window;
	draw_ui(g);
	mlx_destroy_image(g->mlx, g->image.ptr);
	return (0);
}

/*
** Function:	exit_hook
** ----------------------
**		Exits the program.
**
**		keycode: keycode of the pressed key.
**		g: our global structure.
**
**		Returns: 0.
**
** You are correct, no harm is done and it's faster to just exit
** There are various reasons for this:
** All desktop and server environments simply release the entire memory space
** on exit(). They are unaware of program-internal data structures such as
** heaps. Almost all free() implementations do not ever return memory to the
** operating system anyway. More importantly, it's a waste of time when done
** right before exit(). At exit, memory pages and swap space are simply
** released. By contrast, a series of free() calls will burn CPU time and can
** result in disk paging operations, cache misses, and cache evictions.
*/

int					exit_hook(int keycode, t_global *g)
{
	(void)g;
	(void)keycode;
	exit(EXIT_SUCCESS);
}
