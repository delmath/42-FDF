/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:18:35 by madelvin          #+#    #+#             */
/*   Updated: 2024/11/13 03:49:35 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The ft_strmapi() function applies the function ’f’
 * to each character of the string ’s’
 * to create a new string resulting from successive applications of ’f’.
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 * @return The string created from the successive applications of ’f’.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*dst;

	dst = ft_strdup(s);
	if (NULL == dst)
		return (NULL);
	i = 0;
	while (dst[i] != '\0')
	{
		dst[i] = f(i, dst[i]);
		i++;
	}
	return (dst);
}
