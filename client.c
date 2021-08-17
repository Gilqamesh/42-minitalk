#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "minitalk.h"
#include <stdio.h>

void	handle_error(void)
{
	char	*tmp;

	tmp = "Usage: client PID tmp\n";
	write(STDERR_FILENO, tmp, ft_strlen(tmp));
	exit(EXIT_FAILURE);
}

void	handlesigusr(int sig)
{

}

int main(int argc, char **argv)
{
	char				*tmp;
	char				cur;
	pid_t				pid;
	int					i;
	struct sigaction	sa;

	printf("Client pid: %d\n", (int)getpid());
	if (argc != 3)
		handle_error();
	sa.__sigaction_u.__sa_handler = &handlesigusr;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	pid = ft_atoi(argv[1]);
	tmp = argv[2];
	while (*tmp)
	{
		cur = *tmp;
		i = -1;
		while (++i < 8)
		{
			if (cur & 128)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			cur <<= 1;
			usleep(1000);
			pause();
			usleep(1000);
		}
		tmp++;
	}
	return (0);
}
