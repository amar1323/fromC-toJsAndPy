#include <iostream>
/*
    Problem statement:
    You are given the heads of two sorted linked lists list1 and list2.
    Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
    Return the head of the merged linked list.
*/
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1==nullptr && list2==nullptr) return nullptr;
    if(list1==nullptr && list2) return list2;
    if(list1 && list2==nullptr) return list1;
    ListNode* ret = new ListNode();
    ListNode* merged = ret;
    while(list1 && list2){
        if(list1->val <= list2->val){
            merged->next = list1;
            list1 = list1->next;
        }else{
            merged->next = list2;
            list2 = list2->next;      
        }
        merged = merged->next;
    }
    merged->next = list1==nullptr ? list2  : list1;
    return ret->next;
}
int main(){

    ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(4, new ListNode(10,new ListNode(20)))));
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6)))));

    ListNode* ret = mergeTwoLists(l1,l2);
    cout << "My answer to mergeTwoLists(l1,l2) =   ";
    while(ret){
        cout<<ret->val<<" ";
        ret = ret->next;
    }
    cout<< "   and the right answer is : 1 1 2 3 4 4 5 6 10 20"<<endl;
    return 0;
}