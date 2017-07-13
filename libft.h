/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:50:53 by dengstra          #+#    #+#             */
/*   Updated: 2017/07/13 14:37:26 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"
# include "ft_printf/ft_printf.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648

# define NORMAL_COLOR "\x1B[0m"
# define RED_COLOR "\x1B[31m"
# define GREEN_COLOR "\x1B[32m"
# define YELLOW_COLOR "\x1B[33m"
# define BLUE_COLOR "\x1B[34m"
# define MAGENTA_COLOR "\x1B[35m"
# define CYAN_COLOR "\x1B[36m"
# define WHITE_COLOR "\x1B[37m"

void				ft_print_color(char *str, char *color);
void				ft_print_till(char *str, char c);
char				*ft_strjoinfree(int free1, char *s1, int free2, char *s2);
void				*ft_memdup(void *mem, size_t size);
int					ft_split_len(char **split);
void				ft_free_split(char **split);
char				*ft_strcpytill(char *str, char c);
int					ft_is_int(char *str);
int					ft_only_char(char *str, char c);
char				*ft_strndup(const char *str, size_t len);
void				*ft_arrayrev(void *a, size_t size, size_t len);
char				*ft_itoa_base(size_t value, char *base);
void				ft_swap(void *a, void *b, int size);
void				ft_sort_integer_table(int *tab, int size);
int					ft_sqrt(int nb);
void				ft_foreach(int *tab, int length, void (*f)(int));
char				*ft_strrev(char *str);
int					ft_atoi(const char *str);
int					ft_atoi_base(char *str, char *base);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(long long n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_print_memory(void *addr, unsigned int size);
int					ft_putchar(int c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int nb);
void				ft_putnbr_base(int nbr, char *base);
void				ft_putnbr_fd(int nb, int fd);
int					ft_putstr(const char *str);
int					ft_putstrfree(char *str);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr_non_printable(char *str);
char				*ft_strcat(char *dest, char *src);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *src);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *dest, char *src, int nb);
int					ft_strncmp(const char *s1, const char *s2, unsigned int n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *big,
								const char *little, size_t len);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}					t_btree;

typedef struct		s_nth
{
	int				nth;
	t_btree			*node;
}					t_nth;

t_nth				*btree_get_nth(t_btree *root, t_nth *nth);
int					btree_num_nodes(t_btree *root);
void				btree_free(t_btree **root, void (*free_item)(void*));
void				btree_apply_infix(t_btree *root, void (*applyf)(void *));
void				btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void				btree_apply_suffix(t_btree *root, void (*applyf)(void *));
t_btree				*btree_create_node(void *item);
void				btree_insert(t_btree **root, void *item,
									int (*cmpf)(void *, void *));
void				*btree_search_item(t_btree *root, void *data_ref,
									void *res, int (*cmpf)(void *, void *));
void				ft_free_list(t_list *start);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstadd_rev(t_list **start, t_list *new);
#endif
