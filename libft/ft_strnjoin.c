/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:39:33 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/06 14:43:22 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_strnjoin(char **s1, const char *s2, size_t n)
{
	size_t	s1_len;
	char	*output;
	size_t	i;

	if (!s1 || !s2)
		return ;
	s1_len = ft_strlen_s(*s1);
	output = malloc(s1_len + n + 1);
	if (!output)
		return (ft_free_null(s1));
	i = 0;
	if (*s1)
	{
		while ((*s1)[i])
		{
			output[i] = (*s1)[i];
			i++;
		}
	}
	while (*s2 && i - s1_len < n)
		output[i++] = *s2++;
	output[i] = '\0';
	if (*s1 != NULL)
		free(*s1);
	*s1 = output;
}
