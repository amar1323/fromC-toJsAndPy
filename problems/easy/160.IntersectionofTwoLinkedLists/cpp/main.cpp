#include <iostream>
#include <set>

/*
    Problem statement:
    Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
*/

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    set<ListNode*> sA;
    set<ListNode*> sB;
    while(headA || headB){
        if(headA){
            if(sB.find(headA)!= sB.end()) return headA;
            sA.insert(headA);
            headA=headA->next;
        }
        if(headB){
            if(sA.find(headB)!=sA.end()) return headB;
            sB.insert(headB);
            headB = headB->next;
        }
    }
    return nullptr;
}


int main() {
    //[4,1,8,4,5], [5,6,1,8,4,5]=> 8
    ListNode* in11 = new ListNode(4, new ListNode(1, new ListNode(8, new ListNode(4, new ListNode(5)))));
    ListNode* in12 = new ListNode(5, new ListNode(6, new ListNode(1, new ListNode(8, new ListNode(4, new ListNode(5))))));
    //[1,9,1,2,4], [3,2,4] => 2
    ListNode* in21 = new ListNode(1, new ListNode(9, new ListNode(1, new ListNode(2, new ListNode(4)))));
    ListNode* in22 = new ListNode(3, new ListNode(2, new ListNode(4)));
    //[2,6,4],[1,5]=>nullptr
    ListNode* in31 = new ListNode(2, new ListNode(6, new ListNode(4)));
    ListNode* in32 = new ListNode(1, new ListNode(5));

    cout << "My answer for getIntersectionNode(in11,in12) = " << getIntersectionNode(in11,in12)<< " and the right answer is 8" << endl;
    cout << "My answer for getIntersectionNode(in21,in22) = " << getIntersectionNode(in21,in22)<< " and the right answer is 2" << endl;
    cout << "My answer for getIntersectionNode(in31,in32) = " << getIntersectionNode(in31,in32)<< " and the right answer is nullptr" << endl;
    return 0;
}