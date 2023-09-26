#include <stdio.h>
#include <stdlib.h>

/* Definition for singly-linked list */
typedef struct listint_s {
    int n;
    struct listint_s *next;
} listint_t;

int is_palindrome(listint_t **head)
{
    /* Check for empty list or list with only one element (considered a palindrome) */
    if (*head == NULL || (*head)->next == NULL) {
        return 1;
    }

    listint_t *slow_ptr = *head;
    listint_t *fast_ptr = *head;
    listint_t *prev_slow_ptr = *head;
    listint_t *mid = NULL;
    int is_palindrome = 1;

    /* Use Floyd's Tortoise and Hare algorithm to find the middle of the list */
    while (fast_ptr != NULL && fast_ptr->next != NULL) {
        fast_ptr = fast_ptr->next->next;
        prev_slow_ptr = slow_ptr;
        slow_ptr = slow_ptr->next;
    }

    /* If the list has an odd number of nodes, skip the middle node */
    if (fast_ptr != NULL) {
        mid = slow_ptr;
        slow_ptr = slow_ptr->next;
    }

    /* Reverse the second half of the list */
    listint_t *second_half = NULL;
    listint_t *current = slow_ptr;
    listint_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = second_half;
        second_half = current;
        current = next;
    }

    /* Compare the first half and the reversed second half */
    listint_t *first_half = *head;
    while (second_half != NULL) {
        if (first_half->n != second_half->n) {
            is_palindrome = 0;
            break;
        }
        first_half = first_half->next;
        second_half = second_half->next;
    }

    /* Restore the original list by reversing the reversed second half again */
    current = slow_ptr;
    next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = second_half;
        second_half = current;
        current = next;
    }

    /* Reconnect the first half with the middle node (if exists) and the second half */
    if (mid != NULL) {
        prev_slow_ptr->next = mid;
        mid->next = second_half;
    } else {
        prev_slow_ptr->next = second_half;
    }

    return is_palindrome;
}
