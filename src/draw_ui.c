/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw_ui.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 20:37:40 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/11 19:37:53 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

/*
** Function:	put_string
** -----------------------
**		Writes a string on the image.
*/

static void		mlx_sp(t_global *g, t_2dpoint p, int color, char *string)
{
	mlx_string_put(g->mlx, g->window, p.x, p.y, color, string);
}

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
	mlx_sp(g, new_2dp_nc(10, W_HEIGHT - 50), WHITE, "Height mult.:");
	mlx_sp(g, new_2dp_nc(160, W_HEIGHT - 50), WHITE, height_mult);
	mlx_sp(g, new_2dp_nc(10, W_HEIGHT - 30), WHITE, "Scale:");
	mlx_sp(g, new_2dp_nc(80, W_HEIGHT - 30), WHITE, scale);
	mlx_sp(g, new_2dp_nc(W_WIDTH - 120, W_HEIGHT - 30), WHITE, mousex);
	mlx_sp(g, new_2dp_nc(W_WIDTH - 60, W_HEIGHT - 30), WHITE, mousey);
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
	char	*t_mlx_create_image;

	cam_margin_x = ft_itoa(g->cam.margin_x);
	cam_margin_y = ft_itoa(g->cam.margin_y);
	t_mlx_create_image = ft_itoa(g->ts_mlx_create_image);
	mlx_sp(g, new_2dp_nc(120, W_HEIGHT - 30), WHITE, "Margin X:");
	mlx_sp(g, new_2dp_nc(220, W_HEIGHT - 30), WHITE, cam_margin_x);
	mlx_sp(g, new_2dp_nc(280, W_HEIGHT - 30), WHITE, "Margin Y:");
	mlx_sp(g, new_2dp_nc(380, W_HEIGHT - 30), WHITE, cam_margin_y);
	mlx_sp(g, new_2dp_nc(W_WIDTH - 320, 0), WHITE, "mlx_create_image:");
	mlx_sp(g, new_2dp_nc(W_WIDTH - 50, 0), WHITE, t_mlx_create_image);
	free(cam_margin_x);
	free(cam_margin_y);
	free(t_mlx_create_image);
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
	char	*t_calc_pts;
	char	*t_draw_map;
	char	*t_mlx_put_image_to_window;
	char	*t_fps;

	t_calc_pts = ft_itoa(g->ts_calculate_points);
	t_draw_map = ft_itoa(g->ts_draw_map);
	t_mlx_put_image_to_window = ft_itoa(g->ts_mlx_put_image_to_window);
	t_fps =  ft_itoa(1000 / (g->ts_calculate_points + g->ts_draw_map +
			g->ts_mlx_put_image_to_window));
	mlx_sp(g, new_2dp_nc(W_WIDTH - 320, 20), WHITE, "calculate_points:");
	mlx_sp(g, new_2dp_nc(W_WIDTH - 50, 20), WHITE, t_calc_pts);
	mlx_sp(g, new_2dp_nc(W_WIDTH - 320, 40), WHITE, "draw_map:");
	mlx_sp(g, new_2dp_nc(W_WIDTH - 50, 40), WHITE, t_draw_map);
	mlx_sp(g, new_2dp_nc(W_WIDTH - 320, 60), WHITE, "mlx_put_image_to_window:");
	mlx_sp(g, new_2dp_nc(W_WIDTH - 50, 60), WHITE, t_mlx_put_image_to_window);
	mlx_sp(g, new_2dp_nc(W_WIDTH - 320, 80), WHITE, "fps:");
	mlx_sp(g, new_2dp_nc(W_WIDTH - 50, 80), WHITE, t_fps);
	free(t_calc_pts);
	free(t_draw_map);
	free(t_mlx_put_image_to_window);
	free(t_fps);
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
	mlx_sp(g, new_2dp_nc(W_WIDTH - (W_WIDTH / 2) - 20, W_HEIGHT - 30), WHITE,
			"Press TAB for HELP");
}
