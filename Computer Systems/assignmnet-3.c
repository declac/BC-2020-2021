/*
 * Program to build and represent a linked list of integers.
 *
 * Author: Declan McGranahan - aviram@bc.edu
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define USAGE "Please enter one of the following commands:\n" \
    "\ta <int> -- add <int> to the end of the list\n" \
    "\ti <index> -- insert <int> at position <index>\n" \
    "\tr <index> -- remove element from position <index>\n" \
    "\tq -- quit.\n"

typedef struct Node {
    int value;
    struct Node * next;
} Node;

typedef struct List {
    Node * head;
    int length;
} List;

/*
 * Returns a Node object allocated on the heap.
 */
Node * make_node(int value) {
    Node * new_node = (Node *)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

/*
 * Allocates a new List object on the stack.
 */
List make_list() {
    List new_list;
    new_list.head = NULL;
    new_list.length = 0;
    return new_list;
}

/*
 * Adds a new element with the given value to the end of the list.
 */
void add_element(List * list, int value) {
    Node * new_node = make_node(value);
    if (! list->head) {
        list->head = new_node;
    } else {
        Node * current = list->head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }
    ++list->length;
}

/*
 * Inserts a new element into the list with the given value at the position given by index.
 * If the index reaches beyond the end of the list, appends the new element to the end.
 */
void insert_element(List * list, int value, int index) {
    // If the index is nonsensical, just ignore it.
    if (index < 0) {
        return;
    }
    Node * new_node = make_node(value);
    if (index >= list->length) {
        add_element(list, value);
    } else if (index == 0) {
        new_node->next = list->head;
        list->head = new_node;
    } else {
        Node * current = list->head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        Node * rest = current->next;
        current->next = new_node;
        new_node->next = rest;
    }
    ++list->length;
}
/*
 * Function that takes a list as an input and the location of some element in the list.
 * It them traverses the list until it hits that index. Once that index is hit it removes the element.
 * In the processes the location is stored in a temp node called temp.
 */
void remove_element(List * list, int index) {
    int i = 0;
    // Store head node
    Node * temp = list->head;
    Node * prev;
    // If head node itself holds the index to be deleted
    if (temp != NULL && index == 0) {
        list->head = temp->next; // Changed head
        free(temp); // free old head
        return;
    }
    // Search for the index to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && i != index) {
        prev = temp;
        temp = temp->next;
        i++;
    }
    // If key was not present in linked list
    if (temp == NULL)
        return;
    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp); // Free memory
}
/*
 * Prints a visualization of the list.
 */
void print_list(List * list) {
    Node * current = list->head;
    while (current) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("null\n");
}

/*
 * De-allocates heap memory allocated for the Node objects in the list.
 */
void free_list(List * list) {
    Node * head = list->head;
    Node * current;
    while (head) {
        current = head;
        head = head->next;
        free(current);
    }
    list->head = NULL;
    list->length = 0;
}

/*
 * Takes user input to build and manipulate the list and print the results.
 */
int main(int argc, char * argv[]) {
    char c;
    int value;
    int index;
    List list = make_list();
    printf(USAGE);
    printf("> ");
    while (scanf("%c", &c) != EOF) {
        if (c == 'q') {
            while (getchar() != (int)'\n');
            break;
        }
        switch (c) {
            case 'a':
                scanf("%d", &value);
                add_element(&list, value);
                print_list(&list);
                break;
            case 'i':
                scanf("%d %d", &value, &index);
                insert_element(&list, value, index);
                print_list(&list);
                break;
            case 'r':
                scanf("%d", &index);
                remove_element(&list, index);
                print_list(&list);
                break;
            default:
                break;
        }
        while (getchar() != (int)'\n');
        printf("> ");
    }
    free_list(&list);
    return EXIT_SUCCESS;
}
