/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:17:43 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/07 12:29:04 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The ft_lstclear() function clears the list.
 * @param lst The list to be cleared.
 * @param del Function to delete the content of an element.
 */
void	ft_lstclear(t_node **lst, void (*del)(void*))
{
	t_node	*next;
	t_node	*start;

	if (lst == NULL)
		return ;
	start = *lst;
	while (*lst != NULL)
	{
		next = (*lst)->next;
		del(*lst);
		*lst = next;
		if (*lst == start)
			break ;
	}
	*lst = NULL;
}
