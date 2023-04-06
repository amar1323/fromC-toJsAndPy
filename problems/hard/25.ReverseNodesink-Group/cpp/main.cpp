#include <iostream>
#include <list>
#include <numeric>
#include <random>
#include <stack>
/*
    Problem statement
    Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
    k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
    You may not alter the values in the list's nodes, only nodes themselves may be changed.
*/
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == nullptr)
        return nullptr;
    stack<int> s;
    ListNode* ret = new ListNode;
    ListNode* grow = ret;
    while (head) {
        while (s.size() < k && head) {
            s.push(head->val);
            head = head->next;
        }
        if (s.size() == k) {
            while (s.size() > 0) {
                grow->val = s.top();
                s.pop();
                if (s.size() > 0 || head) {
                    grow->next = new ListNode;
                    grow = grow->next;
                }
            }
        }
    }
    if (s.size() > 0) {
        stack<int> sInverse;
        while (s.size() > 0) {
            sInverse.push(s.top());
            s.pop();
        }
        while (sInverse.size() > 0) {
            grow->val = sInverse.top();
            sInverse.pop();
            if (s.size() > 0) {
                grow->next = new ListNode;
                grow = grow->next;
            }
        }
    }
    return ret;
}

int main() {
    int size = 23;
    int k = 4;
    // First create an instance of an engine.
    random_device rnd_device;
    // Specify the engine and distribution.
    mt19937 mersenne_engine{rnd_device()};  // Generates random integers
    uniform_int_distribution<int> vecDdist{1, 100};

    vector<int> vec(size);
    generate(begin(vec), end(vec), [&vecDdist, &mersenne_engine]() { return vecDdist(mersenne_engine); });
    ListNode* list = new ListNode;
    ListNode* grow = list;
    for (size_t i = 0; i < vec.size(); i++) {
        grow->val = vec[i];
        if (i < vec.size() - 1) {
            grow->next = new ListNode;
            grow = grow->next;
        }
    }
    cout << endl;
    grow = list;
    cout << "-----------------------INPUT:list, k="<< k<<"-----------------------" << endl;
    while (grow) {
        cout << grow->val << " ";
        grow = grow->next;
    }
    cout << endl;
    ListNode* check = reverseKGroup(list, k);

    cout << "-----------------------OUTPUT-----------------------" << endl;
    while (check) {
        cout << check->val << " ";
        check = check->next;
    }
    cout << endl;
    return 0;
}