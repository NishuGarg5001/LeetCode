#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

void freeList(struct ListNode *head)
{
    while(head)
    {
        struct ListNode *next = head->next;
        free(head);
        head = next;
    }
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) 
{
    struct ListNode dummy = {0, NULL};
    struct ListNode *current = &dummy;
    int carry = 0;
    while(l1 || l2 || carry)
    {
        int sum = carry;

        if(l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }

        if(l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        struct ListNode *temp = malloc(sizeof *temp);
        if(!temp)
        {
            freeList(dummy.next);
            return NULL;
        }
        temp->val = sum % 10;
        temp->next = NULL;
        carry = sum / 10;

        current->next = temp;
        current = temp;
    }
    return dummy.next;
}

int main()
{
    struct ListNode num1 = {3, &(struct ListNode){4, &(struct ListNode){5, NULL}}};
    struct ListNode num2 = {9, &(struct ListNode){9, &(struct ListNode){9, NULL}}};
    struct ListNode *num1_ptr = &num1;
    struct ListNode *num2_ptr = &num2;
    struct ListNode *result = addTwoNumbers(num1_ptr, num2_ptr);
    if(!result)
        printf("Failed to allocate memory for evaluating result!");
    else
    {
        struct ListNode *iterator = result;
        while(iterator)
        {
            printf("%d->", iterator->val);
            iterator = iterator->next;
                
        }
        printf("NULL");
    }
    freeList(result);
    getchar();
    return 0;
}