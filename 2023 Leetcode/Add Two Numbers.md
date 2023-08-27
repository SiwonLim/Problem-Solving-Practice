[Problem]<br>
https://leetcode.com/problems/add-two-numbers/description/


[Answer1]
```java
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode answer = null;
        boolean carry = false;
        while(true){
            int val = 0;
            if(l1 != null){
                val = l1.val;
            }
            if(l2 != null){
                val += l2.val;
            }
            
            if(carry == true){
                val++;
            }

            if(val >= 10){
                carry = true;
            }else{
                carry = false;
            }
            if(answer == null){
                answer = new ListNode(val%10, null);
            }else{
                ListNode newNode = new ListNode(val%10, null);
                ListNode temp = answer;
                while(temp.next != null){
                    temp = temp.next;
                }
                temp.next = newNode;
            }
            if(l1 != null){
                l1 = l1.next;
            }
            if(l2 != null){
                l2 = l2.next;
            }
            
            if((l1==null) && (l2==null)){
                break;
            }
        }
        if(carry == true){
            ListNode newNode = new ListNode(1, null);
            ListNode temp = answer;
            while(temp.next != null){
                temp = temp.next;
            }
            temp.next = newNode;
        }
        return answer;
    }
}
```

[Answer2]
```java
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummyHead = new ListNode(0);
        ListNode tail = dummyHead;
        int carry = 0;

        while (l1 != null || l2 != null || carry != 0) {
            int digit1 = (l1 != null) ? l1.val : 0;
            int digit2 = (l2 != null) ? l2.val : 0;

            int sum = digit1 + digit2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode newNode = new ListNode(digit);
            tail.next = newNode;
            tail = tail.next;

            l1 = (l1 != null) ? l1.next : null;
            l2 = (l2 != null) ? l2.next : null;
        }

        ListNode result = dummyHead.next;
        dummyHead.next = null;
        return result;
    }
}
```
