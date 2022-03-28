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

void	ft_close_pip(t_pipex_b *pipex)
{
	int	i;

	i = -1;
	while (++ i < (pipex->pipe_num))
		close(pipex->pip[i]);
}
