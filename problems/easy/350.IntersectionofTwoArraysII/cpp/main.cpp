#include <vector>
#include <unordered_map>

using namespace std;
/*
    Problem statement:
    Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.
*/

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ret;
    if(nums1.size()> nums2.size()) swap(nums1, nums2);
    unordered_map<int,int> m;
    for(auto& n :nums1)
        m[n]++;
    for(auto& n: nums2){
        auto it = m.find(n);
        if(it != m.end() && (*it).second>0){
            ret.push_back(n);
            (*it).second--;
        }
    }
    return move(ret);
}

int main(){

    return 0;
}