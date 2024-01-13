[Problem]<br>
https://leetcode.com/problems/merge-two-sorted-lists


[Answer 1]
```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
     public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode result = null;
        ArrayList<Integer> arr = new ArrayList<>();
        while(list1 != null){
            arr.add(list1.val);
            list1 = list1.next;
        }
        while(list2 != null){
            arr.add(list2.val);
            list2 = list2.next;
        }
        Collections.sort(arr);
        for(int i = 0 ; i < arr.size() ; i++){
            ListNode head = result;
            ListNode newNode = new ListNode(arr.get(i), null);
            if(result == null){
                result = newNode;
            }else{
                while(head.next != null){
                    head = head.next;
                }
                head.next = newNode;
            }
        }
        return result;   
    }
}
```

[Answer 2]
```java
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {

        if(list1!=null && list2!=null){
        if(list1.val<list2.val){
            list1.next=mergeTwoLists(list1.next,list2);
            return list1;
            }
            else{
                list2.next=mergeTwoLists(list1,list2.next);
                return list2;
        }
        }
        if(list1==null)
            return list2;
        return list1;
    }
}
```
