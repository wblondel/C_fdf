/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   clicks.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/09 11:45:24 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/09 12:30:49 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <fdf.h>

void 			clicks_init(t_clicks *click)
{
	click->left = 0;
	click->right = 0;
	click->middle = 0;
	click->zoom = 0;
	click->unzoom = 0;
}

void click_toggle(t_clicks *click, int keycode, int toggle)
{
	keycode == CLICK_LEFT ? click->left = toggle : 0;
	keycode == CLICK_RIGHT ? click->right = toggle : 0;
	keycode == CLICK_MIDDLE ? click->middle = toggle : 0;
	keycode == ZOOM ? click->zoom = toggle : 0;
	keycode == UNZOOM ? click->unzoom = toggle : 0;
}
