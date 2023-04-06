#include <iostream>
#include <vector>
#include <limits>
#include <set>
/*
    Problem statement
    There is a garden withNslots. In each slot, there is a flower. TheNflowers will bloom one by one inNdays. In each day, there will beexactlyone flower blooming and it will be in the status of blooming since then.
    Given an arrayflowersconsists of number from1toN. Each number in the array represents the place where the flower will open in that day.
    For example,flowers[i] = xmeans that the unique flower that blooms at dayiwill be at positionx, whereiandxwill be in the range from1toN.
    Also given an integerk, you need to output in which day there exists two flowers in the status of blooming, and also the number of flowers between them iskand these flowers are not blooming.
    If there isn't such day, output -1.
*/
using namespace std;
bool isTrue(vector<bool>& lights, int k, int s, int e){
    int curr=0;
    for(int i=s; i<=e;i++){
        if(lights[i]==true){
            curr=0;
            continue;
        }
        curr++;
        if(curr==k && i+1<lights.size() && lights[i+1]) return true;
    }
    return false;
}

int kEmptySlots1(vector<int>& bulbs, int k) {
    vector<bool> lights(bulbs.size(),false);
    int minL = numeric_limits<int>::max();
    int maxL = numeric_limits<int>::min();
    for(int i=0; i<bulbs.size();i++){
        lights[bulbs[i]-1] = true;
        minL=min(minL, bulbs[i]-1);
        maxL=max(maxL, bulbs[i]-1);
        if(isTrue(lights,k,minL,maxL)) return i+1;
    }
    return -1;
}

int kEmptySlots(vector<int>& bulbs, int k) {
    set<int> s;
    for(int i=0; i< bulbs.size();i++){
        auto it = s.insert(bulbs[i]).first;
        if(it != s.begin()){
            auto itB = it; itB--;
            if(*it-*itB-1 == k) return i+1;
        }
        auto itA = it; itA++;
        if(itA != s.end()){
            if(*itA-*it-1 == k) return i+1;
        }
    }
    return -1;
}

int main(){
    vector<int> bulbs = {6,5,8,9,7,1,10,2,3,4};
    int k = 2;
    cout << " Reference solution of kEmptySlots(bulbs,k) = 8 and my solution is: " << kEmptySlots(bulbs,k) << endl;
    return 0;
}