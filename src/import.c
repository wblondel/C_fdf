/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   import.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/09 13:52:26 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/09 17:05:01 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

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
** Sets the map->width. Function created to comply with the norms...
*/

static void		set_map_width(t_map *map, int yx[2])
{
	map->width = (map->width == -1) ? yx[1] : MIN(yx[1], map->width);
	(map->width == 0) ? error("Error: invalid file") : map->width;
}

/*
** We read the file that is behind the file descriptor fd.
*/

static void		read_file(int const fd, t_map *map)
{
	int		yx[2];
	char	**split;
	char	*line;

	yx[0] = 0;
	map->file = (int**)ft_memalloc(map->height * sizeof(int*));
	while (ft_readline(fd, &line) == 1)
	{
		yx[1] = 0;
		split = ft_strsplit(line, ' ');
		ft_strdel(&line);
		while (split[yx[1]])
			yx[1]++;
		set_map_width(map, yx);
		yx[1] = -1;
		map->file[yx[0]] = (int *)ft_memalloc(map->width * sizeof(int));
		while (split[++yx[1]])
		{
			map->file[yx[0]][yx[1]] = ft_atoi(split[yx[1]]);
			ft_strdel(&split[yx[1]]);
		}
		free(split);
		yx[0]++;
	}
	ft_strdel(&line);
}

/*
** Count the number of lines in a file.
*/

static int		count_lines(int const fd)
{
	int		nblines;
	char	*line;

	nblines = 0;
	while (ft_readline(fd, &line) == 1)
	{
		nblines++;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (nblines);
}

/*
** We try to open what's behind the filename. See open_file().
** If OK, we read the file, close the fd, and return the map.
*/

int				import_from_file(char const *filename, t_map *map)
{
	int		fd;

	if ((fd = open_file(filename)) >= 0)
	{
		map->height = count_lines(fd);
		close(fd);
	}
	else
		return (-1);
	ft_putstr("Reading file...\n");
	if ((fd = open_file(filename)) >= 0)
	{
		read_file(fd, map);
		close(fd);
		return (0);
	}
	else
		return (-1);
}
