#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	int id = fork();
	int n;
	if (id == 0)
	{
		// Child process
		n = 1;
	}
	else
	{
		// Parent process
		n = 6;
	}
	if (id != 0)
	{
		// Wait for the child process to change state
		// Change state includes: child terminated, stopped/resumed by a signal
		wait(NULL);
	}
	for (int i = n; i < n + 5; i++)
	{
		printf("%d ", i);
		fflush(stdout);
	}

	return (0);
}