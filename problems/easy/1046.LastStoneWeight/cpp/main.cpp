#include <vector>
#include <set>

/*
    Problem statement:
    You are given an array of integers stones where stones[i] is the weight of the ith stone.
    We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:
    If x == y, both stones are destroyed, and
    If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
    At the end of the game, there is at most one stone left.
    Return the weight of the last remaining stone. If there are no stones left, return 0.
*/

using namespace std;

int lastStoneWeight(vector<int>& stones) {
    multiset<int, std::greater<int>> ms(stones.begin(), stones.end());
    while(ms.size()>=2){
        multiset<int>::iterator itx = ms.begin();
        auto ity = itx;
        ity++;
        int x = *itx;
        int y = *ity;
        if(x>y) swap(x,y);
        if(x!=y){
            ms.insert(y-x);
        }
        ms.erase(itx);
        ms.erase(ity);
    }
    return ms.size()==0 ? 0 : *ms.begin();
}


int main(){

    return 0;
}