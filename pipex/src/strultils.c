/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strultils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:50:31 by hzona             #+#    #+#             */
/*   Updated: 2021/11/06 14:22:25 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		k;
	size_t		temp;
	char		*test;

	i = 0;
	test = (char *)big;
	if (little[i] == '\0')
		return (&test[i]);
	while (big[i] && i < len)
	{
		k = 0;
		temp = i;
		while (little[k] && big[temp] == little[k] && big[temp] && temp < len)
		{
			temp++;
			k++;
		}
		if (little[k] == '\0')
			return (&test[i]);
		i++;
	}
	return ((void *)0);
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (str1[i] != '\0' || str2[i] != '\0'))
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		k;

	if (!s1 || !s2)
		return ((void *)0);
	i = 0;
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (res == (void *)0 || !s1 || !s2)
		return ((void *)0);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	k = 0;
	while (s2[k])
	{
		res[i] = s2[k];
		i++;
		k++;
	}
	res[i] = '\0';
	return (res);
}

size_t	ft_strlen(const char *string)
{
	size_t	i;

	i = 0;
	while (string[i])
	{
		i++;
	}
	return (i);
}
