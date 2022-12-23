/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:55:43 by euihlee           #+#    #+#             */
/*   Updated: 2022/11/28 12:09:17 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	write_digits(unsigned int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;

	un = (unsigned int) n;
	if (n < 0)
	{
		un = 0u - un;
		write(fd, "-", 1);
	}
	write_digits(un, fd);
}

static void	write_digits(unsigned int n, int fd)
{
	char	digit;

	digit = (n % 10) + '0';
	if (n < 10)
	{
		write(fd, &digit, 1);
		return ;
	}
	write_digits(n / 10, fd);
	write(fd, &digit, 1);
}
