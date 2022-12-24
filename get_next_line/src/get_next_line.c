/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:41:21 by euihlee           #+#    #+#             */
/*   Updated: 2022/12/17 20:24:24 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_tab	*table[BUCKETS];
	t_arr			*next_line;
	char			*string;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	next_line = init_array(INIT_CAPACITY);
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
	if (string == NULL)
	{
		flush(fd, table, NULL);
		return (free_array(next_line));
	}
	return (string);
}

// TODO: remove tmp
t_arr	*flush(int fd, t_tab **table, t_arr *array)
{
	t_arr	*flag;
	t_tab	**head;
	t_tab	*tmp;

	flag = array;
	head = table + (fd % BUCKETS);
	while (*head)
	{
		tmp = *head;
		if (tmp->fd != fd)
		{
			head = &(tmp->next);
			continue ;
		}
		if (flag && !append_array(array, tmp->data, tmp->size))
			flag = NULL;
		*head = tmp->next;
		free(tmp->data);
		free(tmp);
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
	new_tab->data = new_data;
	new_tab->size = new_size;
	new_tab->next = table[fd % BUCKETS];
	table[fd % BUCKETS] = new_tab;
	while (new_size-- > 0)
		new_data[new_size] = array->data[array->eol + new_size];
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
	if (array == NULL)
		return (NULL);
	free(array->data);
	free(array);
	return (NULL);

}
