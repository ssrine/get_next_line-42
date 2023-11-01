/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-hark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 06:38:33 by nel-hark          #+#    #+#             */
/*   Updated: 2022/11/22 06:52:35 by nel-hark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*c;
	size_t	i;

	i = 0;
	if (count != 0 && size > SIZE_MAX / count)
		return (NULL);
	c = malloc(count * size);
	if (!c)
		return (NULL);
	while (i < count * size)
	{
		*((unsigned char *)(c + i)) = 0;
		i++;
	}
	return (c);
}

int	ft_strlen(char *s)

{
	int	a;

	a = 0;
	while (s && s[a] != '\0')
	{
		a++;
	}
	return (a);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	p = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!p)
		return (NULL);
	while (s1[i])
		p[i++] = s1[j++];
	i = 0;
	while (s2[i])
		p[j++] = s2[i++];
	p[j] = '\0';
	if (s1)
		free(s1);
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}
