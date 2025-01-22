/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:55:12 by madelvin          #+#    #+#             */
/*   Updated: 2024/11/10 19:57:31 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief the ft_isdigit() function tests for any character for which
 * isdigit is true.
 * @param c The character to test.
 * @return 1 if c is a digit, 0 otherwise.
 */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
