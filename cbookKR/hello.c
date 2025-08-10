#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */
#define TAB 3

int max;
char line[MAXLINE]; /* current input line */
char longest[MAXLINE]; /* longest line saved here */

int getlinenew(void);
void copynew(void);
void reverse(char to[]);

/* print the longest input line */
int main()
{
    // int len;
    // extern int max;
    // extern char longest[];

    // max = 0;
    // while ((len = getlinenew()) > 0) {
    //     printf("len: %d\n", len);
    //     if (len > max) {
    //         max = len;
    //         copynew();
    //     }
    //     if (max > 0) {  /* there was a line */ 
    //         printf("%s", longest);
    //         reverse(longest);
    //         printf("%s\n", longest);
    //     }
    // }
    int c, i;
    i = 0;

    while ((c = getchar()) != EOF) {
        i++;
        if (c == '\n')
            i = 0; /* reset column counter */
        if (c == '\t') {
            while ((i % TAB) != 0) {
                printf("moduo %d and %d: %d.\n", i, TAB, (i % TAB));
                putchar('X');
                i++;
            }
            printf("moduo %d and %d: %d.\n", i, TAB, (i % TAB));
        } else {
            putchar(c);
        }

    }
    return 0;
}

/* getline: read a line into s, return length */
int getlinenew(void)
{
    int c, i;
    extern char line[];

    for (i=0; i < MAXLINE-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}
/* copy: copy 'from' into 'to'; assume to is big enough */
void copynew(void)
{
    int i;
    extern char line[], longest[];

    i = 0;
    while ((longest[i] = line[i]) != '\0')
        ++i;
}
void reverse(char s[])
{
    char ch;
    int i, j;

    for(j = 0; s[j] != '\0'; j++)
        ;

    if (j > 0 && (s[j - 1] == '\n')) {
        j--;
    }
    for(i = 0; i < j; i++)
    {
        ch   = s[i];
        s[i] = s[j];
        s[j] = ch;
        --j;
    }
}