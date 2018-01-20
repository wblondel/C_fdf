/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 05:55:32 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/20 16:27:05 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

/*
** Prints an error message and exit with error code 1.
*/

void	error(char *msg)
{
	ft_putendl(msg);
	exit(EXIT_FAILURE);
}

/*
** We init our environment (view)
** We import data from file
** We set the hooks and the loop_hook to refresh image
*/

int		main(int argc, char **argv)
{
	t_view	*v;

	if (argc != 2)
		error("error: not enough arguments.");
	v = init_view();
	ft_putstr("Importing from file...\n");
	if ((import_from_file(argv[1], &v->map) == -1))
		error("Error importing from file.\n");
	ft_putstr("DONE!\n");
	set_hooks(v);
	mlx_loop_hook(v->mlx, loop_hook, v);
	mlx_loop(v->mlx);
	return (EXIT_SUCCESS);
}
