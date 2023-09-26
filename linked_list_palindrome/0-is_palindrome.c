#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
#include <stddef.h>


/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to pointer to the head of the list
 *
 * Return: 1 if the list is a palindrome, 0 otherwise
 */

int is_palindrome(listint_t **head)
{
    listint_t *slow_ptr = *head;
    listint_t *fast_ptr = *head;
    listint_t *prev_slow_ptr = *head;
    listint_t *mid = NULL;
    listint_t *first_half = *head;
    listint_t *second_half = NULL;
    listint_t *current = slow_ptr;
    listint_t *next = NULL;
    int is_palindrome = 1;

    if (*head == NULL || (*head)->next == NULL)
    {
        return 1;
    }

    while (fast_ptr != NULL && fast_ptr->next != NULL) {
        fast_ptr = fast_ptr->next->next;
        prev_slow_ptr = slow_ptr;
        slow_ptr = slow_ptr->next;
    }

    if (fast_ptr != NULL) {
        mid = slow_ptr;
        slow_ptr = slow_ptr->next;
    }

    while (current != NULL) {
        next = current->next;
        current->next = second_half;
        second_half = current;
        current = next;
    }

    while (second_half != NULL) {
        if (first_half->n != second_half->n) {
            is_palindrome = 0;
            break;
        }
        first_half = first_half->next;
        second_half = second_half->next;
    }

    current = slow_ptr;
    next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = second_half;
        second_half = current;
        current = next;
    }

    if (mid != NULL) {
        prev_slow_ptr->next = mid;
        mid->next = second_half;
    } else {
        prev_slow_ptr->next = second_half;
    }

    return is_palindrome;
}
