/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 05:55:32 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/08 13:45:10 by wblondel    ###    #+. /#+    ###.fr     */
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
	t_view	*v;
	(void)argv;

	if (argc != 2)
		error("error: not enough arguments.");

	v = init_view();

	set_hooks(v);
	mlx_loop_hook(v->mlx, loop_hook, v);
	mlx_loop(v->mlx);

	return (EXIT_SUCCESS);
}
