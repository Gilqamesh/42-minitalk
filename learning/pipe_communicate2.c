#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	// We create two pipes when communicating between 2 processes in order
	// to prevent any of them from reading and writing to the same pipe
	// causing async related issues
	// Example: if a process writes and reads too fast the other process might
	// be reading the pipe a bit too late to receive the message in which case
	// the entire process will hang.
	int p1[2]; // C -> P
	int p2[2]; // P -> C
	int	pid;

	if (pipe(p1) == -1) return (1);
	if (pipe(p2) == -1) return (2);

	pid = fork();
	if (!pid)
	{
		// Child process
		// Start by closing pipe ends that are not needed
		close(p1[0]);
		close(p2[1]);
		int x;
		read(p2[0], &x, sizeof(x));
		printf("Child has received %d\n", x);
		x *= 4;
		write(p1[1], &x, sizeof(x));
		printf("Child has sent back %d\n", x);
		close(p1[1]);
		close(p2[0]);
	}
	else
	{
		// Parent process
		// Close pipe ends that are not needed for the parent process
		close(p1[1]);
		close(p2[0]);
		srand(time(NULL));
		int y = rand() % 10;
		write(p2[1], &y, sizeof(y));
		printf("Parent has sent %d\n", y);
		read(p1[0], &y, sizeof(y));
		printf("Parent has received %d\n", y);
		close(p1[0]);
		close(p2[1]);
	}
	return (0);
}