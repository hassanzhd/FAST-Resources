#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

// pid_t is used for process ID storage
// fork return either ==0 => (child), > 0 (parent) ,or < 0 (error creating child)

int main(int argc, char const *argv[]) {
    pid_t p;
    p = fork();  // from this line onwards both parent and child are executed

    if (p == 0) {
        for (int i = 0; i < 4; i++) {
            printf("ME BHAI KE BACHE GIN RHA HU\n");
        }
        exit(0);  // exit from the process created
    } else if (p > 0) {
        for (int i = 0; i < 4; i++) {
            printf("ME BEHN KE BACHE GIN RHA HU\n");
        }
        wait(NULL);  // parent waits for the complete execution of child
        printf("I AM LEAVING EARTH\n");
    } else if (p < 0) {
        printf("THERE WAS AN ERROR\n");
    }

    return 0;
}
