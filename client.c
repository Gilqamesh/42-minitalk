#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "minitalk.h"

int main(int argc, char **argv)
{
	char				*tmp;
	char				*message;
	char				cur;
	pid_t				pid;
	int					i;

	if (argc != 3)
	{
		tmp = "Usage: client PID tmp\n";
		write(STDERR_FILENO, tmp, ft_strlen(tmp));
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	message = argv[2];
	tmp = message;
	while (*tmp)
	{
		cur = *tmp;
		i = -1;
		while (++i < 8)
		{
			if (cur & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			cur >>= 1;
		}
		tmp++;
	}
	return (0);
}
