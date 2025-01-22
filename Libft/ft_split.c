/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:23:34 by madelvin          #+#    #+#             */
/*   Updated: 2024/12/19 20:57:04 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_split_word(char **dst, char c, const char *s);

/**
 * @brief The ft_split() function allocates (with malloc(3)) and returns
 * an array of strings obtained by splitting ’s’ using the character ’c’
 * as a delimiter. The array must be
 * ended by a NULL pointer.
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return The array of new strings resulting from the split.
 * NULL if the allocation fails.
 */
char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	char	**dst;

	word_count = ft_count_words(s, c);
	dst = ft_calloc((word_count + 1), sizeof(char *));
	if (dst == NULL)
		return (NULL);
	if (ft_split_word(dst, c, s))
		return (ft_free__char_matrix(dst));
	return (dst);
}

static int	ft_make_word(char **dst, char const *s, size_t size, size_t i)
{
	dst[i] = ft_substr(s, 0, size);
	if (dst[i] == NULL)
		return (1);
	return (0);
}

static size_t	ft_split_word(char **dst, char c, const char *s)
{
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	start = 0;
	end = 0;
	while (s[end] != '\0')
	{
		if (s[end] != c && (end == 0 || s[end - 1] == c))
			start = end;
		if (s[end] != c && (s[end + 1] == c || s[end + 1] == '\0'))
		{
			if (ft_make_word(dst, s + start, end - start + 1, i) == 1)
				return (1);
			i++;
		}
		end++;
	}
	return (0);
}
