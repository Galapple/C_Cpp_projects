#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

struct node {
    int value;
    struct node* next;
}; typedef struct node node_t;

bool is_empty(node_t *head) {
    return head == NULL;
}

node_t *create_new_node(int value) {
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    return result;
}

node_t *insert_first(node_t *head, int value) {
    node_t *new_node = create_new_node(value);
    new_node->next = head;
    return new_node;
}

node_t* insert_last(node_t **head, int value) {
    node_t *temp = *head;
    node_t *new_node = create_new_node(value);
    if (*head == NULL) {
        *head = new_node;
    }
    else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    return new_node;
}

node_t *delete_last(node_t **head) {
    if (*head == NULL) return *head;
    else{
        node_t *temp = *head;
        node_t *new_end = NULL;
        while ((temp->next)->next != NULL) {
            temp = temp->next;
        }
        free((temp->next)->next);
        temp->next = NULL;
        return *head;
    }
   
}

node_t *delete_first(node_t **head) {
    if (*head != NULL) {
        node_t *temp = *head;
        free(head);
        *head = temp->next;
    }
    return *head;
}

node_t *find(node_t* head, int k) {
    node_t *temp = head;
    while (temp != NULL) {
        if (temp->value == k) return temp;
        temp = temp->next;
    }
    return temp;
}

void print_list(node_t *head) {
    node_t *tmp = head;
    while (tmp->next != NULL) {
        if (tmp->next == NULL) break;
        printf("%d->", tmp->value);
        tmp = tmp->next;
    }
    printf("%d", tmp->value);
}

node_t *delete_certain_value(node_t **head, int value) {
    node_t* temp = *head;
    node_t* prev_node;
    if (temp->value == value) {
        *head = temp->next;
        free(temp);
        return *head;
    }
    while (temp!= NULL) {
        prev_node = temp;
        temp = temp->next;
        if (temp->value == value) {
            prev_node->next = temp->next;
            free(temp);
            return *head;
        }
    }
    return *head;
}

int main() {
    node_t *head = NULL;
    node_t *found_element = NULL;
    int size, num, option;
    while (true) {
        printf("\n1.Insert elemnts to stack\n2.Print list\n3.Find element\n4.Pop\n5.Add elements to list\n6.Delete last\n7.Delete certain value\n");
        scanf("%d", &option);
        if (option == 1) {
            printf("\nHow many elements to add the stack?\n");
            scanf("%d", &size);
            printf("Enter %d numbers\n", size);
            for (int i = 0; i < size; i++) {
                scanf("%d", &num);
                head = insert_first(head, num);
            }
        }
        if (option == 2) print_list(head);

        if (option == 3) {
            printf("Insert value to search:\n");
            int k;
            scanf("%d", &k);
            found_element = find(head, k);
            if (found_element != NULL) {
                printf("The value was found in the list");
            }
            else printf("The value was not found in the list");
        }
        if (option == 4) {
            if (head == NULL) printf("The list is empty\n");
            else {
                node_t temp = *head;
                int poped_element = temp.value;
                printf("Deleted element is: %d\n", poped_element);
                delete_first(&head);
            }
            
        }
        if (option == 5) {
            printf("\nHow many elements to add the list?\n");
            scanf("%d", &size);
            printf("Enter %d numbers\n", size);
            for (int i = 0; i < size; i++) {
                scanf("%d", &num);
                insert_last(&head, num);
            }
        }
        if (option == 6) delete_last(&head);
        if (option == 7) {
            printf("Value to delete:\n");
            scanf("%d", &num);
            delete_certain_value(&head, num);
        }
    }

    return 0;
}
