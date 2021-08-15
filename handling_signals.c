#include <stdio.h>
#include <signal.h>

void handle_sigstp(int sig)
{
	printf("Stop not allowed\n");
}

// opposite of sigstp
void handle_sigcont(int sig)
{
	// One thing to note: signal handlers are usually ran asyncronously
	// so instead of using functions like printf, use write instead!
	// Some functions are async safe which are seen in manual
	printf("Input number: \n");
	fflush(stdout);
}

int main(void)
{
	// Hook the signal
	struct sigaction sa;
	sa.__sigaction_u.__sa_handler = &handle_sigcont;
	sa.sa_flags = SA_RESTART;
	// Ctrl + Z (stop execution) (its not kill execution, we can use continue
	// signal later to continue it (command fg)

	sigaction(SIGCONT, &sa, NULL);
	// sigaction(SIGTSTP, &sa, NULL);

	// Could also have done signal(SIGTSTP, &handle_sigstp)
	// But the manual of signal says to avoid it as the implementation of the
	// function varies depending on different versions of Linux and to use
	// sigaction instead.

	int x;
	printf("Input number: ");
	scanf("%d", &x);
	printf("Result %d * 5 = %d\n", x, x * 5);
	return (0);
}