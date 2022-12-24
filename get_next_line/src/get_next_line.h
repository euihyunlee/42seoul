/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:36:43 by euihlee           #+#    #+#             */
/*   Updated: 2022/12/13 15:45:23 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# if BUFFER_SIZE < 1024
#  define INIT_CAPACITY 1024
# else
#  define INIT_CAPACITY BUFFER_SIZE
# endif

# define BUCKETS 128

# define FALSE 0
# define TRUE (!0)

typedef int	t_bool;

typedef struct s_arr
{
	char	*data;
	size_t	capacity;
	size_t	size;
	size_t	eol;
}			t_arr;

typedef struct s_tab
{
	int				fd;
	size_t			size;
	char			*data;
	struct s_tab	*next;
}					t_tab;

char	*get_next_line(int fd);
t_arr	*flush(int fd, t_tab **table, t_arr *array);
t_arr	*cache(int fd, t_tab **table, t_arr *array);
char	*build_string(t_arr *array);
void	*free_array(t_arr *array);

t_arr	*init_array(size_t capacity);
t_arr	*append_array(t_arr *array, char *buffer, size_t bytes);
t_arr	*resize_array(t_arr *array);
t_bool	seek_eol(t_arr *array);
t_bool	read_buffer_size(int fd, t_arr *array);

#endif
