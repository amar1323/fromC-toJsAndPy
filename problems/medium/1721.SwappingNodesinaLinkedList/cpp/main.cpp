#include <algorithm>

using namespace std;

/*
    Problem statement:
    You are given the head of a linked list, and an integer k.

    Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapNodes(ListNode* head, int k) {
   ListNode*  start= head, *end = head, *fast = head;
   for(int i=0; i<k;i++){
       fast=fast->next;
       if(i<k-1)
        start = start->next;
   }
   while(fast){
       end = end->next;
       fast = fast->next;
   }
   swap(end->val, start->val);
   return head;
}