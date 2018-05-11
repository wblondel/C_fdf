/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 05:55:32 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/11 14:27:01 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

/*
** Function:	main
** -----------------
**		Initialises our environment, imports the map from a file,
**		and creates the GUI.
**
**		argc: number of arguments passed (including the binary name).
**		argv: array of aguments.
**
**		Returns: 0 (isn't reached anyway).
*/

int		main(int argc, char **argv)
{
	t_global	*g;

	if (argc != 2)
		error("Error: No file passed.");
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
