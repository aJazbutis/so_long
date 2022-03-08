/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajazbuti <ajazbuti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:12:03 by ajazbuti          #+#    #+#             */
/*   Updated: 2022/01/28 13:54:35 by ajazbuti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
	en01,
	en11,
	done,
	boom,
	wiin,
	lose,
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
	t_player	e;
	int			mc;
	char		**map;
	t_img		img[21];
	int			itms;
	int			exts;
	size_t		h;
	size_t		l;
	int			fin;
}t_game;

void	ft_check_validity(t_llst **map, t_game *gm);
void	ft_exit(char *s, t_llst **map);
int		ft_events(int key, t_game *gm);
int		ft_kill_game(t_game *gm);
void	ft_init(t_game *gm, t_llst **map);
void	ft_put_move_count(t_game *gm);
int		ft_kill_game(t_game *gm);
void	ft_win_game(t_game *gm, int a, int b);
int		ft_enemy(t_game *gm);
void	ft_lose_game(t_game *gm, int a, int b);

#endif