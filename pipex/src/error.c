/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:31:36 by hzona             #+#    #+#             */
/*   Updated: 2021/11/06 15:01:02 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_cmd(void)
{
	write(2, "command not found\n", 18);
	exit(0);
}

void	error_file(void)
{
	write(2, "No such file or directory\n", 26);
	exit(0);
}

void	error_premission(void)
{
	write(2, "Permission denied\n", 18);
	exit(0);
}

void	error_pipe(void)
{
	write(2, "Pipe error\n", 11);
	exit(0);
}

void	error_pid(void)
{
	write(2, "Pid error\n", 10);
	exit(0);
}
