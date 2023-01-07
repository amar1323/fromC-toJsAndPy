#include <iostream>
/*
    Problem statement:
    Given the head of a singly linked list, return true if it is a palindrome or false otherwise.*/
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* caller;
bool helper(ListNode* current){
    if(current){
        if(helper(current->next)==false) return false;
        if(current->val != caller->val) return false;
        caller=caller->next;
    }
    return true;
}

bool isPalindrome(ListNode* current){
    caller = current;
    return helper(current);
}

int main() {
    ListNode* in1 = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))));
    ListNode* in2 = new ListNode(1, new ListNode(2));

    cout << "My answer for isPalindrome(in1) = " << isPalindrome(in1)<< " and the right answer is 1" << endl;
    cout << "My answer for isPalindrome(in2) = " << isPalindrome(in2)<< " and the right answer is 0" << endl;
    return 0;
}