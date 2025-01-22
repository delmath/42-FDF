/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:40:29 by madelvin          #+#    #+#             */
/*   Updated: 2024/11/14 21:57:00 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <errno.h>

/**
 * @brief The ft_strdup() function allocates sufficient
 * memory for a copy of the string s,
 * does the copy, and returns a pointer to it.
 * The pointer may subsequently be used as an argument to the function free(3).
 * @param s The string to duplicate.
 * @return The pointer to the duplicated string.
 */
char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s);
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s, len);
	str[len] = '\0';
	return (str);
}
