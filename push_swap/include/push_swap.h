/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:33:15 by euihlee           #+#    #+#             */
/*   Updated: 2023/02/12 14:13:38 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# include "libft.h"
# include "dllist.h"

# define ERROR_MSG "Error"
# define NO_PARAMS (-1)
# define MEM_ERROR (-1)
# define INVALID_ARGS (-1)

int		push_swap(t_dllist *a, t_dllist *b, int size);
int		push_args(t_dllist *list, char *str);

t_bool	valid_trail(char *endptr);
t_bool	valid_arg(char *endptr, long l);

#endif
