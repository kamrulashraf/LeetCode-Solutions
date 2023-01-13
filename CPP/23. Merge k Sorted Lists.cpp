/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ret = NULL;
        
        if(lists.size() == 0){
            return NULL;
        }
        return merge(lists,0, lists.size()-1);
        
    }
    
    ListNode* merge( vector <ListNode*>& lists, int b , int e){
        if(b == e){
            return lists[b];
        }
        
        int m = (b+e)/2;
        
        ListNode* l = merge(lists, b, m);
        ListNode* r = merge(lists, m+1, e);
        
        return mergeList(l,r);
    }
    
    ListNode* mergeList(ListNode* a, ListNode* b){
        ListNode *ret = NULL, *head;
        
        if(a || b)
            ret = new ListNode();
        head = ret;
        while(a || b){
            if(!a){
                ret -> val = b -> val;
                b = b-> next;
            }
            else if(!b){
                ret -> val = a -> val;
                a = a -> next;
            }
            else{
                if(a-> val < b-> val){
                    ret -> val = a->val;
                    a = a-> next;
                }
                else{
                    ret -> val = b-> val;
                    b = b-> next;
                }
            }
            
            if(a || b){
                ret -> next = new ListNode();
                ret = ret -> next;
            }
        }
        
        return head;

    }
};