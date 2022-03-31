/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:48:04 by hzona             #+#    #+#             */
/*   Updated: 2021/11/06 14:33:34 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*f_pathes(char *cmd, char **envm)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envm[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envm[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		i++;
	}
	return (0);
}

void	command(char *argv, char **envm)
{
	char	**cmd;
	char	*file_path;

	cmd = ft_split(argv, ' ');
	file_path = f_pathes(cmd[0], envm);
	if (execve(file_path, cmd, envm) == -1)
		return (error_cmd());
}
