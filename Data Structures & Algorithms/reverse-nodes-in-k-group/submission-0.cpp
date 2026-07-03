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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //maintain a dummy node
        ListNode dummy =ListNode();
        ListNode * tmp=NULL;
        dummy.next=head;
        ListNode * grpp=&dummy;
        while (true){
            ListNode *kth=getKth(grpp,k);
            if(!kth) break;
            ListNode * grpn=kth->next;
            ListNode * prev=kth->next;
            ListNode *curr=grpp->next;
            while(curr!=grpn){
                tmp=curr->next;
                curr->next=prev;
                prev=curr;
                curr=tmp;
            }
            //now maintain order
            tmp=grpp->next;
            grpp->next=kth;
            grpp=tmp;

        }
        return dummy.next;
        
        
    }
    ListNode * getKth(ListNode *curr,int n){
        while(curr && n>0){
            curr=curr->next;
            n-=1;
        }
        return curr;
    }
};
