/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:42:03 by yusong            #+#    #+#             */
/*   Updated: 2021/08/19 11:42:03 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerfile.h"

int	main(int argc, char **argv, char ** env)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
		errorExit();
	if (pipe(fd) == -1)
		errorExit();
	pid = fork();
	if (pid == -1)
		errorExit();
	if (pid == 0)
		childProccer(argv, env, fd);
	waitpid(pid, NULL, 0);
	parentProcess(argv, env, fd);
	close(fd[0]);
	close(fd[1]);
	return (0);
}