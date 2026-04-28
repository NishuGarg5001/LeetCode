class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1, l2):
        carry = 0
        dummy = ListNode(0, None)
        current = dummy
        while l1 or l2 or carry:
            sum = carry

            if l1:
                sum += l1.val
                l1 = l1.next

            if l2:
                sum += l2.val
                l2 = l2.next

            temp = ListNode(sum % 10, None)
            carry = sum // 10
            current.next = temp
            current = temp
        return dummy.next

n3 = ListNode(5, None)
n2 = ListNode(4, n3)
n1 = ListNode(3, n2)
num1 = n1
m3 = ListNode(9, None)
m2 = ListNode(9, m3)
m1 = ListNode(9, m2)
num2 = m1
result = Solution().addTwoNumbers(num1, num2)
if not result:
    print("Failed to allocate memory for evaluating result!")
else:
    iterator = result
    while iterator:
        print(iterator.val, "->", sep="", end="")
        iterator = iterator.next
    print("NULL")
