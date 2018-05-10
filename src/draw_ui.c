/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw_ui.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 20:37:40 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/10 18:26:30 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

/*
** Function:	draw_ui_1
** ----------------------
**		Draws the UI: Part One
**		- Height multiplier
**		- Scale
**		- Mouse coordinates
**
**		g: our global structure.
*/

static void		draw_ui_1(t_global *g)
{
	char	*height_mult;
	char	*scale;
	char	*mousex;
	char	*mousey;

	height_mult = ft_itoa(g->cam.height_multiplier);
	scale = ft_itoa(g->cam.scale);
	mousex = ft_itoa(g->mouse.x);
	mousey = ft_itoa(g->mouse.y);
	mlx_string_put(g->mlx, g->window, 10, W_HEIGHT - 50, 0xFFFFFF,
					"Height mult.:");
	mlx_string_put(g->mlx, g->window, 160, W_HEIGHT - 50, 0xFFFFFF,
					height_mult);
	mlx_string_put(g->mlx, g->window, 10, W_HEIGHT - 30, 0xFFFFFF,
					"Scale:");
	mlx_string_put(g->mlx, g->window, 80, W_HEIGHT - 30, 0xFFFFFF,
					scale);
	mlx_string_put(g->mlx, g->window, W_WIDTH - 120, W_HEIGHT - 30, 0xFFFFFF,
					mousex);
	mlx_string_put(g->mlx, g->window, W_WIDTH - 60, W_HEIGHT - 30, 0xFFFFFF,
					mousey);
	free(height_mult);
	free(scale);
	free(mousex);
	free(mousey);
}

/*
** Function:	draw_ui_2
** ----------------------
**		Draws the UI: Part Two
**		- Margins
**		- Timer for mlx_create_image()
**
**		g: our global structure.
*/

static void		draw_ui_2(t_global *g)
{
	char	*cam_margin_x;
	char	*cam_margin_y;
	char	*timer_mlx_create_image;

	cam_margin_x = ft_itoa(g->cam.margin_x);
	cam_margin_y = ft_itoa(g->cam.margin_y);
	timer_mlx_create_image = ft_itoa(g->ts_mlx_create_image_end -
								g->ts_mlx_create_image_start);
	mlx_string_put(g->mlx, g->window, 120, W_HEIGHT - 30, 0xFFFFFF,
					"Margin X:");
	mlx_string_put(g->mlx, g->window, 220, W_HEIGHT - 30, 0xFFFFFF,
					cam_margin_x);
	mlx_string_put(g->mlx, g->window, 280, W_HEIGHT - 30, 0xFFFFFF,
					"Margin Y:");
	mlx_string_put(g->mlx, g->window, 380, W_HEIGHT - 30, 0xFFFFFF,
					cam_margin_y);
	mlx_string_put(g->mlx, g->window, W_WIDTH - 320, 0, 0xFFFFFF,
					"mlx_create_image:");
	mlx_string_put(g->mlx, g->window, W_WIDTH - 50, 0, 0xFFFFFF,
					timer_mlx_create_image);
	free(cam_margin_x);
	free(cam_margin_y);
	free(timer_mlx_create_image);
}

/*
** Function:	draw_ui_3
** ----------------------
**		Draws the UI: Part Three
**		- Timer for calculate_points()
**		- Timer for draw_map()
**		- Timer for mlx_put_image_to_window()
**
**		g: our global structure.
*/

static void		draw_ui_3(t_global *g)
{
	char	*timer_calculate_points;
	char	*timer_draw_map;
	char	*timer_mlx_put_image_to_window;

	timer_calculate_points = ft_itoa(g->ts_calculate_points_end -
								g->ts_calculate_points_start);
	timer_draw_map = ft_itoa(g->ts_draw_map_end - g->ts_draw_map_start);
	timer_mlx_put_image_to_window = ft_itoa(g->ts_mlx_put_image_to_window_end -
			g->ts_mlx_put_image_to_window_start);
	mlx_string_put(g->mlx, g->window, W_WIDTH - 320, 20, 0xFFFFFF,
					"calculate_points:");
	mlx_string_put(g->mlx, g->window, W_WIDTH - 50, 20, 0xFFFFFF,
					timer_calculate_points);
	mlx_string_put(g->mlx, g->window, W_WIDTH - 320, 40, 0xFFFFFF,
					"draw_map:");
	mlx_string_put(g->mlx, g->window, W_WIDTH - 50, 40, 0xFFFFFF,
					timer_draw_map);
	mlx_string_put(g->mlx, g->window, W_WIDTH - 320, 60, 0xFFFFFF,
					"mlx_put_image_to_window:");
	mlx_string_put(g->mlx, g->window, W_WIDTH - 50, 60, 0xFFFFFF,
					timer_mlx_put_image_to_window);
	free(timer_calculate_points);
	free(timer_draw_map);
	free(timer_mlx_put_image_to_window);
}

/*
** Function:	draw_ui
** --------------------
**		Draws the entire UI.
**
**		g: our global structure.
*/

void			draw_ui(t_global *g)
{
	draw_ui_1(g);
	draw_ui_2(g);
	draw_ui_3(g);
	mlx_string_put(g->mlx, g->window, W_WIDTH - (W_WIDTH / 2) - 20,
			W_HEIGHT - 30, 0xFFFFFF, "Press TAB for HELP");
}
