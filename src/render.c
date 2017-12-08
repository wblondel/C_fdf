/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   render.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 09:42:45 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/08 10:01:53 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

/*
** Now just a little example : here is a loop that will draw each pixels that
** have an odd width in white and the ones that have an even width in black.
*/
void 	render_horizontal_lines(int *data)
{
	int count_h;
	int count_w;

	count_h = -1;
	while (++count_h < W_HEIGHT)
	{
		count_w = -1;
		while (++count_w < W_WIDTH)
		{
			if (count_w % 8)
				data[count_h * W_WIDTH + count_w] = 0xFFFFFF;
			else
				data[count_h * W_WIDTH + count_w] = 0;
		}
	}
}
