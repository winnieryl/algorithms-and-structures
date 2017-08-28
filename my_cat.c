/*
* @Author: root
* @Date:   2017-04-26 15:14:05
* @Last Modified by:   root
* @Last Modified time: 2017-04-26 15:56:41
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/mylib.h"

#ifdef MY_CAT
/* concatenate files */
int main(int argc, char *argv[]) 
{
    FILE *fp;
    void filecopy(FILE *, FILE *);

    char *prog = argv[0];

    if (argc == 1)
        filecopy(stdin, stdout);
    else
    {
        while (--argc > 0)
        {
            if ((fp = fopen(*++argv, "r")) == NULL)
            {
                fprintf(stderr, "%s: can't open %s\n",
                    prog, *argv);
                exit(1);
            }
            else
            {
                filecopy(fp, stdout);
                fclose(fp);
            }
        }
    }

    if(ferror(stdout))
    {
        fprintf(stderr, "%s: error writing stdout\n", prog);
        exit(2);
    }

    exit(0);
}

#endif
void filecopy(FILE *ifp, FILE *ofp)
{
    int c;
    while((c=getc(ifp)) != EOF)
        putc(c, ofp);
}
