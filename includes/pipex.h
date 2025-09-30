/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitas <adavitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 21:40:26 by adavitas          #+#    #+#             */
/*   Updated: 2025/09/30 22:13:06 by adavitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <stdio.h>
# include "libft.h"

void	ft_child(char **argv, char **envp, int *fd);
void	ft_parent(char **argv, char **envp, int *fd);
void	ft_error(char *err_str, int exit_code);
char	*ft_get_path(char **envp, char *command);
void	ft_execute(char *str, char **envp);

#endif
