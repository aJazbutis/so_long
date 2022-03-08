/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajazbuti <ajazbuti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:25:54 by ajazbuti          #+#    #+#             */
/*   Updated: 2022/01/28 16:15:41 by ajazbuti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(char *s, t_llst **map)
{
	if (*map)
		ft_llstclear(map, &free);
	perror(s);
	exit (EXIT_FAILURE);
}

void	ft_put_move_count(t_game *gm)
{
	char	*s;

	s = NULL;
	printf("Moves: %d\n", gm->mc);
	s = ft_itoa(gm->mc);
	s = ft_add_prfx("Moves: ", s);
	mlx_put_image_to_window(gm->mlx, gm->win, gm->img[wall].i, 0,
		(gm->h - 1) * M);
	mlx_put_image_to_window(gm->mlx, gm->win, gm->img[wall].i, M,
		(gm->h - 1) * M);
	mlx_string_put(gm->mlx, gm->win, M / 2, (gm->h - 1) * M + 40,
		000000000, s);
	free(s);
}

int	ft_kill_game(t_game *gm)
{
	int	i;

	i = -1;
	while (gm->map[++i])
		free(gm->map[i]);
	free(gm->map);
	i = -1;
	while (gm->img[++i].i)
		mlx_destroy_image(gm->mlx, gm->img[i].i);
	mlx_destroy_window(gm->mlx, gm->win);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_win_game(t_game *gm, int a, int b)
{
	int	x;
	int	y;

	x = (gm->l * M - 200) / 2;
	y = (gm->h * M - 200) / 2;
	gm->fin++;
	gm->mc++;
	ft_put_move_count(gm);
	mlx_put_image_to_window(gm->mlx, gm->win, gm->img[tile].i,
		gm->p.x * M, gm->p.y * M);
	mlx_put_image_to_window(gm->mlx, gm->win, gm->img[done].i,
		a * M, b * M);
	mlx_put_image_to_window(gm->mlx, gm->win, gm->img[wiin].i, x, y);
	printf("You're VICTORIOUS!!\n");
}	
