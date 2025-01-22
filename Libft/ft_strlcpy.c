/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:26:48 by madelvin          #+#    #+#             */
/*   Updated: 2024/11/13 03:50:39 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The ft_strlcpy() function copies up to (size - 1)
 * characters from the NUL-terminated string src
 * to dst, NUL-terminating the result.
 * @param dst The destination string
 * @param src The source string
 * @param size The size of the destination
 * @return The total length of the string that would have been created
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_l;
	size_t	i;

	src_l = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (src_l);
	while (src[i] != '\0' && (i < (size - 1)))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_l);
}
