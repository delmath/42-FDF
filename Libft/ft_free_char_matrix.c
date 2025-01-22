/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_char_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:56:02 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/22 19:40:57 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	**ft_free_char_matrix(char **dst)
{
	size_t	i;

	if (!dst)
		return (NULL);
	i = 0;
	while (dst[i] != NULL)
		free(dst[i++]);
	free(dst);
	return (NULL);
}
