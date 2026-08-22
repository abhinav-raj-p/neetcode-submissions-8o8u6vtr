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
        ListNode* dummy=new ListNode(0);
        dummy->next=head;

        ListNode* first=dummy;
        ListNode* second=dummy;
        ListNode* prev;
        n=n+1;
        while(n){
            first=first->next;
            n--;
        }

        while(first!=nullptr){
            second=second->next;

            first=first->next;
        }
        
        second->next=second->next->next;
        return dummy->next;
    }

};
