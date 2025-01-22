/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:35:41 by madelvin          #+#    #+#             */
/*   Updated: 2024/11/17 11:55:35 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * @brief The ft_substr() function allocates (with malloc(3)) and returns
 * a substring from the string ’s’.
 * The substring begins at index ’start’ and is of maximum size ’len’.
 * @param s The string from which to create the substring.
 * @param start The start index of the substring in the string ’s’.
 * @param len The maximum length of the substring.
 * @return The substring. NULL if the allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*dst;
	size_t		s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_calloc(1, sizeof(char)));
	if (len > s_len - start)
		len = s_len - start;
	dst = malloc(sizeof(char) * (len + 1));
	if (NULL == dst)
		return (NULL);
	ft_memcpy((void *)dst, (void *)(s + start), len + 1);
	dst[len] = '\0';
	return (dst);
}
