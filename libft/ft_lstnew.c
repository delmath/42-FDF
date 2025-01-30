/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:44:58 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/07 12:22:39 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * @brief The ft_lstnew() function creates a new list element.
 * @param content The content to create the new element with.
 * @return A new list element, or NULL if the allocation fails.
 */
t_node	*ft_lstnew(int value, t_node *prev)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (new == NULL)
		return (NULL);
	new->value = value;
	new->next = NULL;
	new->prev = prev;
	return (new);
}
