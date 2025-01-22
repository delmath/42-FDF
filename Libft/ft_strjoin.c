/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:25:03 by madelvin          #+#    #+#             */
/*   Updated: 2024/12/18 15:12:36 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * @brief The ft_strjoin() function allocates (with malloc(3))
 * and returns a new string,
 * which is the result of the concatenation of ’s1’ and ’s2’.
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The new string. NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*dst;
	size_t		s1_len;
	size_t		s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dst = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (dst == NULL)
		return (NULL);
	ft_memcpy(dst, s1, s1_len);
	ft_memcpy(dst + s1_len, s2, s2_len);
	dst[s1_len + s2_len] = '\0';
	return (dst);
}
