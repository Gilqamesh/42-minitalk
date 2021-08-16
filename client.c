#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "minitalk.h"

char	*message;
pid_t	pid;

void	handle_sigusr1(int sig)
{
	write(STDOUT_FILENO, message, ft_strlen(message));
}

int main(int argc, char **argv)
{
	struct sigaction	sa;
	char				*err;

	if (argc != 3)
	{
		err = "Usage: client PID MSG\n";
		write(STDERR_FILENO, err, ft_strlen(err));
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	message = argv[2];
	sa.sa_handler = &handle_sigusr1;
	sigaction(SIGUSR1, &sa, NULL);
	kill(pid, SIGUSR1);
	return (0);
}
