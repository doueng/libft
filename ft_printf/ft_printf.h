/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 13:20:35 by dengstra          #+#    #+#             */
/*   Updated: 2017/06/08 17:35:40 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../libft.h"

# define BASE_16_U	"0123456789ABCDEF"
# define BASE_16	"0123456789abcdef"
# define BASE_10	"0123456789"
# define BASE_8		"01234567"

typedef struct		s_id
{
	char			hash;
	char			zero;
	char			plus;
	char			minus;
	char			space;
	size_t			width;
	size_t			precision;
	int				has_precision;
	char			specifier;
	struct s_id		*next;
	enum {
		none,
		h,
		hh,
		l,
		ll,
		j,
		z
	}				e_length;
}					t_id;

t_id				*ft_get_flags(char *format);
int					ft_printf(const char *format, ...);
int					ft_printer(char *format, t_id *id, va_list ap);
int					ft_base(size_t n, char c, t_id *id);
char				ft_is_specifier(char c);
int					ft_print_nbr(char *nbr, t_id *id);
int					ft_printstr(char *str, t_id *id);
size_t				ft_putwstr(wchar_t *str, t_id *id);
char				*ft_putwchar(wchar_t c, t_id *id);
int					ft_putbinary(size_t c);
size_t				length_converter(va_list ap, int len);
size_t				ulength_converter(va_list ap, int len);
char				*padding(char *str, t_id *id, size_t sign_len);
int					ft_putzerochar(t_id *id);
void				input_checker(t_id *id);
char				*one_byte(int c);
char				*two_byte(int c);
char				*three_byte(int c);
char				*four_byte(int c);

#endif
