/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajazbuti <ajazbuti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 21:18:30 by ajazbuti          #+#    #+#             */
/*   Updated: 2021/09/22 19:11:33 by ajazbuti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_one(char *s, char c)
{
	int	i;

	i = 1;
	while (*s)
	{
		while (*s != c && *s)
			s++;
		if (*s == '\0')
			return (++i);
		while (*s == c && *s)
			s++;
		if (*s == '\0')
			return (i);
		i++;
	}
	return (i);
}

static int	ft_word_len(char *str, char c)
{
	int	i;

	i = 0;
	while (*str != c && *str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

static char	**ft_set_all_free(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static void	ft_extract(char **split, char *str, char c, int len)
{
	int	i;
	int	wlen;

	i = 0;
	while (i < len - 1)
	{
		wlen = ft_word_len(str, c);
		split[i] = (char *)ft_calloc(wlen + 1, sizeof(char));
		if (!split[i])
		{
			split = ft_set_all_free(split);
			return ;
		}
		ft_memcpy(split[i], str, wlen);
		if (ft_strchr(str, c))
		{
			str = ft_strchr(str, c);
			while (*str == c)
				str++;
		}
		else
			str++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	char	*str;
	int		i;
	int		len;

	if (s == NULL)
		return (NULL);
	split = NULL;
	str = ft_strtrim(s, &c);
	if (!str)
		return (split);
	i = 0;
	len = ft_size_one(str, c);
	split = (char **)malloc(len * sizeof(char *));
	if (!split)
		return (split);
	while (i < len)
		split[i++] = NULL;
	ft_extract(split, str, c, len);
	free(str);
	return (split);
}
