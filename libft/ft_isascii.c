/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:07:02 by madelvin          #+#    #+#             */
/*   Updated: 2024/11/08 13:52:23 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief The ft_isascii() function check if a character is an ASCII character
 * @param c The character to check
 * @return 1 if the character is an ASCII character, 0 otherwise
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
