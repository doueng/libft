/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 11:42:19 by dengstra          #+#    #+#             */
/*   Updated: 2017/06/02 14:11:07 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_enqueue(t_queue *q)
{
	t_node *node;

	if (!(node = (t_node*)malloc(sizeof(t_node))))
		return (-1);
	node->next = NULL;
	if (!q->head)
	{
		q->tail = node;
		q->head = node;
	}
	else
	{
		q->tail->next = node;
		q->tail = node;
	}
	return (1);
}

static int		read_and_enqueue(int fd, t_queue *q)
{
	char	*buffer;
	int		i;
	int		read_return;
	int		new_line;

	new_line = 0;
	read_return = 1;
	while (!new_line && read_return > 0)
	{
		if (!(buffer = ft_strnew(BUFF_SIZE)))
			return (-1);
		read_return = read(fd, buffer, BUFF_SIZE);
		i = 0;
		while (read_return > 0 && buffer[i])
		{
			if (-1 == ft_enqueue(q))
				return (-1);
			q->tail->value = buffer[i++];
			if (buffer[i] == '\n')
				new_line = 1;
		}
		free(buffer);
	}
	return (read_return);
}

static char		dequeue(t_queue *q)
{
	t_node	*tmp;
	char	c;

	if (!q->head)
		return ('\0');
	c = q->head->value;
	tmp = q->head;
	q->head = q->head->next;
	free(tmp);
	return (c);
}

static int		add_line_and_dequeue(t_queue *q, char **line)
{
	int		len;
	int		ii;
	t_node	*i_node;

	len = 0;
	i_node = q->head;
	while (i_node && i_node->value != '\n')
	{
		i_node = i_node->next;
		len++;
	}
	if (!(line[0] = ft_strnew(len)))
		return (-1);
	ii = 0;
	while (len--)
		line[0][ii++] = dequeue(q);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_queue	*start_q;
	t_queue			*current_q;
	int				read_return;

	current_q = start_q;
	while (current_q && current_q->fd != fd)
		current_q = current_q->next;
	if (!current_q)
	{
		if (!(current_q = (t_queue*)ft_memalloc(sizeof(t_queue))))
			return (-1);
		current_q->fd = fd;
		current_q->head = NULL;
		current_q->next = start_q;
		start_q = current_q;
	}
	if (0 > (read_return = read_and_enqueue(fd, current_q)))
		return (-1);
	if (-1 == add_line_and_dequeue(current_q, line))
		return (-1);
	if (!dequeue(current_q) && !line[0][0])
		return (0);
	return (1);
}
