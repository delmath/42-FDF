/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:36:53 by madelvin          #+#    #+#             */
/*   Updated: 2024/11/15 16:57:39 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>
#include <stdlib.h>

/**
 * @brief The  calloc() function allocates memory for
 * an array of nmemb elements of size bytes each and
 * returns a pointer to the allocated memory.  The memory
 * is set to zero.  If nmemb or size is 0, then calloc()
 * returns either NULL.
 * @param nmemb The number of elements to allocate.
 * @param size The size of each element.
 * @return The ft_calloc() functions return a pointer
 * to the allocated memory, which is suitably aligned
 * for any built-in type.  On error, these functions
 * return NULL.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size == 0 || nmemb == 0)
		return (malloc(0));
	if (size > SIZE_MAX / nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
