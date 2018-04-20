/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   import.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/09 13:52:26 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 16:24:36 by wblondel    ###    #+. /#+    ###.fr     */
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
** We read the file that is behind the file descriptor fd.
** TODO: ft_strsplit() is very slow. It needs optimizations.
*/

static int		read_file(int const fd, t_map *map)
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
		map->width = (map->width == 0) ? yx[1] : MIN(yx[1], map->width);
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
	return (0);
}

/*
** Count the number of lines in a file.
*/

static int		count_lines(int const fd)
{
    /*
    ** This code should be replaced by a lighter code.
    ** Currently, it's very memory intensive as it uses ft_readline (GNL).
    **
    ** Pseudo-code:
    ** int  count;
    **
    ** count = 0;
    **
    */
	int		nblines;
	char	*line;

	nblines = 0;
	while (ft_readline(fd, &line) == 1)
	{
		nblines++;
		ft_strdel(&line);
	}
	return (nblines);
}

/*
** We try to open what's behind the filename. See open_file().
** If OK, we read the file, close the fd, and return the map.
** TODO: Improve open_file() speed. count_lines() is fast enough.
*/

int				import_from_file(char const *filename, t_map *map)
{
	int		fd;

    struct timespec t;
    int64_t			tt_start;
    int64_t			tt_end;

    clock_gettime(CLOCK_REALTIME, &t);
    tt_start = t.tv_sec * INT64_C(1000) + t.tv_nsec / 1000000;
    ft_putstr("Counting number of lines...\n");


	if ((fd = open_file(filename)) >= 0)
	{
		map->height = count_lines(fd);
		close(fd);
	}
	else
		return (-1);

    clock_gettime(CLOCK_REALTIME, &t);
    tt_end = t.tv_sec * INT64_C(1000) + t.tv_nsec / 1000000;
    ft_putnbr(tt_end - tt_start);
    ft_putchar('\n');
	ft_putstr("Done.\n");

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
