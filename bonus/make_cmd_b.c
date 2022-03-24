#include "../include/pipex_bonus.h"

char	*make_cmd(char *av, char **command)
{
	char	*tmp;
	char	*comma;

	while (*command)
	{
		tmp = ft_strjoin(*command, "/");
		comma = ft_strjoin(tmp, av);
		free(tmp);
		if (!(access(comma, 0)))
			return (comma);
		free(comma);
		command ++;
	}
	return (NULL);
}
