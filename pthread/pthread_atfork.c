#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

static void prepare_before_fork()
{
    printf("prepare: before fork\n");
}

static void parent_after_fork()
{
    printf("parent: after fork\n");
}

static void child_after_fork()
{
    printf("child: after fork\n");
}

static void *worker(void *arg)
{
    printf("pthread worker\n");
}

int main()
{
    pthread_t id;

    pthread_atfork(&prepare_before_fork, &parent_after_fork, &child_after_fork);
    fork();

    pthread_create(&id, NULL, &worker, NULL);
    pthread_join(id, NULL);

    return 0;
}
