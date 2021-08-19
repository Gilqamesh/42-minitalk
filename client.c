#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "minitalk.h"
#include <stdio.h>

static void	handle_error(void)
{
	char	*tmp;

	tmp = "Usage: client PID tmp\n";
	write(STDERR_FILENO, tmp, ft_strlen(tmp));
	exit(EXIT_FAILURE);
}

static void	handlesigusr(int sig, siginfo_t *info, void *ucontext)
{
}

static void	send_message(char *message, pid_t pid)
{
	int		i;
	char	byte;

	while (*message)
	{
		byte = *message;
		i = -1;
		while (++i < 8)
		{
			usleep(50);
			if (byte & 128)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			byte <<= 1;
			pause();
		}
		message++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	sigset_t			mask;

	if (argc != 3)
		handle_error();
	sa.__sigaction_u.__sa_sigaction = &handlesigusr;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&mask);
	sa.sa_mask = mask;
	sigaction(SIGUSR1, &sa, NULL);
	send_message(argv[2], ft_atoi(argv[1]));
	return (0);
}
