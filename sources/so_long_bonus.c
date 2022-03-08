/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajazbuti <ajazbuti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:36:39 by ajazbuti          #+#    #+#             */
/*   Updated: 2022/01/28 15:42:09 by ajazbuti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_enlist(char *line, t_llst **map)
{
	char	*cont;
	t_llst	*new;

	cont = ft_substr(line, 0, ft_strlen(line) - 1);
	if (!cont)
		ft_exit("Error\nMalloc failure", map);
	new = ft_llstnew(cont);
	if (!new)
		ft_exit("Error\nMalloc failure", map);
	if (*map)
	{
		ft_llstadd_back(map, new);
		new->ij = (new->prev)->ij + 1;
	}
	else
	{
		*map = new;
		new->ij = 0;
	}
}

static void	ft_parse_map(char *name, t_llst **map, t_game *gm)
{
	char	*line;
	int		fd;

	fd = open(name, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		ft_exit("Error\nEmpty file or read error", map);
	while (line)
	{
		ft_enlist(line, map);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	ft_memset(gm, 0, sizeof(t_game));
	ft_check_validity(map, gm);
	if (!gm->p.x)
		ft_exit("Error\nNo Homer :(", map);
	if (!gm->itms)
		ft_exit("Error\nNo doughnuts :(", map);
	if (!gm->exts)
		ft_exit("Error\nNo exit :(", map);
}

int	main(int argc, char **argv)
{	
	t_llst	*map;
	t_game	gm;

	if (argc != 2)
	{
		perror("Error\nNo map or more than one argument provided");
		return (0);
	}
	map = NULL;
	if (!ft_extension_is_ok(".ber", argv[1]))
		ft_exit("Error\nWrong file type", &map);
	else
		ft_parse_map(argv[1], &map, &gm);
	ft_init(&gm, &map);
	mlx_hook(gm.win, 2, 1L << 2, &ft_events, &gm);
	mlx_hook(gm.win, 17, 1L << 17, &ft_kill_game, &gm);
	mlx_loop_hook(gm.mlx, ft_enemy, &gm);
	mlx_loop(gm.mlx);
	return (0);
}
