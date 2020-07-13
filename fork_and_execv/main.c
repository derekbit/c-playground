#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/* exec()
 *
 * Overlay Calling Process and Run New Program
 *
 * ref:
 * (1) https://www.man7.org/linux/man-pages/man3/execv.3.html
 * (2) The Execuve() Function, Linux for Embedded and Real-time Applications
 * The exec() family of functions replaces the current process image
 * with a new process image.
 *
 * execve() does not return on success, and the text, initialized data,
 * uninitialized data (bss), and stack of the calling process are over‐
 * written according to the contents of the newly loaded program.
 */


int main(int argc, const char *argv[])
{
	pid_t pid = fork();
	char * const params[] = { "/bin/ls", "-l", NULL };

	switch (pid) {
	case -1:
		break;
	case 0: /* child process */
		execv("/bin/ls", params);
		printf("child process: should not show this message\n");
		break;
	default: /* parent process */
		printf("parent process\n");
		break;
	}

	return 0;
}
