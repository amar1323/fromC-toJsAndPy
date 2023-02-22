/*
    Problem statement:
    Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
*/
function ListNode(val) {
    this.val = val;
    this.next = null;
}

var getIntersectionNode = function(headA, headB) {
  let a = headA, b = headB
  while (a !== b) {
      a = !a ? headB : a.next
      b = !b ? headA : b.next
  }
  return a
};


//[4,1,8,4,5], [5,6,1,8,4,5]=> 8
const in11 = new ListNode(4, new ListNode(1, new ListNode(8, new ListNode(4, new ListNode(5)))));
const in12 = new ListNode(5, new ListNode(6, new ListNode(1, new ListNode(8, new ListNode(4, new ListNode(5))))));
//[1,9,1,2,4], [3,2,4] => 2
const in21 = new ListNode(1, new ListNode(9, new ListNode(1, new ListNode(2, new ListNode(4)))));
const in22 = new ListNode(3, new ListNode(2, new ListNode(4)));
//[2,6,4],[1,5]=>nullptr
const in31 = new ListNode(2, new ListNode(6, new ListNode(4)));
const in32 = new ListNode(1, new ListNode(5));
console.log("My answer for getIntersectionNode(in11,in12) = " , getIntersectionNode(in11,in12), " and the right answer is 8" );
console.log("My answer for getIntersectionNode(in21,in22) = " , getIntersectionNode(in21,in22), " and the right answer is 2" );
console.log("My answer for getIntersectionNode(in31,in32) = " , getIntersectionNode(in21,in22), " and the right answer is nullptr" );
