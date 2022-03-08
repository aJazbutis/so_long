/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_validity_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajazbuti <ajazbuti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:05:46 by ajazbuti          #+#    #+#             */
/*   Updated: 2022/01/28 16:52:21 by ajazbuti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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

static void	ft_check_chars_norm(t_game *gm, char *s, int *i, int y)
{
	while (s[++(*i)] && ft_strchr("01CEPX", s[*i]))
	{
		if (s[*i] == 'C')
			gm->itms++;
		if (s[*i] == 'E')
			gm->exts++;
		if (s[*i] == 'P')
		{
			if (gm->p.y == 0)
				gm->p.y = y;
			if (gm->p.x == 0)
				gm->p.x = *i;
			else
				s[*i] = '0';
		}
		if (s[*i] == 'X')
		{
			if (gm->e.y == 0)
				gm->e.y = y;
			if (gm->e.x == 0)
				gm->e.x = *i;
			else
				s[*i] = '0';
		}
	}
}

static void	ft_check_chars(t_llst *tmp, t_llst **map, t_game *gm)
{
	int		i;
	char	*line;

	i = -1;
	line = (char *)tmp->content;
	ft_check_chars_norm(gm, line, &i, tmp->ij);
	if (i && line[i] == '\0' && line[0] == line[i - 1] && line[0] == '1')
		return ;
	else
		ft_exit("Error\nUnfamiliar symbols in map or holes in walls", map);
}

void	ft_check_validity(t_llst **map, t_game *gm)
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
