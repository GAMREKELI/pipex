#include "../include/pipex_bonus.h"

void	check_heredoc(t_pipex_b *pipex, char **av)
{
	char	*line;
	int		fd_here_doc;

	fd_here_doc = open(".heredoc_tmp", O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fd_here_doc < 0)
		exit(1);
	while(1)
	{
		if((get_next_line(0, &line)) == -1)
			return ;
		if (ft_strlen(av[2]) == -1 + ft_strlen(line) && (!(ft_strncmp(av[2], line, ft_strlen(av[2])))))
			break;
	}
	write(fd_here_doc, line, (ft_strlen(line) - 1));
	close(fd_here_doc);
	free(line);
	pipex->in = open(".heredoc_tmp", O_RDONLY , 0777);
	if (pipex->in < 0)
	{
		unlink(".heredoc_tmp");
		exit(1);
	}
}
