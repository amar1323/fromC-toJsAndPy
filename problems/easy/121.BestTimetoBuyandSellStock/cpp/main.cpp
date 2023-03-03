#include <vector>

using namespace std;
/*
    Problem statement:
    You are given an array prices where prices[i] is the price of a given stock on the ith day.

    You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

    Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/
int maxProfit(vector<int> p) {
    int minSoFar = p[0];
    int ret = 0;
    for(int i = 1; i<p.size(); i++){
        minSoFar = min(p[i], minSoFar);
        ret = max(ret, p[i]-minSoFar);
    }
    return ret;
}

int main(){

    return 0;
}