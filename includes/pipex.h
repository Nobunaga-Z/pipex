#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <stdio.h>
# include "libft.h"

void    ft_child(char **argv, char **envp, int *fd);
void    ft_parent(char **argv, char **envp, int *fd);
void    ft_error(char *err_str);
char    *ft_get_path(char **envp, char *command);
void    ft_execute(char *str, char **envp);

#endif
