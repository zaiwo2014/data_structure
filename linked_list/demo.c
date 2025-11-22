//
// Created by leung on 2025/11/22.
//


#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int val;
    struct node* next_node;
    struct node* pre_node;
} node;

typedef struct linked_list {

    node* head;
    node* tail;

} linked_list;




//头插法 不带哨兵
void insert_to_head(node* insert_node, linked_list* linked_list) {
    if (linked_list->head == NULL) {
        // 空链表情况
        linked_list->head = insert_node;
        linked_list->tail = insert_node;
        insert_node->pre_node = NULL;
        insert_node->next_node = NULL;
    } else {
        // 非空链表情况
        node* first_node = linked_list->head;
        insert_node->next_node = first_node;
        first_node->pre_node = insert_node;
        insert_node->pre_node = NULL;
        linked_list->head = insert_node;
    }
}

//尾插法
void insert_to_tail(node *insert_node, linked_list *linked_list) {
    if (linked_list->tail == NULL) {
        // 处理空链表情况
        linked_list->head = insert_node;
        linked_list->tail = insert_node;
        insert_node->pre_node = NULL;
        insert_node->next_node = NULL;
    } else {
        // 正常尾插情况
        node *current_tail = linked_list->tail;
        current_tail->next_node = insert_node;
        insert_node->pre_node = current_tail;
        insert_node->next_node = NULL;
        linked_list->tail = insert_node;
    }
}

//遍历链表
//遍历链表
void traverse_linked_list(linked_list linked_list) {
    if (linked_list.head == NULL)
        return;
    else {
        node *current_node = linked_list.head;
        while (current_node != NULL) {
            printf("%d ", current_node->val);
            current_node = current_node->next_node;
        }
        printf("\n");
    }
}



linked_list* init_linked_list() {
    return malloc(sizeof(struct linked_list));
}


// 释放整个链表内存
void free_linked_list(linked_list* list) {
    if (list == NULL) return;

    node* current = list->head;
    while (current != NULL) {
        node* temp = current;
        current = current->next_node;
        free(temp);
    }

    list->head = NULL;
    list->tail = NULL;
}

int main(int argc, char *argv[]) {
    linked_list my_list = {NULL, NULL};
    for (int i = 0; i < 50; i++) {
        node* new_node = (node*)malloc(sizeof(node)); // 分配堆内存
        new_node->val = i;
        new_node->next_node = NULL;
        new_node->pre_node = NULL;
        insert_to_head(new_node, &my_list); // 直接传入指针
    }

    traverse_linked_list(my_list);

    free_linked_list(&my_list);

}




