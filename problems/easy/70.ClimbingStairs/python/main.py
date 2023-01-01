"""
    Problem statement:
    You are climbing a staircase. It takes n steps to reach the top.
    Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
"""


def climbStairs(n):
    """
    :type n: int
    :rtype: int
    """
    if(n==2): return 2
    if(n==1): return 1
    dp_0 = 1
    dp_1 = 2
    for i in range(2,n):
        ret = dp_0+dp_1
        dp_0 = dp_1
        dp_1 = ret
    return ret


print("My answer for climbStairs(2) = ", climbStairs(2),  " and the right answer is 2")
print("My answer for climbStairs(3) = ", climbStairs(2),  " and the right answer is 3")
print("My answer for climbStairs(5) = ", climbStairs(2),  " and the right answer is 8")
        

