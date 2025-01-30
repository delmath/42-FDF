/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:16:53 by madelvin          #+#    #+#             */
/*   Updated: 2024/11/12 18:44:17 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** 
 * @brief The ft_isprint() function tests for any printing character, 
 * including space (` ').
 * @param c The character to test.
 * @return The isprint() function returns zero if the character tests false 
 * and returns non-zero if the character tests true.
*/
int	ft_isprint(int c)
{
	return ((c >= 32 && c <= 126));
}
