# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        #for reordering the list u have to split the linked list and then merge it back again
        slow=head
        fast=head.next
        while fast and fast.next:
            slow=slow.next
            fast=fast.next.next
        sec=slow.next
        slow.next=None
        prev=tmp=None
        while sec:
            tmp=sec.next
            sec.next=prev
            prev=sec
            sec=tmp
        sec=prev
        f=head
        while sec:
            tmp1=f.next
            tmp2=sec.next
            f.next=sec
            sec.next=tmp1
            f=tmp1
            sec=tmp2
