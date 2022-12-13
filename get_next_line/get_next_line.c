/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:41:21 by euihlee           #+#    #+#             */
/*   Updated: 2022/12/13 13:11:33 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_tab	*table[BUCKETS];
	t_arr			*next_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	next_line = init_arr(INIT_CAPACITY);
	if (next_line == NULL)
		return (NULL);
	flush(fd, table, next_line);
	while (!seek_eol(next_line) && read_buffer_size(fd, next_line))
		;
	if (next_line->eol < 1)
		return (free_array(next_line));
	if (next_line->eol < next_line->size)
		cache(fd, table, next_line);
	return (build_string(next_line));
}

void	flush(int fd, t_tab **table, t_arr *array)
{
	t_tab	**head;
	t_tab	*tmp;

	head = table + (fd % BUCKETS);
	while (*head)
	{
		tmp = *head;
		if (tmp->fd != fd)
		{
			head = &(tmp->next);
			continue ;
		}
		append_array(array, tmp->array->data, tmp->array->size);
		*head = tmp->next;
		free(tmp->array->data);
		free(tmp->array);
		free(tmp);
		return ;
	}
}

void	cache(int fd, t_tab **table, t_arr *array)
{
	t_tab	*new_tab;
	t_arr	*new_array;
	ssize_t	new_capacity;

	new_capacity = array->size - array->eol;
	new_array = init_arr(new_capacity);
	if (new_array == NULL)
		return ;
	append_array(new_array, array->data + array->eol, new_capacity);
	new_tab = malloc(sizeof(*new_tab));
	if (new_tab == NULL)
	{
		free_array(new_array);
		return ;
	}
	new_tab->fd = fd;
	new_tab->array = new_array;
	new_tab->next = table[fd % BUCKETS];
	table[fd % BUCKETS] = new_tab;
}

char	*build_string(t_arr *array)
{
	char	*next_line;

	next_line = malloc((array->eol + 1) * sizeof(*next_line));
	if (next_line == NULL)
		return (free_array(array));
	next_line[array->eol] = '\0';
	while (--array->eol >= 0)
		next_line[array->eol] = array->data[array->eol];
	free_array(array);
	return (next_line);
}

void	*free_array(t_arr *array)
{
	free(array->data);
	free(array);
	return (NULL);
}
