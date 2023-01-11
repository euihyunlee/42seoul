/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:35:43 by euihlee           #+#    #+#             */
/*   Updated: 2022/12/29 19:22:03 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_char(char c)
{
	return (write(STDOUT, &c, 1));
}

int	print_str(char *str)
{
	if (str == NULL)
		return (write(STDOUT, NULL_MSG, ft_strlen(NULL_MSG)));
	return (write(STDOUT, str, ft_strlen(str)));
}
