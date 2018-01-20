/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   import.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/09 13:52:26 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/20 14:46:29 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static int		open_file(char const *filename);
static int		read_file(int const fd, int const nblines, t_map *map);
static int		count_lines(int const fd);

/*
** We try to open what's behind the filename. See open_file().
** If OK, we read the file, close the fd, and return the map.
*/
int		import_from_file(char const *filename, t_map *map)
{
	int		fd;
	int		nblines;

	if ((fd = open_file(filename)) >= 0)
	{
		nblines = count_lines(fd);
		close(fd);
	}

	if ((fd = open_file(filename)) >= 0)
	{
		read_file(fd, nblines, map);
		close(fd);
		/*fill_map(map, lst);*/
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
static int		read_file(int const fd, int const nblines, t_map *map)
{
	int		i;

	i = 0;
	map->filelines = (char**) ft_memalloc(nblines * sizeof(char*));

	while (get_next_line(fd, &map->filelines[i]) == 1)
	{
		ft_putendl(map->filelines[i]);
		i++;
	}

	return (0);
}

/*
** Count the number of lines in a file.
*/
static int		count_lines(int const fd)
{
	int		nblines;
	char	*line;

	nblines = 0;
	while (get_next_line(fd, &line) == 1)
		nblines++;
	free(line);

	return (nblines);
}
