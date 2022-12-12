/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:43:52 by euihlee           #+#    #+#             */
/*   Updated: 2022/12/12 13:44:29 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_array	*init_array(ssize_t capacity)
{
	t_array	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->data = malloc(capacity * sizeof(*new->data));
	if (new->data == NULL)
	{
		free(new);
		return (NULL);
	}
	new->capacity = capacity;
	new->size = 0;
	new->eol = 0;
	return (new);
}

t_array	*append_array(t_array *array, char *buffer, ssize_t bytes)
{
	char	*tmp;

	if (bytes == 0)
		return (NULL);
	if (array->size > SSIZE_MAX - bytes)
		return (NULL);
	if (array->size + bytes > array->capacity && !resize_array(array))
		return (NULL);
	tmp = array->data + array->size;
	array->size += bytes;
	while (bytes-- > 0)
		*tmp++ = *buffer++;
	return (array);
}

t_array	*resize_array(t_array *array)
{
	char	*new;
	ssize_t	i;

	if (array->capacity > SSIZE_MAX / 2)
		return (NULL);
	array->capacity *= 2;
	new = malloc(array->capacity * sizeof(*new));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < array->size)
	{
		new[i] = array->data[i];
		i++;
	}
	free(array->data);
	array->data = new;
	return (array);
}

t_bool	seek_eol(t_array *array)
{
	ssize_t	offset;

	offset = 0;
	if (array->size > BUFFER_SIZE)
		offset = array->size - BUFFER_SIZE;
	while (offset < array->size)
	{
		if (array->data[offset] == '\n')
		{
			array->eol = offset;
			return (TRUE);
		}
		offset++;
	}
	return (FALSE);
}

t_bool	read_buffer_size(int fd, t_array *array)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes;

	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes < 0)
	{
		array->eol = -1;
		return (FALSE);
	}
	append_array(array, buffer, bytes);
	if (bytes != BUFFER_SIZE)
	{
		array->eol = array->size - 1;
		return (FALSE);
	}
	return (TRUE);
}
