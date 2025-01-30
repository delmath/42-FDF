/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:41:31 by madelvin          #+#    #+#             */
/*   Updated: 2024/11/11 16:54:40 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The ft_strrchr() function returns a pointer to the last occurrence of
 * the character c in the string s.
 * @param s The string to search
 * @param c The character to search for
 * @return The functions return a pointer to the matched character or NULL
 * if the character is not found. The terminating null byte is considered
 * part of the string, so that if c is specified as '\0', these functions
 * return a pointer to the terminator.
 */
char	*ft_strrchr(const char *s, int c)
{
	size_t	s_l;

	s_l = ft_strlen(s);
	while (s_l > 0)
	{
		if (s[s_l] == (char)c)
			return ((char *)s + s_l);
		s_l--;
	}
	if (s[s_l] == (char)c)
		return ((char *)s);
	return (NULL);
}
