/*
    Problem statement:
    You are given the heads of two sorted linked lists list1 and list2.
    Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
    Return the head of the merged linked list.
*/


function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val);
    this.next = (next===undefined ? null : next);
}

/**
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */

var mergeTwoLists = function(list1, list2) {
  if(list1==null && list2==null) return list1;
  if(list1==null && list2!=null) return list2;
  if(list1!=null && list2==null ) return list1;
  let ret = new ListNode();
  let merged = ret;
  while(list1 != null && list2!=null){
    if(list1.val <= list2.val){
      merged.next = list1;
      list1 = list1.next;
    }else{
      merged.next = list2;
      list2 = list2.next;
    }
    merged = merged.next;
  }
  merged.next = (list1==null) ? list2 : list1;
  return ret.next;
};

let l1 = new ListNode(1, new ListNode(2, new ListNode(4, new ListNode(10,new ListNode(20)))));
let l2 = new ListNode(1, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6)))));

let ans = mergeTwoLists(l1,l2);
let out = "My answer to mergeTwoLists(l1,l2) =   ";
while(ans != null){
  out += (ans.val+" ");
  ans = ans.next;
}
out += "   and the right answer is : 1 1 2 3 4 4 5 6 10 20";
console.log(out);
