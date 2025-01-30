/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:16:55 by madelvin          #+#    #+#             */
/*   Updated: 2024/11/13 03:50:59 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The ft_strlcat() function appends the NUL-terminated
 * string src to the end of dst.
 * It will append at most size - strlen(dst) - 1 bytes,
 * NUL-terminating the result.
 * @param dst The destination string
 * @param src The source string
 * @param size The size of the destination
 * @return The total length of the string that would have been created
 * if there was enough space
 */
size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	dst_l;
	size_t	src_l;

	dst_l = ft_strlen(dst);
	src_l = ft_strlen(src);
	if (size <= dst_l)
		return (src_l + size);
	i = 0;
	while (src[i] != '\0' && (dst_l + i) < (size - 1))
	{
		dst[dst_l + i] = src[i];
		i++;
	}
	dst[dst_l + i] = '\0';
	return (dst_l + src_l);
}
