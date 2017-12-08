/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 05:54:33 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/08 10:14:13 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

/*
** Includes
*/
# include <stdio.h>
# include <errno.h>
# include <math.h>

# include "mlx.h"
# include "libft.h"

/*
** Constants
*/
# define W_WIDTH 800
# define W_HEIGHT 600

/*
** Structs
*/
typedef struct		s_img
{
	void			*img_ptr;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win;
	t_img			img;
}					t_mlx;

/*
** main.c
*/
void 				error(char *msg);

/*
** init.c
*/
t_mlx 				init_mlx(void);

/*
** hooks.c
*/
int					key_hook(int keycode, void *param);

/*
** render.c
*/
void 				render_horizontal_lines(int *data);

#endif
