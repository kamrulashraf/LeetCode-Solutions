/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode MergeTwoLists(ListNode list1, ListNode list2) {
        ListNode ret = null, cur, save = null;
        while(list1 != null && list2 != null){
            if(list1.val < list2.val){
                cur = new ListNode(list1.val);
                list1 = list1.next;

            }
            else{
                cur = new ListNode(list2.val);
                list2 = list2.next;

            }
            
            if(ret == null){
                ret = cur;
                save = ret;
            }
            else{
                ret.next = cur;
                ret = ret.next;
            }
            
        }
        
        AddElementToNewList(ref ret, ref list1, ref save);
        
        AddElementToNewList(ref ret, ref list2, ref save);
        
        return save;
    }
    
    private void AddElementToNewList(ref ListNode ret, ref ListNode list, ref ListNode save){
        while(list != null){
            if(ret == null){
                ret = new ListNode(list.val);    
                save = ret;
            }
            else{
                ret.next =  new ListNode(list.val);
                ret = ret.next;
            }
            list = list.next;
        }
    }
}

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution1 {
    public ListNode MergeTwoLists(ListNode list1, ListNode list2) {
        ListNode ret = null, cur, save = null;
        while(list1 != null && list2 != null){
            if(list1.val < list2.val){
                cur = list1;
                list1 = list1.next;

            }
            else{
                cur = list2;
                list2 = list2.next;

            }
            
            if(ret == null){
                ret = cur;
                save = ret;
            }
            else{
                ret.next = cur;
                ret = ret.next;
            }
            
        }
        
        AddElementToNewList(ref ret, ref list1, ref save);
        
        AddElementToNewList(ref ret, ref list2, ref save);
        
        return save;
    }
    
    private void AddElementToNewList(ref ListNode ret, ref ListNode list, ref ListNode save){
        while(list != null){
            if(ret == null){
                ret = list;    
                save = ret;
            }
            else{
                ret.next =  list;
                ret = ret.next;
            }
            list = list.next;
        }
    }
}