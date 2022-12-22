/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:49:06 by euihlee           #+#    #+#             */
/*   Updated: 2022/12/22 19:49:13 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_tab	*table[BUCKETS];
	t_arr			*next_line;
	char			*string;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	next_line = init_arr(INIT_CAPACITY);
	if (next_line == NULL)
		return (cleanup(table, fd));
	if (!flush(fd, table, next_line))
		return (free_array(next_line));
	while (!seek_eol(next_line) && read_buffer_size(fd, next_line))
		;
	if (next_line->eol < 1)
		return (free_array(next_line));
	if (next_line->eol < next_line->size && !cache(fd, table, next_line))
		return (free_array(next_line));
	string = build_string(next_line);
	if (string == NULL)
	{
		free_array(next_line);
		return (cleanup(table, fd));
	}
	return (string);
}

t_arr	*flush(int fd, t_tab **table, t_arr *array)
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
		if (!append_array(array, tmp->array->data, tmp->array->size))
		{
			*head = tmp->next;
			free_array(tmp->array);
			free(tmp);
			return (NULL);
		}
		*head = tmp->next;
		free_array(tmp->array);
		free(tmp);
		return (array);
	}
	return (array);
}

t_arr	*cache(int fd, t_tab **table, t_arr *array)
{
	t_tab	*new_tab;
	t_arr	*new_array;
	size_t	new_capacity;

	new_capacity = array->size - array->eol;
	new_array = init_arr(new_capacity);
	if (new_array == NULL)
		return (NULL);
	if (!append_array(new_array, array->data + array->eol, new_capacity))
	{
		free_array(new_array);
		return (NULL);
	}
	new_tab = malloc(sizeof(*new_tab));
	if (new_tab == NULL)
	{
		free_array(new_array);
		return (NULL);
	}
	new_tab->fd = fd;
	new_tab->array = new_array;
	new_tab->next = table[fd % BUCKETS];
	table[fd % BUCKETS] = new_tab;
	return (array);
}

char	*build_string(t_arr *array)
{
	char	*next_line;

	next_line = malloc((array->eol + 1) * sizeof(*next_line));
	if (next_line == NULL)
		return (NULL);
	next_line[array->eol] = '\0';
	while (array->eol-- > 0)
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

void	*cleanup(t_tab **table, int fd)
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
		*head = tmp->next;
		free_array(tmp->array);
		free(tmp);
		break ;
	}
	return (NULL);
}
