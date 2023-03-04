#include <vector>
#include <numeric>
using namespace std;
/*
    Problem statement
    Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.
*/

bool helper(vector<int>& nums, int k, vector<int>& sums, int idx){
    if(idx==nums.size()){
        for(auto& s :sums){
            if(s != 0) return false;
        }
        return true;
    }
    for(int i=0; i<k;i++){
        if(sums[i]-nums[idx]<0) continue;
        int save = sums[i];
        sums[i]-=nums[idx];
        if(helper(nums,k,sums,idx+1)) return true;
        if(save==sums[i]) return false;
        sums[i]+=nums[idx];
    }
    return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k) {
    vector<bool> used(nums.size(),false);
    int sum = accumulate(nums.begin(),nums.end(),0);
    if(sum%k!=0) return false;
    sum /=k;
    sort(nums.begin(), nums.end(), greater<int>());
    if(nums[0]>sum) return false;
    vector<int> sums(k,sum);
    return helper(nums,k,sums,0);
}

int main(){

    vector<int> in = {3522,181,521,515,304,123,2512,312,922,407,146,1932,4037,2646,3871,269};
    auto ret = canPartitionKSubsets(in, 4);
    return 0;
}