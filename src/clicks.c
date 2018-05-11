/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   clicks.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/09 11:45:24 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/11 22:13:26 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

/*
** Function:	clicks_init
** ------------------------
**	Initializes all the mouse-related toggle switches to 0.
**
**	click: structure containing all the mouse-related toggle switches.
*/

void	clicks_init(t_clicks *click)
{
	click->left = 0;
	click->right = 0;
	click->middle = 0;
	click->zoom = 0;
	click->unzoom = 0;
}

/*
** Function:	click_toggle
** -------------------------
**	Sets a mouse-related toggle switch.
**
**	click: structure containing all the mouse-related toggle switches.
**	keycode: keycode of the pressed button.
**	toggle: value to set the toggle to (usually 0 or 1).
*/

void	click_toggle(t_clicks *click, int keycode, int toggle)
{
	keycode == CLICK_LEFT ? click->left = toggle : 0;
	keycode == CLICK_RIGHT ? click->right = toggle : 0;
	keycode == CLICK_MIDDLE ? click->middle = toggle : 0;
	keycode == ZOOM ? click->zoom = toggle : 0;
	keycode == UNZOOM ? click->unzoom = toggle : 0;
}
