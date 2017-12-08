/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 09:36:18 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/08 10:16:13 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

/*
** First you need to call mlx_init and store its return value.
** Now do the same with mlx_new_window
** One more time with mlx_new_image
**
** Now the important part :
** mlx_get_data_addr will return a char * that is 4 time the width * height of your imqge.
** Why so ? Let me explain : This char * will represent your image, pixel by pixel,
** and the values of this array are the colors. That's why the array is 4 times bigger :
** you need 4 char to code the color of each pixels (one for Red, Green and Blue) and one for the alpha.
** But... it's not very convenient, right ? So here is my little trick : you cast
** mlx_get_data_addr as an int * and store it in an int *.
** This way, the array will have the exact same size as your window, and each index
** will represent one complete color of a pixel !
*/
t_mlx		init_mlx(void)
{
	t_mlx mlx;

	if ((mlx.mlx_ptr = mlx_init()) == NULL)
		error("error: mlx_init() failed");
	if ((mlx.win = mlx_new_window(mlx.mlx_ptr, W_WIDTH, W_HEIGHT,
						"FdF Reader")) == NULL)
		error("error: mlx_new_window() failed");
	if ((mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, W_WIDTH, W_HEIGHT))
						== NULL)
		error("error: mlx_new_image() failed");
	if ((mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp,
						&mlx.img.size_l, &mlx.img.endian)) == NULL)
		error("error: mlx_get_data_addr() failed");
	return (mlx);
}
