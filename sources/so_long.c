/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajazbuti <ajazbuti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:36:39 by ajazbuti          #+#    #+#             */
/*   Updated: 2022/01/28 13:47:18 by ajazbuti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		ft_exit("Error\nUnknown map format", &map);
	else
		ft_parse_map(argv[1], &map, &gm);
	ft_init(&gm, &map);
	mlx_hook(gm.win, 2, 1L << 2, &ft_events, &gm);
	mlx_hook(gm.win, 17, 1L << 17, &ft_kill_game, &gm);
	mlx_loop(gm.mlx);
	return (0);
}
