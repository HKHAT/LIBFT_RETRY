/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchakir <elchakir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:32:03 by elchakir          #+#    #+#             */
/*   Updated: 2023/11/24 10:50:01 by elchakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_kelma(const char *str, char c)
{
	size_t	size;

	size = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
			size++;
		while (*str && *str != c)
			str++;
	}
	return (size);
}

static void	ft_hayed(char **array)
{
	char	**temp;

	if (array != NULL)
	{
		temp = array;
		while (*temp != NULL)
		{
			free(*temp);
			temp++;
		}
		free(array);
	}
}

static char	*alloc_kelma(const char *start, const char *end)
{
	size_t	len;
	size_t	i;
	char	*kelma;

	i = 0;
	len = end - start;
	kelma = (char *)malloc((len + 1) * sizeof(char));
	if (!kelma)
		return (NULL);
	while (i < len)
	{
		kelma[i] = start[i];
		i++;
	}
	kelma[len] = '\0';
	return (kelma);
}

static char	**ft_walo(const char *s, char **split, char c, size_t len)
{
	size_t		i;
	const char	*start;

	i = 0;
	while (i < len)
	{
		while (*s == c)
			s++;
		start = s;
		while (*s && *s != c)
			s++;
		split[i] = alloc_kelma(start, s);
		if (!split[i])
		{
			ft_hayed(split);
			return (NULL);
		}
		i++;
	}
	split[i] = NULL;
	return (split);
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	size_t	len;

	split = NULL;
	if (!s)
	{
		return (NULL);
	}
	len = count_kelma(s, c);
	split = (char **)malloc((len + 1) * sizeof(char *));
	if (!split)
	{
		return (NULL);
	}
	return (ft_walo(s, split, c, len));
}
