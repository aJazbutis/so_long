/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajazbuti <ajazbuti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:27:59 by ajazbuti          #+#    #+#             */
/*   Updated: 2022/01/27 19:09:39 by ajazbuti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_up(t_game *gm)
{
	if (gm->map[gm->e.y - 1][gm->e.x] == '0')
	{
		if (gm->e.x >= gm->p.x)
			mlx_put_image_to_window(gm->mlx, gm->win, gm->img[en01].i,
				gm->e.x * M, (gm->e.y - 1) * M);
		else
			mlx_put_image_to_window(gm->mlx, gm->win, gm->img[en11].i,
				gm->e.x * M, (gm->e.y - 1) * M);
		mlx_put_image_to_window(gm->mlx, gm->win, gm->img[tile].i,
			gm->e.x * M, gm->e.y * M);
		gm->map[gm->e.y][gm->e.x] = '0';
		gm->e.y--;
		gm->map[gm->e.y][gm->e.x] = 'X';
	}
	else if (gm->map[gm->e.y - 1][gm->e.x] == 'P')
		ft_lose_game(gm, gm->e.x, gm->e.y - 1);
}

static void	ft_right(t_game *gm)
{
	if (gm->map[gm->e.y][gm->e.x + 1] == '0')
	{
		if (gm->e.x >= gm->p.x)
			mlx_put_image_to_window(gm->mlx, gm->win, gm->img[en01].i,
				(gm->e.x + 1) * M, gm->e.y * M);
		else
			mlx_put_image_to_window(gm->mlx, gm->win, gm->img[en11].i,
				(gm->e.x + 1) * M, gm->e.y * M);
		mlx_put_image_to_window(gm->mlx, gm->win, gm->img[tile].i,
			gm->e.x * M, gm->e.y * M);
		gm->map[gm->e.y][gm->e.x] = '0';
		gm->e.x++;
		gm->map[gm->e.y][gm->e.x] = 'X';
	}
	else if (gm->map[gm->e.y][gm->e.x + 1] == 'P')
		ft_lose_game(gm, gm->e.x + 1, gm->e.y);
}

static void	ft_left(t_game *gm)
{
	if (gm->map[gm->e.y][gm->e.x - 1] == '0')
	{
		if (gm->e.x > gm->p.x)
			mlx_put_image_to_window(gm->mlx, gm->win, gm->img[en01].i,
				(gm->e.x - 1) * M, gm->e.y * M);
		else
			mlx_put_image_to_window(gm->mlx, gm->win, gm->img[en11].i,
				(gm->e.x - 1) * M, gm->e.y * M);
		mlx_put_image_to_window(gm->mlx, gm->win, gm->img[tile].i,
			gm->e.x * M, gm->e.y * M);
		gm->map[gm->e.y][gm->e.x] = '0';
		gm->e.x--;
		gm->map[gm->e.y][gm->e.x] = 'X';
	}
	else if (gm->map[gm->e.y][gm->e.x - 1] == 'P')
		ft_lose_game(gm, gm->e.x - 1, gm->e.y);
}

static void	ft_down(t_game *gm)
{
	if (gm->map[gm->e.y + 1][gm->e.x] == '0')
	{
		if (gm->e.x > gm->p.x)
			mlx_put_image_to_window(gm->mlx, gm->win, gm->img[en01].i,
				gm->e.x * M, (gm->e.y + 1) * M);
		else
			mlx_put_image_to_window(gm->mlx, gm->win, gm->img[en11].i,
				gm->e.x * M, (gm->e.y + 1) * M);
		mlx_put_image_to_window(gm->mlx, gm->win, gm->img[tile].i,
			gm->e.x * M, gm->e.y * M);
		gm->map[gm->e.y][gm->e.x] = '0';
		gm->e.y++;
		gm->map[gm->e.y][gm->e.x] = 'X';
	}
	else if (gm->map[gm->e.y + 1][gm->e.x] == 'P')
		ft_lose_game(gm, gm->e.x, gm->e.y + 1);
}

int	ft_enemy(t_game *gm)
{
	int			rng;
	static int	t;

	if (gm->e.x == 0)
		return (0);
	t++;
	if (!gm->fin && t > 1000)
	{
		rng = rand();
		if (rng % 4 == 0)
			ft_up(gm);
		else if (rng % 4 == 1)
			ft_right(gm);
		else if (rng % 4 == 2)
			ft_down(gm);
		if (rng % 4 == 3)
			ft_left(gm);
		t = 0;
	}
	return (0);
}
