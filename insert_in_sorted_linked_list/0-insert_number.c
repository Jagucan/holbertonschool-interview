#include <stdlib.h>

typedef struct listint_s {
    int n;
    struct listint_s *next;
} listint_t;

listint_t *insert_node(listint_t **head, int number) {

    listint_t *current;

    listint_t *new_node = malloc(sizeof(listint_t));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->n = number;

    if (*head == NULL || number < (*head)->n) {
        new_node->next = *head;
        *head = new_node;
        return new_node;
    }

    current = *head;

    while (current->next != NULL && current->next->n <= number) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;

    return new_node;
}
