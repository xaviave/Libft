/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 16:32:24 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/03 18:31:37 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef _LIBFT_H
# define _LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <wctype.h>
# include <stdarg.h>

# define BUFF_SIZE 32


/*
**	libft source
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;


void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strncat(char *dst, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
		size_t n);
int					ft_strcmp(char const *s1, char const *s2);
int					ft_strncmp(char const *s1, char const *s2, size_t n);
int					ft_atoi(const char *nptr);
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
char				*ft_itoa(long n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
size_t				ft_count_words(const char *str, int c);
char				*ft_strdupi(const char *s, int c);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				*ft_strlowcase(char *str);
char				*ft_strupcase(char *str);
char				*ft_strcapitalize(char *str);
char				*ft_strrev(char *str);
int					get_next_line(const int fd, char **line);
char				*ft_itoa_base(long nu, int base);
char				*ft_luitoa_base(unsigned long nu, int base);
size_t				ft_putwchar(wchar_t c);
size_t				ft_putwstr(wchar_t *wstr);
size_t				ft_wstrlen(wchar_t *wstr);
size_t				ft_wcharlen(wchar_t c);
char				*ft_strjoinf1(char *s1, const char *s2);
char				*ft_strjoinf2(const char *s1, char *s2);


/*
 ** ft_printf source
 */

typedef struct		s_opt
{
	int				l;
	int				h;
	int				j;
	int				z;
	int				hashtag;
	int				zero;
	int				less;
	int				plus;
	int				blank;
	int				accurancy;
	int				min;
	int				star;
	int				ok;
	size_t			letter;
	char			point;
	size_t			damn;
}					t_opt;

int					ft_printf(const char *restrict format, ...);
size_t				ft_string(char *format, va_list ap);
size_t				ft_hexap(char *format, va_list ap);
size_t				ft_number(char *format, va_list ap);
size_t				ft_octnumber(char *format, va_list ap);
size_t				ft_unsnumber(char *format, va_list ap);
size_t				ft_hexnumber(char *format, va_list ap);				
size_t				ft_char(char *format, va_list ap);
size_t				ft_modulo(char *format, va_list ap);
int					parseall(char *format, t_opt *option, int ok);
void				apoption(t_opt *option, char **str, long nu);
size_t				basenumber(long nu, t_opt *option, int base);
size_t				basenumber1(unsigned long nu, t_opt option, int base,
		size_t letter);
void				blank(char **str, t_opt *option, long nu);
void				zero(char **str, int nu);
char				*hashtag(char **str, t_opt *option);
void				plus(char **str, long nu);


/*
**	colors
*/

# define GRN		"\e[32m"
# define MAG		"\e[35m"
# define CYN		"\e[36m"
# define GREY		"\e[90m"
# define ORANGE		"\e[38;5;208m"
# define RED		"\e[38;5;196m"
# define YEL		"\e[38;5;11m"
# define BLUE		"\e[38;5;4m"
# define DBLUE		"\e[38;5;21m"
# define PINK		"\e[38;5;13m"
# define RESET		"\e[0m"

#endif
