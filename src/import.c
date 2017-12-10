/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   import.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/09 13:52:26 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/10 16:13:17 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static int		open_file(char const *filename);
static int		read_file(int const fd, t_list *l);

/*
** We try to open what's behind the filename. See open_file().
** If OK, we read the file, close the fd, and return the map.
*/
int		import_from_file(char const *filename, t_map *map)
{
	int		fd;
	t_list	*l;

	l = NULL;

	if ((fd = open_file(filename)) >= 0)
	{
		read_file(fd, l);
		close(fd);
		fill_map(map, l);
		return (0);
	}
	else
		return (-1);
}

/*
** We try to open what's behind the filename.
** If it's a directory, we return -1 to exit.
** If it's a file, we return the file descriptor.
** If nothing exists of name filename, we return -1.
*/
static int		open_file(char const *filename)
{
	int		fd;

	fd = open(filename, O_DIRECTORY);
	if (fd >= 0)
		return (-1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}

/*
** We read the file that is behind the file descriptor fd.
*/
static int		read_file(int const fd, t_list *l)
{
	(void)l;
	(void)fd;

	/* TODO: boucle while avec GNL */

	l = ft_lstnew("test", ft_strlen("test"));
	return (0);
}
