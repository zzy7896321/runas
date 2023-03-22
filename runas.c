#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

#ifndef PROG
#error "no PROG defined"
#endif

#define STRINGIFY_HELPER(_1) #_1
#define STRINGIFY(_1) STRINGIFY_HELPER(_1)

int main(int argc, char *argv[]) {
    pid_t pid;
    
    const char *prog = STRINGIFY(PROG);

    if (prog[0] != '/') {
        fprintf(stderr, "PROG must be absolute path, but we've got: \"%s\"", prog);
        return 1;
    }
    
    pid = fork();
    if (pid > 0) {
        if (-1 == execv(prog, argv)) {
            fprintf(stderr, "failed to run %s\n", prog);
        }
    } else if (pid < 0) {
        fprintf(stderr, "failed to run %s\n", prog);
        return 2;
    }

    return 0;
}

