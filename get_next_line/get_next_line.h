/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:36:43 by euihlee           #+#    #+#             */
/*   Updated: 2022/12/12 13:48:34 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define INIT_CAPACITY 512
# define BUCKETS 256

# define FALSE 0
# define TRUE (!0)

typedef int	t_bool;

typedef struct s_array
{
	char	*data;
	ssize_t	capacity;
	ssize_t	size;
	ssize_t	eol;
}			t_array;

typedef struct s_node
{
	int				fd;
	t_array			*array;
	struct s_node	*next;
}					t_node;

char	*get_next_line(int fd);
void	flush(int fd, t_node **table, t_array *array);
void	cache(int fd, t_node **table, t_array *array);
char	*build_string(t_array *array);
void	*free_array(t_array *array);

t_array	*init_array(ssize_t capacity);
t_array	*append_array(t_array *array, char *buffer, ssize_t bytes);
t_array	*resize_array(t_array *array);
t_bool	seek_eol(t_array *array);
t_bool	read_buffer_size(int fd, t_array *array);

#endif
