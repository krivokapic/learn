#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

// parameters are pointers
static char *mystrcpy(char *dest, char *src)
{
    char *p = dest;
    while (*src)
    {
        *p++ = *src++;
    }
    *p = '\0';
    return dest;
}
// parameters are arrays
static char *mystrcpy2(char dest[], char src[])
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

static int *int_copy(int *dest, int *src, int n)
{
    int *p = dest;
    while (n-- > 0)
        *p++ = *src++;

    return dest;
}

static int sum(int a, int b){
    return a + b;
}

static size_t mystrlen(const char *s)
{
    size_t i = 0;
    while (*s){
        i++;
        s++;
    }
    return i;
}

static void mystrcat(char *dest, char *src)
{
    while (*dest)
        dest++;
    while ((*dest++ = *src++))
        ;
}

static char* mystrchr(char *src, char target)
{
    while (*src)
    {
        if (*src == target)
            return src;
        src++;
    };

    return NULL;
}

struct tag {
    char lname[20];
    char fname[20];
    int age;
    float rate;
};

struct tag my_struct;
void show_name(struct tag *p);

void show_name(struct tag *p)
{
    printf("%s %s %d\n", p->fname, p->lname, p->age);
}

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

// invert a linked list with a pointer to the head
Node *invert(Node *head) //reverse a linked list pointed by head
{
    Node *P,*q,*r;

    //initial  values of P, q and r
    P=NULL;
    q=head;
    r=q->next;

    //until all nodes have reversed
    while(q!=NULL)
    {
        q->next=P;
        P=q;
        q=r;

        if(r!=NULL)
            r=r->next;
    }

    return P;
}

// invert a linked list with a double pointer to the head
void invert_double(Node **head)
{
    Node *p = NULL, *q = *head, *r;

    //until all nodes have reversed
    while(q!=NULL)
    {
        r = q->next;
        q->next=p;
        p=q;
        q=r;
    }
}

#define MAX 5
int main(void)
{
    srand(time(NULL));

    Node** nodes = malloc(sizeof(Node*) * MAX);

    for (int i = MAX-1; i >= 0; i--)
    {
        nodes[i] = malloc(sizeof(Node));
        nodes[i]->data = rand() % 101;
        if(i < MAX-1)
            nodes[i]->next = nodes[i + 1];
        else
            nodes[i]->next = NULL;
    }
    printf("before invert\n");
    for (int i = 0; i < MAX; i++)
    {
        printf("node[%d] -> %p\n", i, (void*)nodes[i]);
        printf("\tdata: %d\n", nodes[i]->data);
        printf("\tnext: %p\n", (void*)nodes[i]->next);
    }

    invert_double(nodes);

    printf("after invert\n");

    for (int i = MAX-1; i >= 0; i--)
    {
        printf("node[%d] -> %p\n", i, (void*)nodes[i]);
        printf("\tdata: %d\n", nodes[i]->data);
        if(nodes[i]->next != NULL)
            printf("\tnext: %p\n", (void*)nodes[i]->next);
        else
            printf("\tnext: NULL\n");
    }

    free(nodes);

    //head->data = 1;
    //head->next = element1;

    //element1->data = 2;
    //element1->next = element2;

    //element2->data = 3;
    //element2->next = NULL;

    //printf("Original list is : %d %d %d\n", head->data, element1->data, element2->data);

    //head = invert(head);

    //printf("Inverted list is : %d %d %d\n", head->data, element1->data, element2->data);

    //free(head);
    return 0;
}
