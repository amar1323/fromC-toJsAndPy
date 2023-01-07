"""
    Problem statement:
    Write an algorithm to determine if a number n is happy.

    A happy number is a number defined by the following process:

    Starting with any positive integer, replace the number by the sum of the squares of its digits.
    Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
    Those numbers for which this process ends in 1 are happy.
    Return true if n is a happy number, and false if not.
"""


def isHappy(n: int) -> bool:
    save = set()
    while True:
        save.add(n)
        happy = 0
        while n > 0:
            r = n % 10
            happy += (r * r)
            n = (n - r) // 10
        if happy == 1:
            return True
        elif happy in save:
            break
        n = happy
    return False


print("My answer for isHappy(19) = ",isHappy(19), " and the right answer is True")
print("My answer for isHappy(2) = ",isHappy(2), " and the right answer is False")
        

