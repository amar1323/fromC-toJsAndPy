from typing import List, Optional
"""
    Problem statement:
    Given the head of a singly linked list, return true if it is a palindrome or false otherwise.*

"""

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
        
def helper(current: Optional[ListNode], caller: List[Optional[ListNode]]) -> bool:
    if current:
        if not helper(current.next, caller):
            return False
        if current.val != caller[0].val:
            return False
        caller[0] = caller[0].next
    return True

def isPalindrome(current: Optional[ListNode]) -> bool:
    return helper(current, [current])


in1 =  ListNode(1,  ListNode(2,  ListNode(2,  ListNode(1))))
in2 =  ListNode(1,  ListNode(2))

print("My answer for isPalindrome(in1) = " , isPalindrome(in1),  " and the right answer is True")
print("My answer for isPalindrome(in2) = " , isPalindrome(in2),  " and the right answer is False")