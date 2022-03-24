#include "./include/pipex.h"

char	*make_cmd(t_pipex *pipex, char *av, char **command)
{
	char	*tmp;

	while (*command)
	{
		tmp = ft_strjoin(*command, "/");
		pipex->cmd = ft_strjoin(tmp, av);
		free(tmp);
		if (!(access(pipex->cmd, 0)))
			return (pipex->cmd);
		free(pipex->cmd);
		command ++;
	}
	return (NULL);
}
