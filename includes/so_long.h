/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajazbuti <ajazbuti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:16:16 by ajazbuti          #+#    #+#             */
/*   Updated: 2022/01/28 13:55:55 by ajazbuti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../mlx/mlx.h"
# include <errno.h>
# include <stdio.h>
# define M 50

typedef struct s_player
{
	int		y;
	int		x;
}t_player;

enum e_img
{
	tile,
	wall,
	cllc,
	extt,
	pl01,
	pl05,
	pl07,
	pl08,
	pl11,
	pl15,
	pl17,
	pl18,
	pll0,
	pll1,
	done,
	wiin,
	null,
};

typedef struct s_img
{
	char		*p;
	void		*i;
	enum e_img	name;
}t_img;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_player	p;
	int			mc;
	char		**map;
	t_img		img[17];
	int			itms;
	int			exts;
	size_t		h;
	size_t		l;
	int			fin;
}t_game;

void	ft_parse_map(char *name, t_llst **map, t_game *gm);
void	ft_exit(char *s, t_llst **map);
int		ft_events(int key, t_game *gm);
int		ft_kill_game(t_game *gm);
void	ft_init(t_game *gm, t_llst **map);
void	ft_put_move_count(t_game *gm);
int		ft_kill_game(t_game *gm);
void	ft_win_game(t_game *gm, int a, int b);

#endif
