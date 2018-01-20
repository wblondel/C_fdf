/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   image.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 13:40:45 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 01:39:18 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	create_image(void *mlx, t_img *image)
{
	if ((image->ptr = mlx_new_image(mlx, W_WIDTH, W_HEIGHT)) == NULL)
		error("error: mlx_new_image() failed");
	if ((image->pixels = (int *)mlx_get_data_addr(image->ptr, &image->bits_per_pixel,
					&image->size_line, &image->endian)) == NULL)
		error("error: mlx_get_data_addr() failed");
}
