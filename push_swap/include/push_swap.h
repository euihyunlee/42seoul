/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:33:15 by euihlee           #+#    #+#             */
/*   Updated: 2023/02/28 06:17:07 by euihlee          ###   ########.fr       */
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
# define MEM_ERROR (-1)
# define INVALID_ARGS (-2)

# define PA "pa\n"
# define PB "pb\n"
# define RA "ra\n"
# define RB "rb\n"
# define RRA "rra\n"
# define RRB "rrb\n"

int		swap(char *str, t_dllist *list);
int		push(char *str, t_dllist *a, t_dllist *b, int count);
int		rotate(char *str, t_dllist *list, int count);
int		reverse_rotate(char *str, t_dllist *list, int count);

int		push_args(t_dllist *list, char *str);

void	push_swap_small(t_dllist *a, t_dllist *b, int size);
void	push_swap(t_dllist *a, t_dllist *b, int size);

#endif
