from typing import List
"""
    Problem statement:
    A school is trying to take an annual photo of all the students. The students are asked to stand in a single file line in non-decreasing order by height. Let this ordering be represented by the integer array expected where expected[i] is the expected height of the ith student in line.

    You are given an integer array heights representing the current order that the students are standing in. Each heights[i] is the height of the ith student in line (0-indexed).

    Return the number of indices where heights[i] != expected[i].

"""


def heightChecker(heights:List[int])->int:
    expected = heights.copy()
    expected.sort()
    ret = 0
    for i in range(len(heights)):
        if heights[i] != expected[i]:
            ret += 1
    return ret


in1 = [1,1,4,2,1,3]
in2 = [5,1,2,3,4]
in3 = [1,2,3,4,5]
print( "My answer for heightChecker(in1) = " , heightChecker(in1) , " and the right answer is 3" )
print( "My answer for heightChecker(in2) = " , heightChecker(in2) , " and the right answer is 5" )
print( "My answer for heightChecker(in3) = " , heightChecker(in3) , " and the right answer is 0" )   

