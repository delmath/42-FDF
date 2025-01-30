/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:08:22 by madelvin          #+#    #+#             */
/*   Updated: 2024/11/11 16:09:50 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

/**
 * @brief The ft_memcmp() function compares the first n bytes
 * (each interpreted as uint8_t) of the memory areas s1 and s2.
 * @param s1 The first memory area to compare
 * @param s2 The second memory area to compare
 * @param n The number of bytes to compare
 * @return The  ft_memcmp() function returns an integer less than,
 * equal to, or greater than zero if the first n bytes of s1 is found,
 * respectively, to be less than, to match, or be greater than the
 * first n bytes of s2.
 * 
 * For a nonzero return value, the sign is determined by the sign of
 * the difference between the first pair of bytes (interpreted as uint8_t)
 * that differ in s1 and s2.
 * 
 * If n is zero, the return value is zero.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((uint8_t *)s1)[i] != ((uint8_t *)s2)[i])
			return (((uint8_t *)s1)[i] - ((uint8_t *)s2)[i]);
		i++;
	}
	return (0);
}
