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
    void reorderList(ListNode* head) {

        if(!head || !head -> next)
            return;

        ListNode *cur = head, *prev = NULL;
        stack<ListNode*> st;
        while(cur){
            st.push(cur);
            cur = cur->next;
        }

        int sz = (st.size())/2;
        bool isOdd = st.size()&1;
        
        cur = head;
        while(sz--){
            ListNode* next = cur -> next;
            cur -> next = st.top();
            cur ->next -> next = next;
            prev = cur-> next;
            cur = next;
            st.pop();
        }
        if(isOdd){
            prev -> next -> next = NULL;
        }
        else
            prev -> next = NULL;
    }
};