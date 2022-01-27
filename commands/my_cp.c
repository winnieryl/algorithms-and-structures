/*
* @Author: root
* @Date:   2017-05-02 17:33:36
* @Last Modified by:   root
* @Last Modified time: 2017-05-03 16:58:55
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/file.h>
#include <fcntl.h>
//#include "syscalls.h"
#include "include/mylib.h"

#define PERMS 0666
#define BUFSIZE 100

void error(char*, ...);

#ifdef MY_CP
int main(int argc, char *argv[]) {

    int f1, f2, n;
    char buf[BUFSIZ];

    if (argc != 3)
        error("Usage: cp from to");
    if((f1 = open(argv[1], O_RDONLY, 0)) == -1)
        error("cp: can't open %s", argv[1]);
    if((f2 = creat(argv[2], PERMS)) == -1)
        error("cp: can't create %s, mode %03o", argv[2], PERMS);
    while((n = read(f1, buf, BUFSIZE)) > 0)
        if(write(f2, buf, n) != n)
            error("cp: write error on file %s", argv[2]);
    return 0;
}

#endif

void error(char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "error: ");
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
    exit(1);
}