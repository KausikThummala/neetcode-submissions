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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy= ListNode();
        dummy.next=head;
        ListNode * left=&dummy;
        ListNode * right=head;
        while (right && n>0){
            right=right->next;
            n-=1;
        }
        while(left && right){
            left=left->next;
            right=right->next;
        }
        left->next=left->next->next;
        return dummy.next;
    }
};
