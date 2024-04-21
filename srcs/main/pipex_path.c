/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:40:55 by myeow             #+#    #+#             */
/*   Updated: 2024/04/21 02:40:07 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
 * Finds the PATH variable amongst all the environment variables.
 */
static char	*find_path(char **envp)
{
	while (*envp)
	{
		if (ft_strnstr(*envp, "PATH", 4))
			return (*envp);
		++envp;
	}
	return (0);
}

/*
 * Gets the PATH from the environment variables.
 * Returns the value of PATH variable as an array of strings.
 */
char	**pipex_path(char **envp)
{
	char	*path;
	char	**path_dirs;

	path = find_path(envp);
	if (!path)
		return (0);
	path_dirs = ft_split(path + 5, ':');
	return (path_dirs);
}
