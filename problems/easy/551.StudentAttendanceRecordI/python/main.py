from typing import List
"""
    Problem statement:
    You are given a string s representing an attendance record for a student where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:

    'A': Absent.
    'L': Late.
    'P': Present.
    The student is eligible for an attendance award if they meet both of the following criteria:

    The student was absent ('A') for strictly fewer than 2 days total.
    The student was never late ('L') for 3 or more consecutive days.
    Return true if the student is eligible for an attendance award, or false otherwise.
"""

def checkRecord(s: str) -> bool:
    ab = 0
    late = 0
    for i in range(len(s)):
        if s[i] == 'A':
            ab += 1
        if ab >= 2:
            return False
        if s[i] == 'L':
            while i<len(s) and s[i] == 'L':
                late += 1
                i += 1
            i -= 1
        if late >= 3:
            return False
        late = 0
    return True

print("My answer for checkRecord(\"PPALLP\") = " ,checkRecord("PPALLP"), " and the right answer is True")
print("My answer for checkRecord(\"PPALLL\") = " ,checkRecord("PPALLL"), " and the right answer is False")