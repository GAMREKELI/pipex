#include "../include/pipex_bonus.h"

void	ft_child(t_pipex_b *pipex, char **argv, char **envp)
{
	pipex->all_pid = fork();
	if (pipex->all_pid == 0)
	{
		if (pipex->num_child == 0)
			ft_dup(pipex->in, pipex->pip[1]);
		else if (pipex->num_child == pipex->number_cmd - 1)
			ft_dup(pipex->pip[2 * pipex->num_child - 2], pipex->out);
		else
			ft_dup(pipex->pip[2 * pipex->num_child - 2], pipex->pip[2 * pipex->num_child + 1]);
		close_pipes(pipex);
		pipex->split_command = ft_split(argv[2 + pipex->here_doc + pipex->num_child], ' ');
		pipex->cmd = make_cmd(pipex->split_command[0], pipex->command);
		if (!pipex->cmd)
		{
			ft_clean_child(pipex);
			exit(1);
		}
		execve(pipex->cmd, pipex->split_command, envp);
	}
}