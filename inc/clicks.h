/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   clicks.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/09 11:42:36 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 20:13:42 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CLICKS_H
# define CLICKS_H

# define CLICK_LEFT 1
# define CLICK_RIGHT 2
# define CLICK_MIDDLE 3
# define UNZOOM 4
# define ZOOM 5

typedef struct	s_clicks
{
	int			left:1;
	int			right:1;
	int			middle:1;
	int			zoom:1;
	int			unzoom:1;
}				t_clicks;
#endif
