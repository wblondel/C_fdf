/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 05:55:32 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/08 10:17:09 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

/*
** Prints an error message and exit with error code 1.
*/

void 	error(char *msg)
{
	ft_putendl(msg);
	exit(EXIT_FAILURE);
}

int		main(int argc, char **argv)
{
	t_mlx	mlx;
	(void)argv;

	if (argc != 2)
		error("error: not enough arguments.");

	mlx = init_mlx();

	render_horizontal_lines(mlx.img.data);

	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img_ptr, 0, 0);

	mlx_key_hook(mlx.win, key_hook, 0);
	mlx_loop(mlx.mlx_ptr);

	return (EXIT_SUCCESS);
}
