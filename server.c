#include "minitalk.h"
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void	handlesigusr1(int sig)
{

}

int	main(void)
{
	pid_t				pid;
	sigset_t			mask1;
	sigset_t			mask2;
	struct sigaction	sa1;
	struct sigaction	sa2;

	pid = getpid();
	ft_putnbr_fd((int)pid, STDOUT_FILENO);
	sigemptyset(&mask1);
	sigaddset(&mask1, SIGUSR2);
	sa1.sa_handler = &handlesigusr1;
	sa1.sa_mask = mask1;
	sigemptyset(&mask2);
	sigaddset(&mask2, SIGUSR1);
	sa2.sa_handler = &handlesigusr2;
	sa2.sa_mask = mask2;
	sigaction(SIGUSR1, &sa1, NULL);
	sigaction(SIGUSR2, &sa2, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
