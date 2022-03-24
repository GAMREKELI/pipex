#include "./include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		exit(1);
	ft_open_fd(&pipex, argv, argc);
	pipex.path = ft_parse_path(envp);
	if (!pipex.path)
		exit(1);
	if (pipe(pipex.pip) < 0)
		exit(1);
	pipex.command = ft_split(pipex.path, ':');
	pipex.pid1 = fork();
	if (pipex.pid1 < 0)
		ft_clean_main(pipex);
	if (pipex.pid1 == 0)
		ft_child_one(&pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 < 0)
		ft_clean_main(pipex);
	if (pipex.pid2 == 0)
		ft_child_two(&pipex, argv, envp);
	ft_close(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	ft_clean_main(pipex);
	return (0);
}
