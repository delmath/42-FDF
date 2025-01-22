/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:35:34 by madelvin          #+#    #+#             */
/*   Updated: 2024/12/18 16:49:19 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(char const *s, char c)
{
	size_t	word_c;
	int		start;

	word_c = 0;
	start = 0;
	while (*s)
	{
		if (*s == c && start)
			start = 0;
		else if (*s != c && !start)
		{
			start = 1;
			word_c++;
		}
		s++;
	}
	return (word_c);
}
