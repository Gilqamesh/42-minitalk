#include "minitalk.h"
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void	handlesigusr1(int sig)
{
	char	*msg;

	msg = "Hello from server\n";
	write(STDOUT_FILENO, msg, ft_strlen(msg));
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	ft_putnbr_fd((int)pid, STDOUT_FILENO);
	sa.sa_handler = &handlesigusr1;
	sigaction(SIGUSR1, &sa, NULL);
	while (1)
	{
		pause();
		sleep(1);
	}
	return (0);
}
