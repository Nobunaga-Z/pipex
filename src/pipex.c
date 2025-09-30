/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitas <adavitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 21:40:48 by adavitas          #+#    #+#             */
/*   Updated: 2025/09/30 22:13:06 by adavitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *err_str, int exit_code)
{
	ft_putstr_fd(err_str, 2);
	exit(exit_code);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	id;

	if (argc != 5)
		ft_error("Error: Usage: ./pipex file1 cmd1 cmd2 file2\n", 1);
	if (pipe(fd) == -1)
		ft_error("Error: Failed to create pipe\n", 1);
	id = fork();
	if (id == -1)
	{
		close(fd[0]);
		close(fd[1]);
		ft_error("Error: Failed to fork\n", 1);
	}
	if (id == 0)
		ft_child(argv, envp, fd);
	waitpid(id, NULL, 0);
	ft_parent(argv, envp, fd);
	return (0);
}
