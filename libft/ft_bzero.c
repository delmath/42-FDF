/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:57:17 by madelvin          #+#    #+#             */
/*   Updated: 2024/11/13 20:21:19 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The  ft_bzero() function erases the data in the n
 * bytes of the memory starting at the location pointed
 * to by s, by writing zeros (bytes containing '\0') to that area.
 * @param s The memory to zero.
 * @param n The number of bytes to zero.
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
