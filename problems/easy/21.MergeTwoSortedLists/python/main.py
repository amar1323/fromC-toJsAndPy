from typing import Optional
"""
    Problem statement:
    You are given the heads of two sorted linked lists list1 and list2.
    Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
    Return the head of the merged linked list.
"""

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def mergeTwoLists(list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
    if list1==None and list2==None: return list1
    if list1!=None and list2==None: return list1
    if list1==None and list2!=None: return list2

    merged = ListNode()
    ret = merged
    while list1 != None and list2!= None :
        if list1.val<= list2.val:
            merged.next = list1
            list1 = list1.next
        else:
            merged.next = list2
            list2 = list2.next
        merged = merged.next
    if list1 == None: merged.next = list2
    else: merged.next = list1
    return ret.next
    
l1 = ListNode(1, ListNode(2, ListNode(4, ListNode(10,ListNode(20)))))
l2 = ListNode(1, ListNode(3, ListNode(4, ListNode(5, ListNode(6)))))

ans = mergeTwoLists(l1,l2)
out = "My answer to mergeTwoLists(l1,l2) =   "
while ans != None:
    out += (str(ans.val)+" ")
    ans = ans.next

out += "   and the right answer is : 1 1 2 3 4 4 5 6 10 20"
print(out)



