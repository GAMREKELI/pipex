#include "./include/pipex.h"

void	ft_child_one(t_pipex *pipex, char **av, char **envp)
{
	dup2(pipex->in, 0);
	close(pipex->pip[0]);
	dup2(pipex->pip[1], 1);
	pipex->split_command = ft_split(av[2], ' ');
	pipex->result = make_cmd(pipex, pipex->split_command[0], pipex->command);
	if (!pipex->result)
	{
		ft_clean_child(pipex);
		write(2, "\nCommand not found\n", 19);
		exit(1);
	}
	execve(pipex->result, pipex->split_command, envp);
}

void	ft_child_two(t_pipex *pipex, char **av, char **envp)
{
	dup2(pipex->out, 1);
	close(pipex->pip[1]);
	dup2(pipex->pip[0], 0);
	pipex->split_command = ft_split(av[3], ' ');
	pipex->result = make_cmd(pipex, pipex->split_command[0], pipex->command);
	if (!pipex->result)
	{
		ft_clean_child(pipex);
		write(2, "\nCommand not found\n", 19);
		exit(1);
	}
	execve(pipex->result, pipex->split_command, envp);
}
