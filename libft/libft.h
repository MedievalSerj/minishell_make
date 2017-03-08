/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 13:18:58 by sladonia          #+#    #+#             */
/*   Updated: 2016/12/02 13:19:02 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIBFT_H
# define __LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <wchar.h>
# include <fcntl.h>
# include <dirent.h>
# define BUFF_SIZE 128

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
typedef struct		s_lst
{
	void			*content;
	struct s_lst	*next;
}					t_lst;
typedef struct		s_d_dec
{
	void			*data;
	char			*size;
	char			type;
	int				width;
	int				precision;
	int				precision_flag;
	int				sign;
	int				plus;
	int				minus;
	int				zero;
	int				space;
	int				pound;
}					t_d_dec;
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little, \
					size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					get_next_line(const int fd, char **line);
char				*ft_char_n_str(char c, size_t n);
void				ft_put_str_w(char *s, size_t w, char c);
char				*ft_str_tolower(char *s);
int					ft_printf(const char *format, ...);
char				*ft_str_append(char *s, char c);
void				select_f(t_d_dec *val, int *n);
void				d_signed_decimal(t_d_dec *val, int *n);
void				u_unsigned_decimal(t_d_dec *val, int *n);
void				x_hex(t_d_dec *val, int *n);
void				persent(t_d_dec *val, int *n);
void				c_char(t_d_dec *val, int *n);
void				wc_char(t_d_dec *val, int *n);
void				s_string(t_d_dec *val, int *n);
void				ws_string(t_d_dec *val, int *n);
void				p_hex(t_d_dec *val, int *n);
char				*ft_str_long(long long n, char *tmp);
char				*ft_str_append_unsafe(char *s, char c);
const char			*define_t(const char *s, char *type);
void				define_description(const char *sring, char **desc);
void				validate_size(char **desc);
t_d_dec				*fill_t_d_desc(char type, char **desc, va_list args,
							t_d_dec *val);
char				*ft_str_u_long(unsigned long long n, char *tmp);
char				*ft_str_hex(unsigned long long n, int h, int base);
void				o_octal(t_d_dec *val, int *n);
t_d_dec				*init_t_d_dec(void);
char				*encode_c(wchar_t n, int *k, int p);
char				*ft_str_j(char *s1, char *s2, int fr);
char				*buffered_reader(int fd);
char				*resize_buf(char *buf, int *n);
int					ft_readline(int fd, char **line);
int					get_num_str(char *arg);
t_list				*ft_list_dir(char *path);
t_lst				*l_add(t_lst *head, void *content);
void				l_add_last(t_lst **head, void *content);
t_lst				*l_get_nth(t_lst *head, int n);
void				l_iter(t_lst *head, void (*f)(t_lst *elem));
void				l_del_nth(t_lst **head, int n, void (*f)(void *content));
void				l_del_all(t_lst **head, void (*f)(void *content));
void				l_del(t_lst **head, t_lst *this, void (*f)(void *content));
int					l_count(t_lst *head);
void				ft_clear_arr(char ***s);
int					ft_char_last_n(char *s, char c);
char				*ft_reasign(char *this, char *new, int free_new);
char				**ft_lst_to_arr(t_lst *head);
#endif
