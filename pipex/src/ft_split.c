/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 09:02:12 by hzona             #+#    #+#             */
/*   Updated: 2021/10/09 16:28:25 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*res;
	size_t		i;

	if (!s)
		return ((void *)0);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	i = 0;
	res = malloc(sizeof(char) * (len + 1));
	if (res == (void *)0)
		return ((void *)0);
	while (i < len)
	{
		if (s[start + i] != '\0' && start < ft_strlen(s))
			res[i] = s[start + i];
		else
			res[i] = '\0';
		i++;
	}
	res[i] = '\0';
	return (res);
}

static size_t	word_len(const char *str, char c)
{
	size_t			i;
	size_t			count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((str[i] != c && str[i + 1] && str[i + 1] == c)
			|| (str[i] != c && !str[i + 1]))
			count++;
		i++;
	}
	return (count);
}

static size_t	len_split(const char *str, char c)
{
	size_t			i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static char	**clean_split(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return ((void *)0);
}

char	**ft_split(char const *s, char c)
{
	size_t			i;
	size_t			start;
	char			**arr;

	i = 0;
	start = 0;
	if (!s)
		return ((void *)0);
	arr = malloc((word_len(s, c) + 1) * sizeof(char *));
	if (!arr)
		return ((void *)0);
	while (s[i++] == c)
		start++;
	i = -1;
	while (++i < word_len(s, c))
	{
		arr[i] = ft_substr(s, start, len_split(&s[start], c));
		if (!arr[i])
			return (clean_split(arr));
		start += len_split(&s[start], c);
		while (s[start] == c)
			start++;
	}
	arr[i] = (void *)0;
	return (arr);
}
