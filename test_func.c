/*
* @Author: root
* @Date:   2017-03-24 15:46:54
* @Last Modified by:   root
* @Last Modified time: 2017-04-26 18:06:46
*/

#include "include/mylib.h"
#include "include/mystruct.h"
#include <stdlib.h>

/**
 * return the index of t in s. 
 * @param  s [description]
 * @param  t [description]
 * @return   [description]
 */
int strindex(char s[], char t[])
{
    int i, j, k;
    for(i = 0; i < s[i] != '\0'; i++)
    {
        for (k = i, j = 0; j < strlen(t) && s[k] == t[j]; k++, j++)
            ;
        if (j > 0 && t[j] == '\0')
            return i;
    }
    return -1;
}

int r_strindex(char s[], char t[])
{
    if(strlen(t) == 0)
        return -1;
    int i, j, k;
    for(i = strlen(s)-1; i >= 0; i--)
    {
        for (k = i, j = strlen(t)-1; j >= 0 && s[k] == t[j]; k--, j--)
            ;
        if (j == -1)
            return i;
    }
    return -1;
}

int getline1(char s[], int lim)
{
    int c, i;
    i = 0;
    while(--lim > 0 && (c=getchar()) != EOF && c !='\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/**
 * recurive itoa
 * @param n [description]
 */
void printd(int n)
{
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }


    if (n/10)
        printd(n/10);
    putchar(n % 10 + '0');
}

/**
 * recurive reverse(s)
 */
void reverse_str(char s[])
{

}

void isBigEndian()
{
    Endian x;
    x.b = 1;
    printf("The machine is %s-Endian.\n", (x.a == 1) ? "Little" : "Big");
    unsigned int y = 1;
    printf("The machine is %s-Endian.\n", (((char*)&y)[0] == 1) ? "Little" : "Big");
}

void my_strcpy(char *s, char *t)
{
    while(*s++ = *t++)
        ;
}

int my_strcmp(char *s, char *t)
{
    return my_strcmp_r(s, t, 0);
}

int my_strcmp_r(char *s, char *t, int reverse)
{
    for(;*s==*t; s++,t++)
        if(*s=='\0')
            return 0;
    return reverse ? (*t - *s) : (*s - *t);
}

void my_strcat(char *s, char*t)
{
    while(*s != 0)
        s++;
    while(*s++ = *t++)
        ;

}

void findFirstDiffLine(char *f1, char *f2)
{
    FILE *fp1, *fp2;
    fp1 = fopen(f1, "r");
    if (fp1 == NULL)
    {
        puts("Open file f1 error!");
        return;
    }
    fp2 = fopen(f2, "r");
    if (fp2 == NULL)
    {
        puts("Open file f2 error!");
        fclose(fp1);
        return;
    }

    char line1[MAX_LINE], line2[MAX_LINE];

    while(fgets(line1, MAX_LINE, fp1) != NULL)
    {
        if(fgets(line2, MAX_LINE, fp2) != NULL)
        {
            if (my_strcmp(line1, line2) != 0)
            {
                puts("This line is different:");
                puts(line1);
                puts(line2);
            }
        }
    }

    fclose(fp1);
    fclose(fp2);

}

#ifdef TEST_FUNC
int main() {
    op1();
    char s[100] = "we have a very good very day.";
    char t[10] = "abcd";
    printf("%d\n", strindex(s, t));
    printf("%d\n", r_strindex(s, t));
    char lines[1000] = "i am a very good person.\n he is not a good person.\n we are good people.\n";
    //printd(-123456);
    int xx = 3;
    printf("\n%d\n", square(xx+1));
    dprint(10/5);

    int frontback = 10;
    printf("%d\n", paste(front, back));
    int x = 1, y = 2;
    swap1(int, x, y);
    printf("swap: x:%d, y:%d\n", x, y);
    isBigEndian();
    my_strcat(s,t);
    printf("after strcat: %s\n", s); 
    reverse_p(s);
    printf("after reverse: %s\n", s); 


    // test bit
    flags_t flag;
    printf("size of flags: %d\n", sizeof(flag));
    flag.is_keyword = flag.is_static = 0;
    printf("value of flags: %d\n", flag.is_keyword);

    int p[3] = {1, 2, 3};
    int *q = p;
    int m = 0;
    printf("0X%p\n", q);
    q++;
    printf("0X%p\n", q);

    findFirstDiffLine("/home/ctest/general_test/test1.txt", "/home/ctest/general_test/test2.txt");
    return 0;
}
#endif