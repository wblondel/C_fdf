/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 05:55:32 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/09 15:18:02 by wblondel    ###    #+. /#+    ###.fr     */
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

	if (argc != 2)
		error("error: not enough arguments.");

	/* We init our environment (view) */
	v = init_view();

	/* We import data from file */
	ft_putstr("Importing from file... ");
	if ((import_from_file(argv[1], &v->map) == -1))
		error("error importing from file.");
	ft_putstr("DONE!\n");

	/* We set the hooks and the loop_hook to refresh image */
	set_hooks(v);
	mlx_loop_hook(v->mlx, loop_hook, v);
	mlx_loop(v->mlx);

	return (EXIT_SUCCESS);
}
