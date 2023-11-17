#ifndef SHELL_H
<<<<<<< HEAD
# define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>


# define BUFFER_SIZE
char	*str_copy1(char	*str, int *index, char a)
void	init_env(char **envp, global_t *global)
char	*env_search(char	*str, global_t *global)
env_t	*envsearch(char	*str, global_t *global)
int	is_num(char *str)
void    my_exit(char **cmd, global_t *global)
static char	*all(int fd, char *left)
static char	*get_line(char *line)
static char	*ft_left(char *line)
char	*_getline(int fd, global_t *global)
void	*my_memcpy(void *dst, const void *src, size_t n)
size_t	my_strlen(const char *s)
char	*my_strjoin(char *s1, char *s2)
char	*my_strchr(const char *s, int c)
static int	ft_abs(int nb)
static int	ft_nbrpow(int nbr)
char	*_itoa(int n)
int	is_lo_op(char *str)
int	count_words(char *str, global_t *global)
char *copy_str(char *str, int *index)
char **advanced_split(char *str, global_t *global)
void exec_logical_operators(char **str, global_t *global)
void	lstadd_back_env(env_t **lst, env_t *new)
void	lstadd_back_command(command_t **lst, command_t *new)
void	lstadd_back_alias(alias_t **lst, alias_t *new)
void	putnbr_fd(int n, int fd)
char *remove_comments(char *ptr, global_t *global, int fd)
void _setenv(char **cmd, global_t *global)
void _unsetenv(char **cmd, global_t *global)
static char	**m_error(char	**arr)
static int	ft_count_words(char const *str, char charset)
static int	ft_word_len(char const *str, char charset)
static char	*ft_word_grep(char const *str, char charset)
char	**split(char const *s, char c)
=======
#define SHELL_H

#include <stdio.h>

#include <stdarg.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>


char *my_getline(void);

char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);


>>>>>>> 46fe6cef6e2686bd67d07337589dd7075d2394aa

#endif
