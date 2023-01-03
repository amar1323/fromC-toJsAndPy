#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>

/*
    Problem statement:
    Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.
*/
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() < nums2.size())
        swap(nums2, nums1);
    // nums1.size > nums2.size
    vector<int> ret;
    unordered_set<int> s2(nums2.begin(), nums2.end());
    for (auto& n1 : nums1) {
        auto it = s2.find(n1);
        if (it != s2.end()) {
            ret.push_back(n1);
            s2.erase(it);
        }
        if (s2.size() == 0)
            break;
    }
    return ret;
}

int main() {
    vector<int> num11 = {1,2,2,1};
    vector<int> num12 = {2,2};
    vector<int> num21 = {4,9,5};
    vector<int> num22 = {9,4,9,8,4};

    string pr1,pr2;
    auto ans1 = intersection(num11,num12);
    auto ans2 = intersection(num21,num22);
    for(auto& c : ans1)
        pr1+=(to_string(c)+" ");
    pr1.pop_back();
    for(auto& c : ans2)
        pr2+=(to_string(c)+" ");
    pr2.pop_back();
    cout << "My answer for intersection(num11,num22) = " << pr1<< " and the right answer is {2}" << endl;
    cout << "My answer for intersection(num11,num22) = " << pr2<< " and the right answer is {9,4}" << endl;
    return 0;
}