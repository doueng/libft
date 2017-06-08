/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 11:48:35 by douglas           #+#    #+#             */
/*   Updated: 2017/06/07 12:11:20 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*precision(char *nbr, t_id *id)
{
	size_t	p_len;
	size_t	nbr_len;
	char	*result;

	if (!nbr)
		exit(-1);
	if (id->precision == 0 && *nbr == '0')
		return (ft_strnew(0));
	p_len = id->precision;
	nbr_len = ft_strlen(nbr);
	if (p_len > nbr_len)
	{
		if (!(result = ft_strnew(p_len)))
			exit(-1);
		ft_memset(result, '0', p_len);
		ft_memmove(result + p_len - nbr_len, nbr, nbr_len);
	}
	else
		result = ft_strdup(nbr);
	return (result);
}

static char		*get_sign(int minus, t_id *id)
{
	char specifier;

	specifier = id->specifier;
	if (specifier == 'x' || specifier == 'p')
		return ("0x");
	else if (specifier == 'X')
		return ("0X");
	else if (specifier == 'o' || specifier == 'O')
		return ("0");
	else if (minus)
		return ("-");
	else if (id->plus == '+')
		return ("+");
	else
		return ("");
}

static	int		sign_adder(t_id *id, int minus, char *nbr, int len)
{
	char *joined;

	if ((!ft_only_char(nbr, '0') || *nbr != '0'
						|| id->plus || id->specifier == 'p' || minus)
						&& (!ft_strchr("oOxX", id->specifier)
						|| (id->hash &&
						(*nbr || ft_strchr("oO", id->specifier)))))
	{
		if ((id->plus || id->hash || minus) && id->zero == '0')
		{
			len += ft_putstr(get_sign(minus, id));
			len += ft_putstrfree(padding(nbr, id, len));
		}
		else
		{
			joined = ft_strjoin(get_sign(minus, id), nbr);
			len += ft_putstrfree(padding(joined, id, len));
			free(joined);
		}
	}
	else
		len += ft_putstrfree(padding(nbr, id, len));
	return (len);
}

int				ft_print_nbr(char *nbr, t_id *id)
{
	int			len;
	int			minus;
	char		*prec;

	if (!nbr)
		exit(-1);
	if ((minus = (*nbr == '-') ? 1 : 0))
		nbr++;
	prec = NULL;
	if (id->has_precision)
	{
		if (!(prec = precision(nbr, id)))
			exit(-1);
		nbr = prec;
		id->zero = ' ';
	}
	len = 0;
	if (id->space && ft_strchr("di", id->specifier) && !minus && !id->plus)
		len = write(1, " ", 1);
	len = sign_adder(id, minus, nbr, len);
	free(prec);
	return (len);
}

int				ft_base(size_t n, char c, t_id *id)
{
	char	*base;
	char	*tmp;
	int		len;

	if (c == 'x' || c == 'p')
		base = BASE_16;
	else if (c == 'X')
		base = BASE_16_U;
	else
		base = BASE_8;
	tmp = ft_itoa_base(n, base);
	len = ft_print_nbr(tmp, id);
	if (tmp)
		free(tmp);
	return (len);
}
