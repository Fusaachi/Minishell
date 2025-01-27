/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranke <pfranke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:47:02 by pfranke           #+#    #+#             */
/*   Updated: 2024/08/05 20:06:13 by pfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*destroyer(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

char	*reusebufer(char *buffer)
{
	int		i;
	int		j;
	char	*nextbuffer;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	nextbuffer = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		nextbuffer[j++] = buffer[i++];
	free(buffer);
	nextbuffer[j] = '\0';
	return (nextbuffer);
}

char	*findline(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*get_from_file(int fd, char *buffer)
{
	char	*tempbuffer;
	int		byte_read;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	tempbuffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, tempbuffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(tempbuffer);
			free(buffer);
			return (NULL);
		}
		tempbuffer[byte_read] = 0;
		buffer = destroyer(buffer, tempbuffer);
		if (ft_strchr(tempbuffer, '\n'))
			break ;
	}
	free(tempbuffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer || !ft_strchr(buffer, '\n'))
		buffer = get_from_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = findline(buffer);
	buffer = reusebufer(buffer);
	return (line);
}
