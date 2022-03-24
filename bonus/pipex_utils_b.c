#include "../include/pipex_bonus.h"

void	ft_close(t_pipex_b *pipex)
{
	close(pipex->in);
	close(pipex->out);
}

char	*ft_parse_path(char **envp)
{
	while (envp ++)
	{
		if (!(ft_strncmp("PATH=", *envp, 5)))
			return (*envp + 5);
	}
	return (NULL);
}

void	ft_clean_main(t_pipex_b pipex)
{
	int	i;

	i = -1;
	ft_close(&pipex);
	if (pipex.here_doc == 1)
		unlink(".heredoc_tmp");
	while (pipex.command[++ i])
		free(pipex.command[i]);
	free(pipex.command);
	free(pipex.pip);
}

void	ft_clean_child(t_pipex_b *pipex)
{
	int	i;

	i = -1;
	while (pipex->split_command[++ i])
		free(pipex->split_command[i]);
	free(pipex->split_command);
	free(pipex->cmd);
	write(1, "qwerty", 6);

}

void	ft_open_fd(t_pipex_b *pipex, char *av[], int ac)
{
	pipex->in = open(av[1], O_RDONLY);
	pipex->out = open(av[ac - 1], O_RDWR | O_TRUNC | O_CREAT, 0777);
	if (pipex->in < 0 || pipex->out < 0)
		exit(1);
}
