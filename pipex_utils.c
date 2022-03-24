#include "./include/pipex.h"

void	ft_close(t_pipex *pipex)
{
	close(pipex->pip[0]);
	close(pipex->pip[1]);
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

void	ft_clean_main(t_pipex pipex)
{
	int	i;

	i = -1;
	close(pipex.in);
	close(pipex.out);
	while (pipex.command[++ i])
		free(pipex.command[i]);
	free(pipex.command);
}

void	ft_clean_child(t_pipex *pipex)
{
	int	i;

	i = -1;
	while (pipex->split_command[++ i])
		free(pipex->split_command[i]);
	free(pipex->split_command);
	free(pipex->result);
}

void	ft_open_fd(t_pipex *pipex, char *av[], int ac)
{
	pipex->in = open(av[1], O_RDONLY);
	pipex->out = open(av[ac - 1], O_RDWR | O_TRUNC | O_CREAT, 0777);
	if (pipex->in < 0 || pipex->out < 0)
		exit(1);
}
