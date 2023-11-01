/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-hark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:01:00 by nel-hark          #+#    #+#             */
/*   Updated: 2022/11/28 17:06:23 by nel-hark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*update(char *holder)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	while (holder[i] && holder[i] != '\n')
		i++;
	if (!holder[i])
	{
		free(holder);
		return (NULL);
	}
	new = (char *)malloc(sizeof(char) * (ft_strlen(holder) - i + 1));
	if (!new)
	{
		free(holder);
		return (NULL);
	}
	i++;
	j = 0;
	while (holder[i])
		new[j++] = holder[i++];
	new[j] = 0;
	free(holder);
	return (new);
}

char	*readline(char *holder)
{
	char	*line;
	int		i;

	i = 0;
	if (!holder[i])
		return (NULL);
	i = 0;
	while (holder[i] && holder[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (holder[i] && holder[i] != '\n')
	{
		line[i] = holder[i];
		i++;
	}
	if (holder[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

char	*read_from_file(int fd, char *holder)
{
	char	*buff;
	int		readed;

	if (holder == NULL)
		holder = ft_calloc(1, 1);
	buff = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	readed = 1;
	while (!ft_strchr(holder, '\n') && readed >= 1)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if (readed == -1)
		{
			free(holder);
			free(buff);
			return (NULL);
		}
		buff[readed] = 0;
		holder = ft_strjoin(holder, buff);
	}
	free(buff);
	return (holder);
}

char	*get_next_line(int fd)
{
	static char	*holder[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	holder[fd] = read_from_file(fd, holder[fd]);
	if (!holder[fd])
		return (NULL);
	line = readline(holder[fd]);
	holder[fd] = update(holder[fd]);
	return (line);
}
