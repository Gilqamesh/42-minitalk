#include <stdio.h>
#include <unistd.h>

int main()
{
	// Calling fork creates a child process from where its called, returns a ID and executes anything from that line on a different child process.
	int id = fork();
	printf("Hello from id: %d\n", id); // This will differ on child and parent process because of the fork. 0 means child process, anything else main process
	// This ID returned in the child process is not its process ID. We can get that with getpid()
	// However the ID we get in the parent process is the child's process ID.
	if (id == 0)
		printf("Hello from child process\n");
	else
		printf("Hello from the main process\n");
}