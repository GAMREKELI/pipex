/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdursley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:44:46 by pdursley          #+#    #+#             */
/*   Updated: 2022/03/31 00:44:46 by pdursley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	ft_error_in_out(void)
{
	write(2, "\nError\n", 7);
	exit(1);
}

void	outfile(t_pipex_b *pipex, char **av, int ac)
{
	if (pipex->here_doc == 1)
		pipex->out = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
	else
		pipex->out = open(av[ac - 1], O_RDWR | O_TRUNC | O_CREAT, 0777);
	if (pipex->out < 0)
	{
		if (pipex->here_doc == 0)
		{
			if (unlink(av[1]) < 0)
				ft_error_in_out();
		}
		ft_error_in_out();
	}
}

void	infile(t_pipex_b *pipex, char **av, int ac)
{
	if (!ft_strncmp(av[1], "here_doc", 9))
	{
		if (ac >= 6)
		{
			pipex->here_doc = 1;
			check_heredoc(pipex, av);
		}
		else
			ft_error_in_out();
	}
	else
	{
		if (ac >= 5)
		{
			pipex->here_doc = 0;
			pipex->in = open(av[1], O_RDONLY);
			if (pipex->in < 0)
				ft_error_in_out();
		}
		else
			ft_error_in_out();
	}
}
