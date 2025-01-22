/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:51:32 by madelvin          #+#    #+#             */
/*   Updated: 2024/11/13 04:07:16 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The ft_strcmp() function compares the two strings s1 and s2.
 * The locale is not taken into account
 * (for a locale-aware comparison, see strcoll(3)).
 * The comparison is done using unsigned characters.
 * @param s1 The first string to compare
 * @param s2 The second string to compare
 * @param n The maximum number of characters to compare
 * @return The strcmp() and strncmp() functions return an integer less than,
 * equal to, or greater than zero if s1 (or the first n bytes thereof) is found,
 * respectively, to be less than, to match, or be greater than s2.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
