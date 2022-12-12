/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:41:21 by euihlee           #+#    #+#             */
/*   Updated: 2022/12/12 13:49:18 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_node	*table[BUCKETS];
	t_array			*next_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	next_line = init_array(INIT_CAPACITY);
	if (next_line == NULL)
		return (NULL);
	flush(fd, table, next_line);
	while (!seek_eol(next_line) && read_buffer_size(fd, next_line))
		;
	if (next_line->eol < 0)
		return (free_array(next_line));
	if (next_line->eol < next_line->size)
		cache(fd, table, next_line);
	return (build_string(next_line));
}

void	flush(int fd, t_node **table, t_array *array)
{
	t_node	**head;
	t_node	*tmp;

	head = table + (fd % BUCKETS);
	while (*head)
	{
		tmp = *head;
		if (tmp->fd == fd)
		{
			append_array(array, tmp->array->data, tmp->array->size);
			*head = tmp->next;
			free(tmp->array->data);
			free(tmp->array);
			free(tmp);
			return ;
		}
		head = &(tmp->next);
	}
}

void	cache(int fd, t_node **table, t_array *array)
{
	t_node	*new_node;
	t_array	*new_array;
	ssize_t	new_capacity;

	new_capacity = array->size - array->eol - 1;
	new_array = init_array(new_capacity);
	if (new_array == NULL)
		return ;
	append_array(new_array, array->data + array->eol + 1, new_capacity);
	new_node = malloc(sizeof(*new_node));
	if (new_node == NULL)
		return ;
	new_node->fd = fd;
	new_node->array = new_array;
	new_node->next = table[fd % BUCKETS];
	table[fd % BUCKETS] = new_node;
}

char	*build_string(t_array *array)
{
	char	*next_line;
	ssize_t	i;

	if (array->eol == 0)
		return (free_array(array));
	next_line = malloc((array->eol + 1) * sizeof(*next_line));
	if (next_line == NULL)
		return (free_array(array));
	next_line[array->eol] = '\0';
	i = 0;
	while (i < array->eol)
	{
		next_line[i] = array->data[i];
		i++;
	}
	free_array(array);
	return (next_line);
}

void	*free_array(t_array *array)
{
	free(array->data);
	free(array);
	return (NULL);
}
