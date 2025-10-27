#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct list_item {
    int value;
    struct list_item *next;
};
typedef struct list_item list_item;

struct list {
    struct list_item *head;
};
typedef struct list list;

void remove_cs101(list *l, list_item *target);
void remove_elegant(list *l, list_item *target);
void print_items(list *l, list_item *item1, list_item *item2);

void print_items(list *l, list_item *item1, list_item *item2)
{
    printf("l->head: %p\n"
           "l->head->value: %d\n"
           "item1->value: %d\nitem1->next: %p\n"
           "item2->value: %d\nitem2->next: %p\n",
           l->head, l->head->value,
           item1->value, item1->next, 
           item2->value, item2->next);
};

void remove_cs101(list *l, list_item *target)
{
    list_item *cur = l->head, *prev = NULL;
    while(cur != target){
        printf("cur != target: %b\n", cur != target);
        prev = cur;
        cur = cur->next;
    }
    printf("=========\n");
    printf("start: l->head -> %p, prev -> %p, cur -> %p\n", l->head, cur, prev);
    printf("start: l->head->value -> %d, prev -> %p, cur -> %p\n", l->head->value, cur, prev);
    printf("=========\n");
    if (prev)
        prev->next = cur->next;
    else
        l->head = cur->next;
    printf("end: l->head -> %p, prev -> %p, cur -> %p\n", l->head, cur, prev);
    printf("end: l->head->value -> %d, prev -> %p, cur -> %p\n", l->head->value, cur, prev);
    printf("=========\n\n");
};

void remove_elegant(list *l, list_item *target)
{
    list_item **p = &l->head;
    printf("=========\n");
    printf("start: *p -> %p\n", *p);
    printf("start: target -> %p\n", target);
    printf("start: *p->value -> %d\n", (*p)->value);
    printf("=========\n");
    while(*p != target)
        p = &(*p)->next;
    *p = target->next;
    printf("end: *p -> %p\n", *p);
    printf("end: *p->value -> %d\n", (*p)->value);
    printf("=========\n");
};

int main(void)
{
    list *l = malloc(sizeof(list));

    list_item *item1 = malloc(sizeof(list_item));
    list_item *item2 = malloc(sizeof(list_item));

    item1->value = 10;
    item2->value = 20;

    item1->next = item2;
    item2->next = NULL;

    l->head = item1;
    
    assert(l->head == item1);
    assert(item2 == item1->next);

    printf("==========\n");
    printf("l: %p\nitem1: %p\nitem2: %p\n", l, item1, item2);
    printf("==========\n");

    print_items(l, item1, item2);

    puts("\nremove_cs101:");
    remove_cs101(l, item1);

    printf("=============\n");
    printf("l->head: %p\n", l->head);
    printf("reset l->head to item1:\n");
    l->head = item1;
    printf("l->head: %p\n", l->head);
    printf("=============\n\n");

    print_items(l, item1, item2);

    puts("\nremove_elegant:");
    remove_elegant(l, item1);

    return 0;
};
