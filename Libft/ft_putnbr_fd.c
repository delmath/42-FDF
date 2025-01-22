/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:37:41 by madelvin          #+#    #+#             */
/*   Updated: 2024/11/14 21:59:23 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_fd_r(long nbr, int fd);

/**
 * @brief The ft_putnbr_fd() function outputs the integer 'n' to the given 
 * file descriptor 'fd'.
 * @param n The integer to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = nbr * -1;
	}
	ft_putnbr_fd_r(nbr, fd);
}

static void	ft_putnbr_fd_r(long nbr, int fd)
{
	if (nbr >= 10)
		ft_putnbr_fd_r(nbr / 10, fd);
	ft_putchar_fd(nbr % 10 + '0', fd);
}
