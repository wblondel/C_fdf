/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 05:55:32 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/08 08:39:37 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "main.h"

int		main(void)
{
	int		win_width;
	int		win_height;
	t_mlx	mlx;

	win_width = 800;
	win_height = 600;

	/*
	** First you need to call mlx_init and store its return value.
	*/
	if ((mlx.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);

	/*
	** Now do the same with mlx_new_window
	*/
	if ((mlx.win = mlx_new_window(mlx.mlx_ptr, win_width, win_height, "a")) == NULL)
		return (EXIT_FAILURE);

	/*
	** One more time with mlx_new_image
	*/
	mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, win_width, win_height);

	/*
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
	mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp,
											&mlx.img.size_l, &mlx.img.endian);

	/*
	** Now you just have to print the image using mlx_put_image_to_window !
	*/
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img_ptr, 0, 0);

	mlx_loop(mlx.mlx_ptr);
	return (EXIT_SUCCESS);
}
