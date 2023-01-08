"""
    Problem statement:
    Your friend is typing his name into a keyboard. Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.

    You examine the typed characters of the keyboard. Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.
"""


def isLongPressedName(name:str, typed:str)->bool:
    if len(typed) < len(name):
        return False
    i = 0
    j = 0
    kt = None
    kn = None
    while i < len(name) and j < len(typed):
        kn = i + 1
        countN = 1
        c = name[i]
        while kn < len(name) and c == name[kn]:
            kn += 1
            countN += 1
        kt = j
        countT = 0
        while kt <len(typed) and c == typed[kt]:
            kt += 1
            countT += 1
        if countT >= countN:
            i = kn
            j = kt
        else:
            return False
    return kt == len(typed) and kn == len(name)


in11="alex"
in12 ="aaleex"
in21 = "saeed"
in22 = "ssaaedd"
print( "My answer for isLongPressedName(in11,in12) = " , isLongPressedName(in11,in12)  , " and the right answer is True")
print( "My answer for isLongPressedName(in21,in22) = " , isLongPressedName(in21,in22) , " and the right answer is False" )      

