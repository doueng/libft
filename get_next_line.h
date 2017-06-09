/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 14:42:41 by dengstra          #+#    #+#             */
/*   Updated: 2017/06/02 14:07:46 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct		s_node
{
	char			value;
	struct s_node	*next;
}					t_node;

typedef struct		s_queue
{
	int				fd;
	t_node			*head;
	t_node			*tail;
	struct s_queue	*next;
}					t_queue;

int					get_next_line(const int fd, char **line);

#endif
