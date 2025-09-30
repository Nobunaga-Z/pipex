#include "pipex.h"

void    ft_error(char *err_str)
{
    ft_putstr_fd(err_str, 2);
    exit(1);
}

int	main(int argc, char **argv, char **envp)
{
    int     fd[2];
    pid_t   id;

    if (argc != 5)
        ft_error("Error: Usage: ./pipex file1 cmd1 cmd2 file2\n");
    if (pipe(fd) == -1)
        ft_error("Error: Failed to create pipe\n");
    id = fork();
    if (id == -1)
    {
        close(fd[0]);
        close(fd[1]);
        ft_error("Error: Failed to fork\n");
    }
    if (id == 0)
        ft_child(argv, envp, fd);
    waitpid(id, NULL, 0);
    ft_parent(argv, envp, fd);
    return (0);
}
