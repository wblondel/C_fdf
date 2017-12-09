/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   render.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 09:42:45 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/09 15:22:26 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"
#include <time.h>
#include <stdlib.h>

/*
** Now just a little example : here is a loop that will draw each pixels that
** have an odd width in white and the ones that have an even width in black.
*/
void 	render_horizontal_lines(int *pixels)
{
	int count_h;
	int count_w;

	count_h = -1;
	while (++count_h < W_HEIGHT)
	{
		count_w = -1;
		while (++count_w < W_WIDTH)
		{
			if (count_w % 20)
				pixels[count_h * W_WIDTH + count_w] = 0x6379FF;
			else
				pixels[count_h * W_WIDTH + count_w] = 0xFFEB69;
		}
	}
}

/*
** We need do have our file stored somewhere.
** We don't want to read our file each time we create the image...
*/
void	render_map(int *pixels)
{
	(void)pixels;
}
