#ifndef MY_LIB_H
#define MY_LIB_H

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE 1000

#define max(a,b) ((a) > (b) ? (a) : (b))
#define square(x) (x)*(x)
#define dprint(expr) printf(#expr " = %g\n", expr)
#define paste(front, back) front ## back

//#define TEST_FUNC
//#define MY_CP
//#define MY_CAT
//#define TEST_OP
//#define MY_GREP
//#define QUICK_SORT
//#define MY_STRUCT
#define HASHMAP

#define swap1(t, x, y) \
{\
	typeof(t) SWAP = x; \
	x = y;\
	y = SWAP;\
}\

typedef union EndianStruct{
	char a;
	unsigned short b;
} Endian;

bool op1();
bool op2();
int bitcount(unsigned int x);
int bitcount1(unsigned int x);
void possibleSubset(char set[], int N);
int binary_search(int arr[], int x, int size);
int binary_search1(int arr[], int x, int start, int end);
int my_atoi(char s[]);
double my_atof(char s[]);
void my_itoa(int n, char s[]);
void my_itoa_length(int n, char s[], int minLength);
void my_itob(int n, char s[], int base);
int getline1(char[], int);
void printd(int);
void isBigEndian();

/* string related */
void my_strcpy(char *, char *t);
int my_strcmp(char*, char*);
int my_strcmp_r(char*, char*, int);
void reverse_str(char[]);
void reverse_p(char s[]);
int strindex(char s[], char t[]);
int r_strindex(char s[], char t[]);
void reverse(char*);
void my_strcat(char*, char*);


/* compare */
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void my_qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *, int), int reverse);
int numcmp(char *, char *);
int numcmp_r(char *, char *, int);
void swap(void *v[], int, int);

void findFirstDiffLine(char*, char*);



/* file related */

#endif