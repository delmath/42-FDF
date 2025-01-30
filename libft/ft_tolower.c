/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:26:57 by madelvin          #+#    #+#             */
/*   Updated: 2024/11/12 18:44:54 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The ft_tolower() function converts a uppercase letter to lowercase,
 * if possible owtherwise returns c
 * @param c The character to convert
 * @return The lowercase letter
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + SPACE_LOWER_UPPER);
	return (c);
}
