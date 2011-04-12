#include <sys/types.h>

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif /* HAVE_CONFIG_H */

#include <stdio.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <assert.h>
#include <errno.h>
#include <stdlib.h>

#ifdef HAVE_SCHED_H
#include <sched.h>
#endif

void Test0(void)
{
	pid_t pid, wpid;
	int status = -1;

	printf("\n-----Entering %s\n", __func__);

	if ((pid = vfork()) == 0) {
                /* can only exit here */
                char *argv[] = { "/bin/ls", NULL };
                char *envp[] = { NULL };

                execve("/bin/ls", argv, envp);

		exit(0);
	}

	printf("I am: %d\n", getpid());
	printf("Got child: %d\n", pid);

	wpid = waitpid(-1, &status, 0);

	printf("Got wpid %d status %d, wanted %d\n", wpid, status, pid);

	assert(wpid == pid);
	assert(status == 0);
}

int
main(void)
{
	Test0();
        exit(0);
}
