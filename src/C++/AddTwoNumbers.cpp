#include <iostream>

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) 
    {}
 };

void freeList(ListNode *head)
{
    while(head)
    {
        ListNode *temp = head->next;
        delete(head);
        head = temp;
    }
}

class Solution 
{
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int carry = 0;
        ListNode dummy(0, nullptr);
        ListNode *current = &dummy;
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

            ListNode *temp = new (std::nothrow) ListNode(sum % 10);
            if(!temp)
            {
                freeList(dummy.next);
                return nullptr;
            }
            carry = sum / 10;
            current->next = temp;
            current = temp;
        }
        return dummy.next;
    }
};

 int main()
 {
    ListNode n3(5, nullptr);
    ListNode n2(4, &n3);
    ListNode n1(3, &n2);
    ListNode *num1 = &n1;
    ListNode m3(9, nullptr);
    ListNode m2(9, &m3);
    ListNode m1(9, &m2);
    ListNode *num2 = &m1;
    ListNode *result = Solution().addTwoNumbers(num1, num2);
    if(!result)
        std::cout << "Failed to allocate memory for evaluating result!";
    else
    {
        ListNode *iterator = result;
        while(iterator)
        {
            std::cout << iterator->val << "->";
            iterator = iterator->next;
                
        }
        std::cout << "NULL";
    }
    freeList(result);
    std::cin.get();
    return 0;
 }