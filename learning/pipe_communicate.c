#include <stdio.h>
#include <unistd.h>

int main()
{
	int fd[2];
	// fd[0] read
	// fd[1] write
	if (pipe(fd) == -1)
		return (1);
	int pid = fork();
	if (pid == -1)
		return (2);
	if (pid == 0) // parent process
	{
		close(fd[0]);
		int x;
		printf("Input a number: ");
		scanf("%d", &x);
		if (write(fd[1], &x, sizeof(int)) == -1)
			return (3);
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		int y;
		if (read(fd[0], &y, sizeof(int)) == -1)
			return (4);
		close(fd[0]);
		printf("Got from child process %d\n", y);
	}

	return (0);
}