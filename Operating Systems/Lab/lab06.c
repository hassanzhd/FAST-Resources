#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

// Q1: calculate two different sum of tables and then display the result but concurrently
// IPC using unnamed pipes => two ends => 0th end -> read end, 1th end -> write end

int main(int argc, char const *argv[]) {
    int fileDiscripter[2];  // 0th index and 1th index
    pipe(fileDiscripter);   // this will be creating the pipe

    //  0 <- fileDiscripter -> 1

    pid_t p;
    p = fork();

    if (p == 0) {
        int a = 0;
        int factor = 1;

        for (int i = 1; i <= 10; i++) {
            a = a + (factor * i);
        }

        write(fileDiscripter[1], &a, sizeof(int));

        exit(0);
    } else if (p > 0) {
        int b = 0;
        int factor = 2;

        for (int i = 1; i <= 10; i++) {
            b = b + (factor * i);
        }

        wait(NULL);

        int a;
        read(fileDiscripter[0], &a, sizeof(int));

        printf("%d %d\n", a, b);

    } else if (p < 0) {
        printf("ERROR OCCURED\n");
    }

    return 0;
}
