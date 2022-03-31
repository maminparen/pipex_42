/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:48:04 by hzona             #+#    #+#             */
/*   Updated: 2021/11/06 14:57:30 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(int *p, char **argv, char **envm)
{
	int	file;

	if (!access(argv[4], F_OK) && access(argv[4], W_OK))
		error_premission();
	file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file == -1)
		error_file();
	dup2(p[0], 0);
	dup2(file, 1);
	close(p[1]);
	command(argv[3], envm);
}

void	child_process(int *p, char **argv, char **envm)
{
	int	file;

	if (!access(argv[4], F_OK) && access(argv[1], R_OK))
		error_premission();
	file = open(argv[1], O_RDONLY, 0777);
	if (file == -1)
		error_file();
	dup2(p[1], 1);
	dup2(file, 0);
	close(p[1]);
	command(argv[2], envm);
}

int	main(int argc, char **argv, char **envm)
{
	pid_t	pid;
	int		p[2];

	if (argc != 5)
	{
		write(1, "Usage : ./pipex infile cmd1 cmd2 outfile\n", 41);
		return (0);
	}
	if (pipe(p) == -1)
		return (0);
	pid = fork();
	if (pid == -1)
		return (0);
	if (pid == 0)
		child_process(p, argv, envm);
	waitpid(pid, NULL, 0);
	parent_process(p, argv, envm);
	close(p[0]);
	close(p[1]);
	return (0);
}
