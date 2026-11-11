#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    pid_t p = fork();
    if (p == -1) { perror("fork"); return 1; }
    if (p == 0) {
        printf("fils: pid=%d ppid=%d\n", getpid(), getppid());
        return 0;
    }
    wait(NULL);
    printf("pere: pid=%d ppid=%d\n", getpid(), getppid());
    return 0;
}