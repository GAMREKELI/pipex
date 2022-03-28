#include "./include/pipex.h"

void	check_path(t_pipex pipex)
{
	if (!pipex.path)
	{
		write(2, "\nError\n", 7);
		exit(1);
	}
}

void	ft_argc(int argc)
{
	if (argc != 5)
	{
		write(2, "\nError\n", 7);
		exit(1);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	ft_argc(argc);
	ft_open_fd(&pipex, argv, argc);
	pipex.path = ft_parse_path(envp);
	check_path(pipex);
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
