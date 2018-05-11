/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw_ui_help.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/10 18:23:54 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/11 18:47:34 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

/*
** Function:	draw_ui_help
** -------------------------
**		Draws the Help UI.
**
**		g: our global structure.
*/

void	draw_ui_help(t_global *g)
{
	draw_rectangle(new_3dpoint(W_WIDTH / 4, W_HEIGHT / 4, 0, 0x6379FF),
					new_3dpoint(W_WIDTH / 4 * 3, W_HEIGHT / 4 * 3, 0, 0x6379FF),
					g->image.pixels);
}
