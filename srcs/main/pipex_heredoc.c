/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:33:18 by myeow             #+#    #+#             */
/*   Updated: 2024/04/22 00:49:21 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	heredoc_process(int argc, char **argv, int heredoc_fd)
{
	char	*content;
	int		i;

	while (1)
	{
		i = argc - 4;
		while (--i > 0)
			ft_putstr_fd("pipe ", 1);
		ft_putstr_fd("heredoc> ", 1);
		content = get_next_line(STDIN_FILENO);
		if (content)
		{
			if (!ft_strncmp(content, argv[2], ft_strlen(argv[2])) && \
					*(content + ft_strlen(argv[2])) == '\n')
				break ;
			ft_putstr_fd(content, heredoc_fd);
			free(content);
		}
	}
}

int	pipex_heredoc(int argc, char **argv)
{
	int	fd;

	fd = open(".heredoc_temp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
		pipex_error("here_doc open error.", 0, 0, 1);
	heredoc_process(argc, argv, fd);
	close(fd);
	fd = open(".heredoc_temp", O_RDONLY);
	if (fd == -1)
	{
		unlink(".heredoc_temp");
		pipex_error("here_doc error.", 0, 0, 1);
	}
	return (fd);
}
