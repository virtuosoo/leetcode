#include <stdio.h>
#include <string.h>
#include <signal.h>
typedef void (func) (int);

int main()
{
    //'printf("%s\n", strchr(NULL, 'c'));
    signal(SIGINT, SIG_IGN);
}

