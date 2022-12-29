/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:35:43 by euihlee           #+#    #+#             */
/*   Updated: 2022/12/29 19:22:03 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	return (write(STDOUT, &c, 1));
}

int	print_string(char *string)
{
	size_t	len;

	if (string == NULL)
		return (write(STDOUT, "(null)", 6));
	len = 0;
	while (string[len])
		len++;
	return (write(STDOUT, string, len));
}
