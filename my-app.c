#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char * argv[])
{
    printf(1, "This is my own app! [%d]\n", getcpuid());
    exit();
}
