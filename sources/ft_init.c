/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajazbuti <ajazbuti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:58:35 by ajazbuti          #+#    #+#             */
/*   Updated: 2022/01/28 15:53:51 by ajazbuti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_init_img(t_game *gm)
{
	int	x;
	int	y;

	gm->img[tile].i = mlx_xpm_file_to_image(gm->mlx, gm->img[tile].p, &x, &y);
	gm->img[wall].i = mlx_xpm_file_to_image(gm->mlx, gm->img[wall].p, &x, &y);
	gm->img[cllc].i = mlx_xpm_file_to_image(gm->mlx, gm->img[cllc].p, &x, &y);
	gm->img[extt].i = mlx_xpm_file_to_image(gm->mlx, gm->img[extt].p, &x, &y);
	gm->img[pl01].i = mlx_xpm_file_to_image(gm->mlx, gm->img[pl01].p, &x, &y);
	gm->img[pl05].i = mlx_xpm_file_to_image(gm->mlx, gm->img[pl05].p, &x, &y);
	gm->img[pl07].i = mlx_xpm_file_to_image(gm->mlx, gm->img[pl07].p, &x, &y);
	gm->img[pl08].i = mlx_xpm_file_to_image(gm->mlx, gm->img[pl08].p, &x, &y);
	gm->img[pl11].i = mlx_xpm_file_to_image(gm->mlx, gm->img[pl11].p, &x, &y);
	gm->img[pl15].i = mlx_xpm_file_to_image(gm->mlx, gm->img[pl15].p, &x, &y);
	gm->img[pl17].i = mlx_xpm_file_to_image(gm->mlx, gm->img[pl17].p, &x, &y);
	gm->img[pl18].i = mlx_xpm_file_to_image(gm->mlx, gm->img[pl18].p, &x, &y);
	gm->img[pll1].i = mlx_xpm_file_to_image(gm->mlx, gm->img[pll1].p, &x, &y);
	gm->img[pll0].i = mlx_xpm_file_to_image(gm->mlx, gm->img[pll0].p, &x, &y);
	gm->img[wiin].i = mlx_xpm_file_to_image(gm->mlx, gm->img[wiin].p, &x, &y);
	gm->img[done].i = mlx_xpm_file_to_image(gm->mlx, gm->img[done].p, &x, &y);
	gm->img[null].i = NULL;
}

static void	ft_set_path(t_game *gm)
{
	gm->img[tile].p = "./img/grass50x50.xpm";
	gm->img[wall].p = "./img/trees50x50.xpm";
	gm->img[cllc].p = "./img/donut50x50.xpm";
	gm->img[extt].p = "./img/sofa50x50.xpm";
	gm->img[pl01].p = "./img/homer01.xpm";
	gm->img[pl08].p = "./img/homer08.xpm";
	gm->img[pl05].p = "./img/homer05.xpm";
	gm->img[pl07].p = "./img/homer07.xpm";
	gm->img[pl11].p = "./img/homer11.xpm";
	gm->img[pl18].p = "./img/homer18.xpm";
	gm->img[pl15].p = "./img/homer15.xpm";
	gm->img[pl17].p = "./img/homer17.xpm";
	gm->img[pll0].p = "./img/eat_lft.xpm";
	gm->img[pll1].p = "./img/eat_rght.xpm";
	gm->img[wiin].p = "./img/win200x200.xpm";
	gm->img[done].p = "./img/homersofa.xpm";
	ft_init_img(gm);
}

static void	ft_lst_to_tab(t_game *gm, t_llst **map)
{
	int		i;
	t_llst	*tmp;

	tmp = *map;
	i = 0;
	while (tmp)
	{
		gm->map[i] = ft_strdup(tmp->content);
		tmp = tmp->next;
		i++;
		gm->map[i] = NULL;
		if (!gm->map[i - 1])
		{
			ft_free_tab(gm->map);
			ft_llstclear(map, &free);
			perror("Error\nMalloc failure");
			exit(EXIT_FAILURE);
		}
	}
	ft_llstclear(map, &free);
}

static void	ft_put_map(t_game *gm)
{
	int		i[2];

	i[0] = -1;
	while (gm->map[++i[0]])
	{
		i[1] = -1;
		while (gm->map[i[0]][++i[1]])
		{
			if (gm->map[i[0]][i[1]] == '1')
				mlx_put_image_to_window(gm->mlx, gm->win, gm->img[wall].i,
					i[1] * M, i[0] * M);
			else if (gm->map[i[0]][i[1]] == '0')
				mlx_put_image_to_window(gm->mlx, gm->win, gm->img[tile].i,
					i[1] * M, i[0] * M);
			else if (gm->map[i[0]][i[1]] == 'C')
				mlx_put_image_to_window(gm->mlx, gm->win, gm->img[cllc].i,
					i[1] * M, i[0] * M);
			else if (gm->map[i[0]][i[1]] == 'E')
				mlx_put_image_to_window(gm->mlx, gm->win, gm->img[extt].i,
					i[1] * M, i[0] * M);
			else
				mlx_put_image_to_window(gm->mlx, gm->win, gm->img[pl15].i,
					i[1] * M, i[0] * M);
		}
	}
}

void	ft_init(t_game *gm, t_llst **map)
{
	gm->mlx = mlx_init();
	gm->win = mlx_new_window(gm->mlx, gm->l * M, gm->h * M, "so_long");
	gm->map = (char **)malloc((ft_llstsize(*map) + 1) * sizeof(char *));
	ft_set_path(gm);
	ft_lst_to_tab(gm, map);
	ft_put_map(gm);
	ft_put_move_count(gm);
}
