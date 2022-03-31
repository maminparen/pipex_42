/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:49:11 by hzona             #+#    #+#             */
/*   Updated: 2021/11/06 15:01:18 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

void	error_cmd(void);
void	error_file(void);
void	error_premission(void);
void	error_pipe(void);
void	error_pid(void);
char	*f_pathes(char *cmd, char **envm);

int		mini_gnl(int fd, char **line);

void	command(char *argv, char **envm);
char	**ft_split(const char *str, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *string);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

int		open_file(char *argv, int i);
void	arg_err(void);

#endif
