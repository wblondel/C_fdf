/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   import.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/09 13:52:26 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/11 12:27:28 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

/*
** Function:	open_file
** ----------------------
**		Opens what's behind the filename.
**
**		filename: the object of the path to open.
**
**		Returns: the file descriptor if it's a file,
**		-1 if it's a directory or if nothing exists at this path.
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
** Function:	set_map_width
** --------------------------
**		Sets the map->width. Function created to comply with the norms...
**
**		map: our map structure.
**		xy: our indices to navigate in the file and the line read.
*/

static void		set_map_width(t_map *map, int yx[2])
{
	map->width = (map->width == -1) ? yx[1] : MIN(yx[1], map->width);
	(map->width == 0) ? error("Error: invalid file") : map->width;
}

/*
** Function:	read_file
** ----------------------
**		Reads the map data from the file behind
**		the given file descriptor.
**
**		fd: the file descriptor.
**		map: our map structure.
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
** Function:	count_lines
** ------------------------
**		Counts the number of lines in a file.
**
**		fd: the file descriptor.
**
**		Returns: the number of lines.
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
** Function:	import_from_file
** -----------------------------
**		Opens the object behind the filename and reads map data from it.
**
**		filename: the file name.
**		map: our map structure.
**
**		Returns: 0 if successful, -1 if failed.
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
