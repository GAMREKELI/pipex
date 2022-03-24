#include "../include/pipex_bonus.h"

void	outfile(t_pipex_b *pipex, char **av, int ac)
{
	if (pipex->here_doc == 1)
		pipex->out = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
	else
	{
		pipex->out = open(av[ac - 1], O_RDWR | O_TRUNC | O_CREAT, 0777);
	}
	if (pipex->out < 0)
	{
		close(pipex->in);
		exit(1);
	}
}

void	infile(t_pipex_b *pipex, char **av)
{
	if (!(ft_strncmp(av[1], "here_doc", 9)))
	{
		pipex->here_doc = 1;
		check_heredoc(pipex, av);
	}
	else
	{
		pipex->here_doc = 0;
		pipex->in = open(av[1], O_RDONLY);
		if (pipex->in < 0)
			exit(1);
	}
}
