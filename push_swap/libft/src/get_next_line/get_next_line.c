/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:41:21 by euihlee           #+#    #+#             */
/*   Updated: 2023/02/08 17:11:40 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_tab	*table[GNL_BUCKETS];
	t_arr			*next_line;
	char			*string;

	if (fd < 0 || GNL_BUFSIZ < 1)
		return (NULL);
	next_line = init_array(GNL_INIT_CAPACITY);
	if (next_line == NULL)
	{
		flush(fd, table, NULL);
		return (NULL);
	}
	if (!flush(fd, table, next_line))
		return (free_array(next_line));
	while (!seek_eol(next_line) && read_buffer_size(fd, next_line))
		;
	if (next_line->eol < 1 || !cache(fd, table, next_line))
		return (free_array(next_line));
	string = build_string(next_line);
	free_array(next_line);
	if (string)
		return (string);
	flush(fd, table, NULL);
	return (NULL);
}

t_arr	*flush(int fd, t_tab **table, t_arr *array)
{
	t_arr	*flag;
	t_tab	**nodeptr;
	t_tab	*node;

	flag = array;
	nodeptr = table + (fd % GNL_BUCKETS);
	while (*nodeptr)
	{
		node = *nodeptr;
		if (node->fd != fd)
		{
			nodeptr = &(node->next);
			continue ;
		}
		if (flag && !append_array(array, node->data, node->size))
			flag = NULL;
		*nodeptr = node->next;
		free(node->data);
		free(node);
		break ;
	}
	return (flag);
}

t_arr	*cache(int fd, t_tab **table, t_arr *array)
{
	t_tab	*new_tab;
	char	*new_data;
	size_t	new_size;

	new_size = array->size - array->eol;
	if (new_size == 0)
		return (array);
	new_data = malloc(new_size * sizeof(*new_data));
	if (new_data == NULL)
		return (NULL);
	new_tab = malloc(sizeof(*new_tab));
	if (new_tab == NULL)
	{
		free(new_data);
		return (NULL);
	}
	new_tab->fd = fd;
	new_tab->size = new_size;
	while (new_size-- > 0)
		new_data[new_size] = array->data[array->eol + new_size];
	new_tab->data = new_data;
	new_tab->next = table[fd % GNL_BUCKETS];
	table[fd % GNL_BUCKETS] = new_tab;
	return (array);
}

char	*build_string(t_arr *array)
{
	char	*string;
	size_t	i;

	string = malloc((array->eol + 1) * sizeof(*string));
	if (string == NULL)
		return (NULL);
	string[array->eol] = '\0';
	i = 0;
	while (i < array->eol)
	{
		string[i] = array->data[i];
		i++;
	}
	return (string);
}

void	*free_array(t_arr *array)
{
	if (array == NULL)
		return (NULL);
	free(array->data);
	free(array);
	return (NULL);
}
