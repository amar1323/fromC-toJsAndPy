/*
    Problem statement:
    Write a function to find the longest common prefix string amongst an array of strings.
    If there is no common prefix, return an empty string "".
*/

/**
 * @param {string[]} strs
 * @return {string}
 */
/*
string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0)
        return "";
    else if (strs.size() == 1)
        return strs[0];
    string ret;
    for (int i = 0; i < strs[0].size(); i++) {
        char c = strs[0][i];
        for (int j = 0; j < strs.size(); j++) {
            if (!(i < strs[j].size() && c == strs[j][i])) return ret;
        }
        ret += c;
    }
    return ret;
}
*/

var longestCommonPrefix = function(strs) {
    if(strs.length==0) return "";
    else if(strs.length==1) return strs[0];
    let ret="";
    for(let i = 0; i<strs[0].length;i++){
        let c = strs[0][i];
        for(let j =1; j<strs.length;j++){
            if(i >= strs[j].length || c != strs[j][i])
                return ret;
        }
        ret+=c;
    }
    return ret;
};

let in1 = ["flower","flow","flight"];
let in2 = ["dog","racecar","car"];

console.log("My answer for longestCommonPrefix(in1)= ", longestCommonPrefix(in1), " and real answer is: fl");
console.log("My answer for longestCommonPrefix(in2)= ", longestCommonPrefix(in2), " and real answer is: ");