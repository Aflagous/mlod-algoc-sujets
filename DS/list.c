#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


List *list_create(void) {
    List *l = malloc(sizeof(List));
    l->first = l->last = NULL;
    return l;
}

size_t list_count(const List *list) {
    size_t count = 0;

    ListNode *p=list->first;
    while(p!=NULL) {
        count++;
        p=p->next;
    }

    return count;
}

void list_addlast(List *list, data_t item_data) {
    ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
    new_node->data = item_data;
    new_node->next = NULL;
    
    if (list->first == NULL) {
        list->first = new_node;
        list->last = new_node;
        new_node->prev = NULL;
    } else {
        new_node->prev = list->last;
        list->last->next = new_node;
        list->last = new_node;
    }
}

data_t list_rmlast(List *list) {
    data_t removed_data = list->last->data;
    ListNode *temp = list->last;
    if (list->first == list->last) {
        list->first = NULL;
        list->last = NULL;
    } else {
        list->last = list->last->prev;
        list->last->next = NULL;
    }
    free(temp);
    return removed_data;
}

void list_print(const List *list) {
    ListNode *act = list->first;
    printf("List elements: ");
    while (act != NULL) {
        printf("%d ", act->data);
        act = act->next;
    }
    printf("\n");
}

int main(void) {

    List *l = list_create();

    assert(list_count(l)==0);

    list_addlast(l,10);
    list_addlast(l,20);
    list_addlast(l,30);
    list_addlast(l,40);

    assert(list_count(l)==4);

    list_print(l);

    data_t t =  list_rmlast(l);

    assert(t==40);
    list_print(l);

    return 0;
}
