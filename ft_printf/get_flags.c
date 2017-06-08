/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 22:27:28 by douglas           #+#    #+#             */
/*   Updated: 2017/06/03 18:34:11 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_length(char *format, t_id **id)
{
	if (*format == 'l' && *(format + 1) == 'l')
	{
		(*id)->e_length = ll;
		return (format + 2);
	}
	if (*format == 'h' && *(format + 1) == 'h')
	{
		(*id)->e_length = hh;
		return (format + 2);
	}
	(*format == 'l') ? (*id)->e_length = l : 0;
	(*format == 'h') ? (*id)->e_length = h : 0;
	(*format == 'j') ? (*id)->e_length = j : 0;
	(*format == 'z') ? (*id)->e_length = z : 0;
	if ((*id)->e_length)
		return (++format);
	return (format);
}

static char	*get_flags(t_id **id, char *format)
{
	while (ft_strchr("#0- +", *format))
	{
		if (*format == '#')
			(*id)->hash = *format;
		if (*format == '0' && !(*id)->minus)
			(*id)->zero = *format;
		if (*format == '-')
		{
			(*id)->minus = *format;
			(*id)->zero = ' ';
		}
		if (*format == '+')
			(*id)->plus = *format;
		if (*format == ' ')
			(*id)->space = ' ';
		format++;
	}
	return (format);
}

static t_id	*ft_id(char *format)
{
	t_id	*id;

	if (!(id = (t_id*)ft_memalloc(sizeof(t_id))))
		exit(-1);
	id->zero = ' ';
	id->specifier = 0;
	format = get_flags(&id, format);
	if (*format >= '1' && *format <= '9')
	{
		id->width = ft_atoi(format);
		while (ft_isdigit(*format))
			format++;
	}
	if (*format == '.')
	{
		id->precision = ft_atoi(++format);
		id->has_precision = 1;
		while (ft_isdigit(*format))
			format++;
	}
	format = get_length(format, &id);
	id->specifier = *format;
	if (id->specifier == 'p')
		id->hash = '#';
	return (id);
}

static void	add_to_lst(t_id **lst, t_id *id)
{
	t_id	*tmp;

	if (*lst == NULL)
	{
		*lst = id;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = id;
}

t_id		*ft_get_flags(char *format)
{
	t_id	*lst;

	lst = NULL;
	while (*format)
	{
		if (*format == '%')
			add_to_lst(&lst, ft_id(++format));
		format++;
	}
	return (lst);
}
