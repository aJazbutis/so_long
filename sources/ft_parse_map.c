/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajazbuti <ajazbuti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:23:14 by ajazbuti          #+#    #+#             */
/*   Updated: 2022/01/28 15:43:25 by ajazbuti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_top_bttm_check(t_llst **map, t_llst *tmp)
{
	char	*s1;
	char	*s2;

	s1 = (char *)(*map)->content;
	s2 = (char *)tmp->content;
	while (*s1 == '1' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 || *s2)
		ft_exit("Error\nHoles in walls", map);
}

static void	ft_check_chars(t_llst *tmp, t_llst **map, t_game *gm)
{
	int		i;
	char	*line;

	i = -1;
	line = (char *)tmp->content;
	while (line[++i] && ft_strchr("01CEP", line[i]))
	{
		if (line[i] == 'C')
			gm->itms++;
		if (line[i] == 'E')
			gm->exts++;
		if (line[i] == 'P')
		{
			if (gm->p.y == 0)
				gm->p.y = tmp->ij;
			if (gm->p.x == 0)
				gm->p.x = i;
			else
				line[i] = '0';
		}
	}
	if (i && line[i] == '\0' && line[0] == line[i - 1] && line[0] == '1')
		return ;
	else
		ft_exit("Error\nUnfamiliar symbols in map or holes in walls", map);
}

static void	ft_check_validity(t_llst **map, t_game *gm)
{
	t_llst	*tmp;

	gm->l = ft_strlen((*map)->content);
	gm->h = ft_llstsize(*map);
	if (gm->l < 3 || gm->h < 3)
		ft_exit("Error\nToo small map", map);
	tmp = (*map)->next;
	while (tmp->next)
	{
		if (ft_strlen(tmp->content) == gm->l)
		{
			ft_check_chars(tmp, map, gm);
			tmp = tmp->next;
		}
		else
			ft_exit("Error\nMessy line lengthsesss", map);
	}
	ft_top_bttm_check(map, tmp);
}

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

void	ft_parse_map(char *name, t_llst **map, t_game *gm)
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
