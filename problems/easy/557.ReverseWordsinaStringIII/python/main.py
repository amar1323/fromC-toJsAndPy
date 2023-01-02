"""
    Problem statement:
    Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order
"""
def reverseWords(s: str) -> str:
  s = list(s)
  j=0
  for i in range(len(s)):
    ii = i-1
    if(s[i]==' '):
      while(j<ii):
        s[ii],s[j] = s[j],s[ii] 
        j+=1
        ii-=1
      j=i+1
  if j<len(s):
    i=len(s)-1
    while(j<i):
      s[i],s[j] = s[j],s[i] 
      j+=1
      i-=1  
  return ''.join(s)

in1 ="Let's take LeetCode contest"
in2 ="God Ding"

print( "My answer for reverseWords(in1) = ", reverseWords(in1), " and the right answer is s'teL ekat edoCteeL tsetnoc")
print( "My answer for reverseWords(in2) = ", reverseWords(in2), " and the right answer is doG gniD")

