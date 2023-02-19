/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:33:15 by euihlee           #+#    #+#             */
/*   Updated: 2023/02/19 11:01:43 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# include "libft.h"
# include "dllist.h"
# include "ft_printf.h"

# define ERROR_MSG "Error"
# define NO_PARAMS (-1)
# define MEM_ERROR (-1)
# define INVALID_ARGS (-1)

int		swap(t_dllist *list);
int		push(t_dllist *a, t_dllist *b, int count);
int		rotate(t_dllist *list, int count);
int		reverse_rotate(t_dllist *list, int count);

int		push_args(t_dllist *list, char *str);

void	push_swap(t_dllist *a, t_dllist *b, int size);

#endif
