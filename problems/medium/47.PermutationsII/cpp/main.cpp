#include <unordered_set>
#include <vector>

using namespace std;
/*
    Problem statement
    Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
*/

struct hashFunction {
    size_t operator()(const vector<int>& myVector) const {
        std::hash<int> hasher;
        size_t answer = 0;
        for (int i : myVector) {
            answer ^= hasher(i) + 0x9e3779b9 +
                      (answer << 6) + (answer >> 2);
        }
        return answer;
    }
};
using mySet = unordered_set<vector<int>, hashFunction>;

void helper(vector<int>& nums, int start, int end, vector<vector<int>>& ret, mySet& visited) {
    if (start == end && visited.find(nums) == visited.end()) {
        ret.push_back(nums);
        visited.insert(nums);
        return;
    }
    for (int i = start; i <= end; i++) {
        swap(nums[i], nums[start]);
        helper(nums, start + 1, end, ret, visited);
        swap(nums[i], nums[start]);
    }
}  // use hash table visited
vector<vector<int>> permuteUnique(vector<int>& nums) {
    mySet visited;
    vector<vector<int>> ret;
    helper(nums, 0, nums.size() - 1, ret, visited);
    return ret;
}


int main(){

    return 0;
}