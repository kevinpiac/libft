/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 10:37:12 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/28 14:37:01 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# define ABS(x) ((x > 0) ? x : -x)
# define GNL_BUFF_SIZE 100
# include "opm_config.h"
# include "error_config.h"
# include <sys/stat.h>

typedef	enum
{
	false,
	true
}	t_bool;

/*
** VECTORS
*/

# define VECTOR_DEFAULT_CAPACITY 10

typedef struct		s_vector
{
	void			**items;
	int				capacity;
	int				total;
}					t_vector;

t_vector			*vector_new(size_t capacity);
void				vector_del(t_vector *this, void(del_fn)(void *));
void				vector_delone(t_vector *this, int index, void (*f)(void *));
void				vector_clear(t_vector *this, void (*f)(void *));
void				*vector_get(t_vector *this, int index);
void				vector_set(t_vector *this, void *item, int index);
void				vector_add(t_vector *this, void *item);
void				vector_addfront(t_vector *this, void *item);
void				vector_resize(t_vector *this);
void				vector_showall(t_vector *this);
void				vector_insert(t_vector *this, void *item, int index);
void				vector_foreach(t_vector *this, void (*f)(void *));
void				vector_bubblesort(t_vector *this,
						int (*cmp)(void *, void *), int order);
char				**vector_totab(t_vector *this);

/*
** ARGUMENTS MANAGER
*/

typedef struct		s_arm_argument
{
	char			*type;
	char			*name;
}					t_arm_argument;

t_arm_argument		*arm_argument_new(char *name, char *type);
t_vector			*arm_init(int ac, char **av);
void				arm_debug(t_vector *arm);
void				arm_destroy(t_vector *this);

t_arm_argument		*arm_getparam(t_vector *arm, int index);
char				*arm_getparam_name(t_vector *arm, int index);
char				*arm_getparam_type(t_vector *arm, int index);
char				*arm_tostr(t_vector *arm);

t_arm_argument		*arm_findparam(t_vector *arm, char *name);
t_vector			*arm_findallparams(t_vector *arm);
t_vector			*arm_findalloptions(t_vector *arm);

t_bool				arm_isparam(t_arm_argument *arg);
t_bool				arm_isoption(t_arm_argument *arg);

/*
** PROGRAM'S OPTIONS MANAGER
*/

typedef struct		s_opm_option
{
	char			*name;
	char			**aliases;
	char			*param;
	t_bool			req_params;
	t_bool			is_set;
}					t_opm_option;

typedef struct		s_opm_params
{
	t_vector		*config;
	t_vector		*params;
	int				total_set;
	t_bool			error;
	int				error_code;
}					t_opm_params;

t_vector			*opm_config_init(char *config);
void				opm_config_destroy(t_vector *this);

t_opm_params		*opm_init(t_vector *arm, t_vector *config);
void				opm_destroy(t_opm_params *this);

void				opm_debug(t_opm_params *opm);
void				opm_error(const char *error_description);
t_opm_option		*opm_getoption(t_opm_params *params, int index);
char				*opm_getoption_param(t_opm_params *params, int index);

t_opm_option		*opm_findoption(t_vector *options, char *name);
char				*opm_findoption_param(t_vector *options, char *name);

t_bool				opm_issetoption(t_vector *option, char *name);

/*
** LINKED LISTS
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);

void				ft_lstput(t_list *list);
void				ft_lstputendl(t_list *list);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstaddback(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** GET NEXT line
*/

typedef	struct		s_gnl
{
	void			*content;
	size_t			content_size;
	struct s_gnl	*next;
	int				fd;
}					t_gnl;

int					get_next_line(int fd, char **line);

/*
** BIT OPERATIONS
*/

void				ft_bitprint(unsigned int i);
void				ft_bitsetfour(unsigned int *i, unsigned int val,
									unsigned int nth);
void				ft_bitsetoctal(unsigned int *i, unsigned int val,
									unsigned int nth);

unsigned int		ft_bitgetfour(unsigned int i, unsigned int index);
unsigned int		ft_bitgetoctal(unsigned int i, unsigned int index);

/*
** FUNCTIONS TO PRINT
*/

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int f);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);

/*
** GET INFORMATIONS ABOUT STR / CHAR
*/

size_t				ft_strlen(const char *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strindex(const char *str, const char *to_find);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strsub(const char *s, unsigned int start, size_t len);

/*
** STR / CHAR BOOLEAN ?
*/

int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_istoskip(char *tab, int c);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);

/*
** STR / CHAR MANIPULATIONS
*/

int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_atoi(const char *s);

char				*ft_itoa(int n);
char				*ft_strcat(char *s1, const char *s2);
size_t				ft_strlcat(char *s1, const char *s2, size_t n);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s);
char				*ft_strreplace(const char *str, const char *to, char *by);

char				**ft_strsplit(char const *s, char c);
void				ft_delsplit(char **splited);
int					ft_splitcount(char **splited);

/*
** MEMORY ALLOCATION / MANIPULATION
*/

void				*ft_memalloc(size_t size);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *s, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_realloc(void *ptr, size_t size, size_t newsize);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_bzero(void *s, size_t n);
char				*ft_strnew(size_t size);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

/*
** FUNCTION POINTER
*/

void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

char				*ft_strmap(char const *s, char(*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
** ERROR HANDLER
*/

void				error_print(int error_type, char *cmd, char *error_details);

/*
** DIRECTORY / FILES / LINKS
*/

t_bool				is_dir(const char *path);
t_bool				is_reg(const char *path);
t_bool				is_lnk(const char *path);

#endif
