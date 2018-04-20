/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 05:55:32 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/08 06:46:25 by wblondel    ###    #+. /#+    ###.fr     */
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
	t_global	*g;

	printf("My process ID: %d\n", getpid());
	/*getchar();*/

	if (argc != 2)
		error("error: not enough arguments.");
	g = init_global();
	ft_putstr("Importing from file...\n");
	if ((import_from_file(argv[1], &g->map) == -1))
		error("Error importing from file.\n");
	ft_putstr("DONE!\n");
	set_hooks(g);
	mlx_loop_hook(g->mlx, loop_hook, g);
	mlx_loop(g->mlx);
	return (EXIT_SUCCESS);
}
