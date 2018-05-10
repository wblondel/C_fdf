/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   image.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 13:40:45 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/10 19:03:11 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

/*
** Function:	mlx_create_image
** -----------------------------
**		Creates an empty mlx_image.
**
**		mlx: the screen connection identifier.
**		image: our image global structure.
**
** Now the important part :
** mlx_get_data_addr will return a char * that is 4 time the width * height of
** your image.
** Why so ? Let me explain : This char * will represent your image, pixel by
** pixel, and the values of this array are the colors. That's why the array is
** 4 times bigger : you need 4 char to code the color of each pixels (one for
** Red, Green and Blue) and one for the alpha. But... it's not very convenient,
** right ? So here is my little trick : you cast mlx_get_data_addr as an int *
** and store it in an int *. This way, the array will have the exact same size
** as your window, and each index will represent one complete color of a pixel !
*/

void	mlx_create_image(void *mlx, t_img *image)
{
	if ((image->ptr = mlx_new_image(mlx, W_WIDTH, W_HEIGHT)) == NULL)
		error("error: mlx_new_image() failed");
	if ((image->pixels = (int *)mlx_get_data_addr(image->ptr,
					&image->bits_per_pixel, &image->size_line, &image->endian))
					== NULL)
		error("error: mlx_get_data_addr() failed");
}
