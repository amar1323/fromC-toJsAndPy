#include <vector>
#include <numeric>

/*
    Problem statement
    You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.
    Return true if you can make this square and false otherwise.
*/
using namespace std;


bool helper(vector<int>& matchsticks, int current, vector<bool>& used, int idx, int count,int target){
    if(count==3)
        return true;
    if(current == target)
        return helper(matchsticks,0, used, 0, count+1,target);
    for(int i=idx; i<matchsticks.size();i++){
        if(used[i] || current+matchsticks[i]>target) continue;
        used[i]=true;
        if(helper(matchsticks,current+matchsticks[i], used,i+1,count,target))
            return true;
        used[i]=false;
        if(current==0) // very important to skip if all number are used
            break;
    }
    return false;
}
bool makesquare(vector<int>& matchsticks) {
    int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
    if(sum%4!=0) return false;
    sum/=4;
    sort(matchsticks.begin(), matchsticks.end(), greater<int>());
    if(matchsticks[0]>sum) // very important to return false if one matchsticks is greater that target
        return false;
    vector<bool> used(matchsticks.size(),false);
    return helper(matchsticks,0,used,0,0,sum);
}


int main(){


    return 0;
}