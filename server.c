#include "minitalk.h"
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <inttypes.h>

void	handlesigusr(int sig, siginfo_t *info, void *ucontext)
{
	static char	c;
	static int	i;

	if (sig == SIGUSR1)
	{
		c <<= 1;
		c |= 1;
	}
	else if (sig == SIGUSR2)
		c <<= 1;
	i++;
	if (i == 8)
	{
		write(STDOUT_FILENO, &c, 1);
		i = 0;
		c = 0;
	}
	usleep(50);
	if (info->si_pid)
		kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;
	sigset_t			mask;

	pid = getpid();
	ft_putnbr_fd((int)pid, STDOUT_FILENO);
	sa.__sigaction_u.__sa_sigaction = &handlesigusr;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&mask);
	sa.sa_mask = mask;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
