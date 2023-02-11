/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:43:52 by euihlee           #+#    #+#             */
/*   Updated: 2023/02/08 17:10:53 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_arr	*init_array(size_t capacity)
{
	t_arr	*new;

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

t_arr	*append_array(t_arr *array, char *buffer, size_t bytes)
{
	char	*end;

	if (bytes == 0)
		return (NULL);
	if (array->size > SIZE_MAX - bytes)
		return (NULL);
	while (array->size + bytes > array->capacity)
	{
		if (!resize_array(array))
			return (NULL);
	}
	end = array->data + array->size;
	array->size += bytes;
	while (bytes-- > 0)
		*end++ = *buffer++;
	return (array);
}

t_arr	*resize_array(t_arr *array)
{
	char	*new;
	size_t	i;

	if (array->capacity > SIZE_MAX / 2)
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

t_bool	seek_eol(t_arr *array)
{
	size_t	offset;

	offset = 0;
	if (array->size > GNL_BUFSIZ)
		offset = array->size - GNL_BUFSIZ;
	while (offset < array->size)
	{
		if (array->data[offset] == '\n')
		{
			array->eol = ++offset;
			return (TRUE);
		}
		offset++;
	}
	return (FALSE);
}

t_bool	read_buffer_size(int fd, t_arr *array)
{
	char	buffer[GNL_BUFSIZ];
	ssize_t	bytes;

	bytes = read(fd, buffer, GNL_BUFSIZ);
	if (bytes == 0)
	{
		array->eol = array->size;
		return (FALSE);
	}
	if (bytes < 0 || !append_array(array, buffer, bytes))
	{
		array->eol = 0;
		return (FALSE);
	}
	return (TRUE);
}
