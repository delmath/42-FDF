/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:21:18 by madelvin          #+#    #+#             */
/*   Updated: 2024/11/13 03:49:05 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The ft_strnstr() function locates the first occurrence
 * of the null-terminated
 * string little in the string big, where not more than
 * len characters are searched.
 * Characters that appear after a `\0' character are not searched.
 * @param big The string to search in
 * @param little The string to search for
 * @param len The maximum number of characters to search
 * @return The functions return a pointer to the beginning of the located string,
 * or NULL if the string is not found. If little is an empty string, big is
 * returned.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && little[j] && i + j < len)
			j++;
		if (!little[j])
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
