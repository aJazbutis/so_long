/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajazbuti <ajazbuti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:44:01 by ajazbuti          #+#    #+#             */
/*   Updated: 2022/01/25 21:13:26 by ajazbuti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_mv_rght(t_game *gm)
{
	if (gm->map[gm->p.y][gm->p.x + 1] == '0' ||
		gm->map[gm->p.y][gm->p.x + 1] == 'C')
	{
		if (gm->mc % 3 == 0)
			mlx_put_image_to_window(gm->mlx, gm->win, gm->img[pl11].i,
				(gm->p.x + 1) * M, gm->p.y * M);
		else if (gm->mc % 3 == 1)
			mlx_put_image_to_window(gm->mlx, gm->win, gm->img[pl15].i,
				(gm->p.x + 1) * M, gm->p.y * M);
		else
			mlx_put_image_to_window(gm->mlx, gm->win, gm->img[pl17].i,
				(gm->p.x + 1) * M, gm->p.y * M);
		mlx_put_image_to_window(gm->mlx, gm->win, gm->img[tile].i,
			gm->p.x * M, gm->p.y * M);
		if (gm->map[gm->p.y][gm->p.x + 1] == 'C')
			gm->itms--;
		gm->map[gm->p.y][gm->p.x] = '0';
		gm->p.x++;
		gm->map[gm->p.y][gm->p.x] = 'P';
		gm->mc++;
		ft_put_move_count(gm);
	}
	else if (gm->map[gm->p.y][gm->p.x + 1] == 'E' && gm->itms == 0)
		ft_win_game(gm, gm->p.x + 1, gm->p.y);
}

static void	ft_mv_left(t_game *gm)
{
	if (gm->map[gm->p.y][gm->p.x - 1] == '0' ||
		gm->map[gm->p.y][gm->p.x - 1] == 'C')
	{
		if (gm->mc % 3 == 0)
			mlx_put_image_to_window(gm->mlx, gm->win, gm->img[pl01].i,
				(gm->p.x - 1) * M, gm->p.y * M);
		else if (gm->mc % 3 == 1)
			mlx_put_image_to_window(gm->mlx, gm->win, gm->img[pl05].i,
				(gm->p.x - 1) * M, gm->p.y * M);
		else
			mlx_put_image_to_window(gm->mlx, gm->win, gm->img[pl07].i,
				(gm->p.x - 1) * M, gm->p.y * M);
		mlx_put_image_to_window(gm->mlx, gm->win, gm->img[tile].i,
			gm->p.x * M, gm->p.y * M);
		if (gm->map[gm->p.y][gm->p.x - 1] == 'C')
			gm->itms--;
		gm->map[gm->p.y][gm->p.x] = '0';
		gm->p.x--;
		gm->map[gm->p.y][gm->p.x] = 'P';
		gm->mc++;
		ft_put_move_count(gm);
	}
	else if (gm->map[gm->p.y][gm->p.x - 1] == 'E' && gm->itms == 0)
		ft_win_game(gm, gm->p.x - 1, gm->p.y);
}

static void	ft_mv_down(t_game *gm)
{
	if (gm->map[gm->p.y + 1][gm->p.x] == '0' ||
			gm->map[gm->p.y + 1][gm->p.x] == 'C')
	{
		if (gm->mc % 2 == 0)
			mlx_put_image_to_window(gm->mlx, gm->win, gm->img[pl08].i,
				gm->p.x * M, (gm->p.y + 1) * M);
		else
			mlx_put_image_to_window(gm->mlx, gm->win, gm->img[pl18].i,
				gm->p.x * M, (gm->p.y + 1) * M);
		mlx_put_image_to_window(gm->mlx, gm->win, gm->img[tile].i,
			gm->p.x * M, gm->p.y * M);
		if (gm->map[gm->p.y + 1][gm->p.x] == 'C')
			gm->itms--;
		gm->map[gm->p.y][gm->p.x] = '0';
		gm->p.y++;
		gm->map[gm->p.y][gm->p.x] = 'P';
		gm->mc++;
		ft_put_move_count(gm);
	}
	else if (gm->map[gm->p.y + 1][gm->p.x] == 'E' && gm->itms == 0)
		ft_win_game(gm, gm->p.x, gm->p.y + 1);
}

static void	ft_mv_up(t_game *gm)
{
	if (gm->map[gm->p.y - 1][gm->p.x] == '0' ||
		gm->map[gm->p.y - 1][gm->p.x] == 'C')
	{
		if (gm->mc % 2 == 0)
			mlx_put_image_to_window(gm->mlx, gm->win, gm->img[pl08].i,
				gm->p.x * M, (gm->p.y - 1) * M);
		else
			mlx_put_image_to_window(gm->mlx, gm->win, gm->img[pl18].i,
				gm->p.x * M, (gm->p.y - 1) * M);
		mlx_put_image_to_window(gm->mlx, gm->win, gm->img[tile].i,
			gm->p.x * M, gm->p.y * M);
		if (gm->map[gm->p.y - 1][gm->p.x] == 'C')
			gm->itms--;
		gm->map[gm->p.y][gm->p.x] = '0';
		gm->p.y--;
		gm->map[gm->p.y][gm->p.x] = 'P';
		gm->mc++;
		ft_put_move_count(gm);
	}
	else if (gm->map[gm->p.y - 1][gm->p.x] == 'E' && gm->itms == 0)
		ft_win_game(gm, gm->p.x, gm->p.y - 1);
}

int	ft_events(int key, t_game *gm)
{
	if ((key == 126 || key == 13) && !gm->fin)
		ft_mv_up(gm);
	if ((key == 125 || key == 1) && !gm->fin)
		ft_mv_down(gm);
	if ((key == 123 || key == 0) && !gm->fin)
		ft_mv_left(gm);
	if ((key == 124 || key == 2) && !gm->fin)
		ft_mv_rght(gm);
	if (key == 53)
		ft_kill_game(gm);
	return (0);
}
