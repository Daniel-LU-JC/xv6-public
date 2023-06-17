#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char * argv[])
{
    // int a = 0;
    printf(1, "Observing Shared Variable! CPU[%d]\n", getcpuid());
    
    int pid = fork();
    if (pid == 0) {
        // printf(1, "Child Process! CPU[%d]\n", getcpuid());
        while (read_sh_var() == 0)
            printf(1, "waiting...\n");
        printf(1, "the new value set by the parent process: %d\n", read_sh_var());
    } else {
        // printf(1, "Parent Process! CPU[%d]\n", getcpuid());
        if (write_sh_var(1) != 0)
            printf(1, "[ERROR]\n");
        if (read_sh_var() != 1)
            printf(1, "[ERROR]\n");
    }

    exit();
}
