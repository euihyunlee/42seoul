/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:33:15 by euihlee           #+#    #+#             */
/*   Updated: 2023/02/06 13:48:06 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# include "dllist.h"

# define ERROR_MSG "Error"
# define NO_PARAMS (0)
# define MEM_ERROR (0)

int	push_swap(t_dllist *a, t_dllist *b);

#endif
