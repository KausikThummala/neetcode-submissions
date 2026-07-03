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
        if(lists.empty()){
            return nullptr;
        }
        //now we have to merge 2 sorted list at a time
        int n=lists.size();
        while(n>1){
            //similar to merged sort
            
            vector <ListNode *> merged;
            for(int i=0;i<n;i+=2){
                ListNode * l1=lists[i];
                ListNode *l2=(i+1<n) ? lists[i+1] : nullptr;
                merged.push_back(merge(l1,l2));
            }
            lists=merged;
            n=lists.size();
        }
        return lists[0];

        
    }
    ListNode * merge(ListNode * l1,ListNode *l2){
        ListNode dummy =ListNode();
        ListNode * tail=&dummy;
        while(l1 && l2){
            if(l1->val <l2->val){
                tail->next=l1;
                l1=l1->next;
            }
            else{
                tail->next=l2;
                l2=l2->next;
            }
            tail=tail->next;
        }
        if(l1) tail->next=l1;
        if(l2) tail->next=l2;
        return dummy.next;
    }
};
