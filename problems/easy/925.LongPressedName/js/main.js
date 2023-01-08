/*
    Problem statement:
    Your friend is typing his name into a keyboard. Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.

    You examine the typed characters of the keyboard. Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.

*/

/**
 * @param {string} name
 * @param {string} typed
 * @return {boolean}
 */

function isLongPressedName(name, typed) {
    if (typed.length < name.length) return false;
    let i = 0;
    let j = 0;
    let kt;
    let kn;
    while (i < name.length && j < typed.length) {
        kn = i + 1;
        let countN = 1;
        const c = name[i];
        while (c === name[kn]) {
            kn++;
            countN++;
        }
        kt = j;
        let countT = 0;
        while (c === typed[kt]) {
            kt++;
            countT++;
        }
        if (countT >= countN) {
            i = kn;
            j = kt;
        } else {
            return false;
        }
    }
    return kt === typed.length && kn === name.length;
}


const in11="alex";
const in12 ="aaleex";
const in21 = "saeed";
const in22 = "ssaaedd";
console.log( "My answer for isLongPressedName(in11,in12) = " , isLongPressedName(in11,in12)  , " and the right answer is true");
console.log( "My answer for isLongPressedName(in21,in22) = " , isLongPressedName(in21,in22) , " and the right answer is false" );