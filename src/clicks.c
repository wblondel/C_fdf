/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   clicks.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/09 11:45:24 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/09 11:58:32 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <fdf.h>

void 			clicks_init(t_clicks *click)
{
	click->none = 0;
	click->click_left = 0;
	click->click_right = 0;
	click->click_middle = 0;
	click->zoom = 0;
	click->unzoom = 0;
}

void click_toggle(t_clicks *click, int keycode, int toggle)
{
	keycode == CLICK_LEFT ? click->click_left = toggle : 0;
	keycode == CLICK_RIGHT ? click->click_right = toggle : 0;
	keycode == CLICK_MIDDLE ? click->click_middle = toggle : 0;
	keycode == ZOOM ? click->zoom = toggle : 0;
	keycode == UNZOOM ? click->unzoom = toggle : 0;
}
