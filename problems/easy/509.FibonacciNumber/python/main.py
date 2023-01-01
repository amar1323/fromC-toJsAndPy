"""
    Problem statement:
    The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,
"""


def fib( n: int) -> int:
  if n == 0: return 0
  if n == 1: return 1
  f0 = 0
  f1 = 1
  ret=0
  for i in range(2,n+1):
      ret = f0 + f1
      f0 = f1
      f1 = ret
  return ret


print("My answer for climbStairs(2) = ", fib(2),  " and the right answer is 1")
print("My answer for climbStairs(3) = ", fib(3),  " and the right answer is 2")
print("My answer for climbStairs(4) = ", fib(4),  " and the right answer is 3")
        

