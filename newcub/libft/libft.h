/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:11:02 by tkitago           #+#    #+#             */
/*   Updated: 2025/04/10 11:02:46 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <inttypes.h>
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define PATH_SEPARATE '/'

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

# define STRGEN_BUFFSIZE 20
# define GNL_BUFFSIZE 10000

typedef struct s_strgen
{
	char			*str;
	char			buff[STRGEN_BUFFSIZE];
	size_t			position;
	int				error;
}					t_strgen;
//*str: ptr keeps main charline
// buff: buf accum tmp data
// position: write posi in buf
// error: error flg

typedef struct s_bufferio
{
	int				fd;
	t_strgen		*strgen;
}					t_bufferio;

typedef struct s_xorshift32_state
{
	uint32_t		a;
}					t_xorshift32_state;

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
int					ft_isalnum(int i);
int					ft_isalpha(int i);
int					ft_isascii(int i);
int					ft_isdigit(int i);
int					ft_isprint(int i);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strchr(const char *s, int i);
char				*ft_strdup(const char *s);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
char				*ft_strrchr(const char *s, int c);
int					ft_tolower(int i);
int					ft_toupper(int i);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *str, char c);
int					abs(int nbr);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_strcmp(const char *s1, const char *s2);
void				*ft_2darraynew(size_t size, size_t width, size_t height);
double				ft_atof(const char *str);
int					ft_isspace(int c);
void				ft_2darraydel(void *array);
int					ft_bufferioread(t_bufferio *io);
t_bufferio			*ft_bufferionew(int fd, int close_on_error);
void				ft_bufferiodel(t_bufferio *io, int do_close);
void				ft_strgendel(t_strgen *strgen);
void				ft_strgeninteg(t_strgen *strgen);
t_strgen			*ft_strgeninit(void);
char				*ft_strgenfetch(t_strgen *strgen, size_t len);
void				ft_strgenchr(t_strgen *strgen, char insert);
void				ft_strgenstr(t_strgen *strgen, char *insert);
char				*ft_strgencomp(t_strgen *strgen);
char				*ft_strjoin2(char const *s1, char const *s2);
size_t				ft_llstlen(void *lst, size_t size);
int					ft_llstdel(void *lst_ptr, size_t size, int index,
						void *dst);
void				*ft_llst2array(void *lst, size_t size, size_t *__len);
void				ft_llstclear(void *lst_ptr, size_t size);
int					ft_llstappend(void *lst_ptr, size_t size, void *newlst);
char				*ft_readline(t_bufferio *io);
char				*ft_joinpath(char *base, char *path);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstadd_back(t_list **lst, t_list *newlst);
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_char(int fd, char c);
int					ft_format(int fd, int c, va_list args);
int					ft_hex(int fd, unsigned int i, int f);
int					ft_int(int fd, int i);
char				*ft_pointer_base(unsigned long long pointer, int base);
int					ft_pointer(int fd, unsigned long long pointer);
int					ft_dprintf(int fd, const char *input, ...);
int					ft_str_count(int fd, char *c);
int					ft_str(int fd, char *str);
char				*ft_tolower_all(char *c);
int					ft_uint(int fd, unsigned int uint);
int					ft_unfo_output(int fd, const char *input, va_list args);

// functions added by icchon
int					ft_calc_next_chr(char *str, char c);
int					ft_calc_next_str(char *src, char *set);
int					ft_contain(const char *str, char c);
int					ft_contain_any(const char *str, const char *set);
int					ft_create_file(char *filename);
char				*ft_create_random_file(char *prefix, char *extension);
uint32_t			ft_generate_seed(void);
char				*ft_get_absolute_path(char *relative_path, char **env);
char				*ft_get_env(char *key, char **env);
char				**ft_get_expanded_env(char *key, char sep, char **env);
char				**ft_get_expanded_path(char **env);
int					ft_max(int argn, ...);
int					ft_min(int argn, ...);
int					ft_path_exist(char *path);
uint32_t			ft_rand_u32(uint32_t seed);
char				*ft_strjoin_safe(char *s1, char *s2, int is_free1,
						int is_free2);
char				*ft_utoa(unsigned int n);
int					ft_get_digit_cnt(uintptr_t n, unsigned int base);
char				*ft_chr_to_str(char c);
int					ft_isequal(char *s1, char *s2);
int					ft_ismatch(int x, int argn, ...);
size_t				ft_strslen(const char **strs);
void				ft_print_strs(char **strs);
int					ft_isint(const char *nptr);
int					ft_islong(const char *nptr);
int					ft_issign(int c);
char				**ft_strsdup(char **strs);
void				*xmalloc(size_t size);
char				*ft_strtrim_safe(char *s1, char *set);
int					ft_calc_back_chr(char *str, char c);

#endif