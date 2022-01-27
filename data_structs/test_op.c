/*
* @Author: root
* @Date:   2017-03-21 14:08:50
* @Last Modified by:   root
* @Last Modified time: 2017-03-30 19:41:50
*/

#include "mylib.h"

bool op1()
{
    printf("op1 exec.\n");
    return false;
}

bool op2()
{
    printf("op2 exec.\n");
    return true;
}

bool powof2(unsigned int x)
{
    return x && !(x&(x-1));
}
/* bitcount: count 1 bits in x */
int bitcount(unsigned int x)
{
    int b;
    for(b = 0;x != 0; x >>= 1)
    {
        if (x & 01)
            b++;
    }
    return b;
}

int bitcount1(unsigned int x)
{
    int b=0;
    while(x)
    {
        x = x&(x-1);
        b++;
    }
    return b;
}


void possibleSubset(char set[], int N)
{
    int i, j;
    for (i = 0; i < (1 << N); ++i)
    {
        printf("%d. { ", i);
        for (j = 0; j < N; ++j)
        {
            if (i & (1 << j))
                printf("%c ",set[j]);
        }
        printf("}\n");
    }
}

/** normal implementation */
int binary_search(int arr[], int x, int size)
{
    int low, high, mid;
    low = 0;
    high = size - 1;
    while(low <= high)
    {
        mid = (low+high)/2;
        if (x == arr[mid])
            return mid;
        else if(x < arr[mid])
            high = mid - 1;
        else 
            low = mid + 1;
    }
    return -1;
}

/**
 * recursive implementation of binary search
 * @param  arr   [description]
 * @param  x     [description]
 * @param  start [description]
 * @param  end   [description]
 * @return       [description]
 */
int binary_search1(int arr[], int x, int start, int end)
{
    if (start > end)
        return -1;
    int mid = (start+end)/2;
    if(arr[mid] == x)
        return mid;
    else if(arr[mid] < x)
        return binary_search1(arr, x, mid+1, end);
    return binary_search1(arr, x, start, mid-1);
}

int my_atoi(char s[])
{
    int i, n, sign;
    for(i = 0;isspace(s[i]);i++)
        ;
    sign = (s[i] == '-')? -1:1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (n=0;isdigit(s[i]);i++)
        n = 10*n + (s[i] - '0');
    return sign*n;
}

double my_atof(char s[])
{
    double val, power;
    int i, sign;
    for(i = 0;isspace(s[i]);i++)
        ;
    sign = (s[i] == '-')? -1:1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val=0.0;isdigit(s[i]);i++)
        val = 10.0*val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power=1.0;isdigit(s[i]);i++)
    {
        val = 10.0*val + (s[i] - '0');
        power *= 10;
    }
    return sign*val/power;
}

void reverse(char s[])
{
    char temp;
    int i, j;
    for(i = 0, j = strlen(s) - 1; i<j; i++,j--)
        temp = s[i], s[i] = s[j], s[j] = temp;
}

void reverse_p(char s[])
{
    char temp, *start, *end;
    start = s;
    end = s + strlen(s) - 1;
    for (start = s, end = s + strlen(s) - 1; start < end; start++, end--)
        temp = *start, *start = *end, *end = temp;
}

void my_itoa(int n, char s[])
{
    int sign, i=0;
    unsigned int temp;
    if ((sign = n) < 0)
       temp = -n;
    else
        temp = n;
    do {
        s[i++] = temp%10 + '0';
    }while ((temp /= 10) > 0);
    if(sign<0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void my_itoa_length(int n, char s[], int minLength)
{
    int sign, i=0;
    unsigned int temp;
    if ((sign = n) < 0)
       temp = -n;
    else
        temp = n;
    do {
        s[i++] = temp%10 + '0';
    }while ((temp /= 10) > 0);
    if(sign<0)
        s[i++] = '-';
    while(i < minLength)
        s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}

/**
 * convert int to string on a certain base
 * @param n    [description]
 * @param s    [description]
 * @param base [description]
 */
void my_itob(int n, char s[], int base)
{
    int sign, curr, i=0;
    unsigned int temp;
    if ((sign = n) < 0)
       temp = -n;
    else
        temp = n;
    do {
        curr = temp%base;
        s[i++] = (curr < 10) ? (curr + '0'): (curr - 10 + 'A');
    } while ((temp /= base) > 0);
    if(sign<0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
#ifdef TEST_OP
int main() {
    bool x =false;
    x || op1();
    x && op2();

    x &= op2();

    int y  = 1;
    y = y++;
    printf("y:%d.\n", y);
    y = ++y;
    printf("y:%d.\n", y);
    unsigned int z = 128;
    printf("%d is power of 2: %s\n", z, powof2(z) ? "true":"false");
    printf("There are %d ones in number: %d\n", bitcount(z), z);
    printf("There are %d ones in number: %d\n", bitcount1(z), z);
    int size = 4;
    char set[4] = {'a','b','c','d'};
    possibleSubset(set, size);

    int n = 2;
    printf("%d %d\n",++n, 2*n);


    int a[4] = {0};
    int i=1, j;
    a[i] = i++;
    for (j =0;j<4;j++)
        printf("%d ",a[j]);

    int b[7] = {1,2,3,4,5,6,7};
    int val = 3;
    printf("\n%d in position %d\n", val, binary_search(b, val, sizeof(b)/sizeof(int)));
    printf("\n%d in position %d\n", val, binary_search1(b, val, 0, sizeof(b)/sizeof(int)));
    char str[] = "  -100";
    printf("%d\n", atoi(str));

    reverse(str);
    printf("%s\n", str);

    int minInt = -1*pow(2,sizeof(int)*8 - 1);
    char s[100]={0};
    printf("%d\n", minInt);
    unsigned int m = -1*minInt;
    printf("%u\n", m);
    my_itoa_length(minInt,s, 20);
    printf("%s\n", s);
    int zz = 23456;
    for(i =2;i <17;i++)
    {
        memset(s, sizeof(s), 0);
        my_itob(zz,s,i);
        printf("base: %d, %s\n", i, s);
    }
    char dbstr[100] = "-2.345f3";
    printf("%.3f\n", my_atof(dbstr));
    return 0;
}
#endif