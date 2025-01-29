/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:28:23 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/28 20:21:09 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	select_value_sign(int x, int value)
{
	if (x > 0)
		return (value);
	return (-value);
}
