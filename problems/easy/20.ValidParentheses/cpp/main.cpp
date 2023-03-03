#include <string>
#include <stack>
#include <unordered_map>
/*
    Problem statement:
    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

    An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.
*/
using namespace std;

bool isValidParentheses(string s) {
    stack<char> st;
    unordered_map<char,char> m={
                               {'{','}'},
                               {'(',')'},
                               {'[',']'}
                               };
    for(auto c : s){
        if(st.size() && c == m[st.top()])
            st.pop();
        else st.push(c);
    }
    return st.size()==0;
}


int main(){


    return 0;
}