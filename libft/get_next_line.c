/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 08:26:31 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/06 14:46:41 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*clear_all(char *buffer, char *out)
{
	if (out != NULL)
		free(out);
	out = NULL;
	buffer[0] = '\0';
	return (NULL);
}

int	read_buffer(char *buffer, char **out)
{
	size_t	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
	{
		ft_strnjoin(out, buffer, i + 1);
		if (out == NULL)
			return (-1);
		ft_memmove(buffer, buffer + i + 1, BUFFER_SIZE - i);
		buffer[BUFFER_SIZE - i + 1] = '\0';
		return (1);
	}
	if (buffer[0] != '\0' && buffer[i] == '\0')
	{
		ft_strnjoin(out, buffer, i);
		if (out == NULL)
			return (-1);
		buffer[0] = 0;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*out;
	int			bytes_read;

	out = NULL;
	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	while (read_buffer(buffer[fd], &out) == 0)
	{
		bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			if (bytes_read < 0)
				return (clear_all(buffer[fd], out));
			return (out);
		}
		buffer[fd][bytes_read] = '\0';
	}
	if (out == NULL)
		return (clear_all(buffer[fd], out));
	return (out);
}
