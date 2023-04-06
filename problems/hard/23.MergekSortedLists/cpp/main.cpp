#include <iostream>
#include <list>
#include <numeric>
#include <random>
/*
    Problem statement
    You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
    Merge all the linked-lists into one sorted linked-list and return it.
*/

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct kHeap {
    int val;
    list<kHeap*> children;
    kHeap(int val) {
        this->val = val;
        children = list<kHeap*>(0);
    }
    void insert(int val) {
        if (children.size() == 0 || children.back()->val < val) {
            children.push_back(new kHeap(val));
        } else {
            kHeap* righParent(0);
            for (auto& child : children) {
                if (child->val >= val) {
                    righParent = child;
                    break;
                }
            }
            righParent->insert(val);
        }
    }
    void toVector(vector<int>& out) {
        for (auto& child : children) {
            if (child) {
                child->toVector(out);
                out.push_back(child->val);
            }
        }
    }
    void toList(ListNode* out) {
        vector<int> v;
        this->toVector(v);
        ListNode* add = out;
        for (int i = 0; i < v.size(); i++) {
            add->val = v[i];
            if (i < v.size() - 1) {
                add->next = new ListNode;
                add = add->next;
            }
        }
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.size() == 0)
        return nullptr;
    kHeap heap(0);
    bool notEmpty = true;
    for (int i = 0; i < lists.size(); i++) {
        ListNode* curr = lists[i];
        while (curr) {
            notEmpty = false;
            heap.insert(curr->val);
            curr = curr->next;
        }
    }
    if (notEmpty)
        return nullptr;
    ListNode* ret = new ListNode(0);
    heap.toList(ret);
    return ret;
}

int main() {
    cout << "----------------------INPUT-----------------------" << endl;

    int k = 5;
    // First create an instance of an engine.
    random_device rnd_device;
    // Specify the engine and distribution.
    mt19937 mersenne_engine{rnd_device()};  // Generates random integers
    uniform_int_distribution<int> sizDdist{1, 20};
    uniform_int_distribution<int> vecDdist{1, 100};

    vector<int> vSizes(k);
    generate(begin(vSizes), end(vSizes), [&sizDdist, &mersenne_engine]() { return sizDdist(mersenne_engine); });
    vector<int> ref(accumulate(vSizes.begin(), vSizes.end(), 0));
    int b, e, idx;
    b = e = idx = 0;
    vector<ListNode*> lists(k);
    for (auto& s : vSizes) {
        b = e;
        e += s;
        generate(ref.begin() + b, ref.begin() + e, [&vecDdist, &mersenne_engine]() { return vecDdist(mersenne_engine); });
        sort(ref.begin() + b, ref.begin() + e);
        ListNode* to_add = new ListNode;
        lists[idx] = to_add;
        for (int i = b; i < e; i++) {
            cout << ref[i] << " ";
            to_add->val = ref[i];
            if (i < e - 1) {
                to_add->next = new ListNode;
                to_add = to_add->next;
            }
        }
        idx++;
        cout << endl;
    }
    cout << "----------------------OUTPUT-----------------------" << endl;
    
    ListNode* lout = mergeKLists(lists);
    while (lout) {
        cout << lout->val << " ";
        lout = lout->next;
    }
    cout << endl;
    return 0;
}