/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:54:53 by madelvin          #+#    #+#             */
/*   Updated: 2024/11/13 20:16:49 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>
#include <stdlib.h>

static uint8_t	ft_check_is_set(char c, char const *set);

/**
 * @brief This ft_strtrim() function allocates and returns a copy of ’s1’
 * with the characters
 * specified in ’set’ removed from the beginning and the end of the string.
 * @param s1 The string to be trimmed.
 * @param set The reference set of characters to trim.
 * @return The trimmed string. NULL if the allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*dst;

	i = 0;
	end = 0;
	start = 0;
	while (s1[start] && ft_check_is_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_check_is_set(s1[end - 1], set))
		end--;
	dst = malloc(sizeof(char) * (end - start + 1));
	if (dst == NULL)
		return (NULL);
	while (start < end)
		dst[i++] = s1[start++];
	dst[i] = '\0';
	return (dst);
}

static uint8_t	ft_check_is_set(char c, char const *set)
{
	uint8_t	i;

	i = 0;
	while (set[i] && set[i] != c)
		i++;
	return (set[i] == c);
}
