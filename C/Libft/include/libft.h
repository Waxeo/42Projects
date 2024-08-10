/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:12:22 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/01/13 17:56:27 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_isalpha(int c);

int		ft_isdigit(int c);

int		ft_isalnum(int c);

int		ft_isascii(int c);

int		ft_isprint(int c);

size_t	ft_strlen(const char *theString);

void	*ft_memset(void *ptr, int value, size_t len);

void	ft_bzero(void *ptr, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t size);

void	*ft_memmove(void *dest, const void *src, size_t size);

size_t	ft_strlcpy(char *dest, const char *src, size_t size);

size_t	ft_strlcat(char *dest, const char *src, size_t size);

int		ft_toupper(int c);

int		ft_tolower(int c);

char	*ft_strchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c);

int		ft_strncmp(const char *s1, const char *s2, size_t len);

void	*ft_memchr(const void *s, int c, size_t size);

int		ft_memcmp(const void *ptr1, const void *ptr2, size_t size);

char	*ft_strnstr(const char *str, const char *to_find, size_t len);

int		ft_atoi(const char *str);

void	*ft_calloc(size_t nbr, size_t size);

char	*ft_strdup(const char *src);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strjoin(char *s1, char *s2);

char	*ft_strtrim(char const *s1, char const *c);

char	**ft_split(char const *s, char c);

char	*ft_itoa(int n);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

void	ft_putchar_fd(char c, int fd);

void	ft_putstr_fd(char *s, int fd);

void	ft_putendl_fd(char *s, int fd);

void	ft_putnbr_fd(int n, int fd);

t_list	*ft_lstnew(void *content);

void	ft_lstadd_front(t_list **lst, t_list *new);

int		ft_lstsize(t_list *lst);

t_list	*ft_lstlast(t_list *lst);

void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_lstdelone(t_list *lst, void (*del)(void *));

void	ft_lstclear(t_list **lst, void (*del)(void *));

void	ft_lstiter(t_list *lst, void (*f)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

int		ft_printf(const char *format, ...);
int		ft_check_format(char *format, va_list args);
int		ft_check_arg(char *format, int i, va_list args);

int		ft_putchar_c(char c);
int		ft_string(char *s);

int		ft_ptr(unsigned long long nbr);
int		ft_printhexap(unsigned long long nbr, int type);
void	ft_convertp(unsigned long long nbr, char *base);
int		ft_len_hexap(unsigned long long nbr);

int		ft_print_int(int c);
int		ft_print_unsigned(unsigned int c);

int		ft_printhexa(unsigned int nbr, int type);
void	ft_convert(unsigned int nbr, char *type);
int		ft_len_hexa(unsigned int nbr);

char	*ft_line_return(char *stock);
char	*ft_stock(char *stock);
char	*ft_read_and_save(int fd, char *stock);
char	*get_next_line(int fd);
#endif
