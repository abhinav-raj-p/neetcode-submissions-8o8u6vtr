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
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* next;
        ListNode* prev=nullptr;
        ListNode r;
        ListNode* i=head;
        // ListNode* temp;
        // ListNode* tail=&r;

        while(fast!=nullptr&&fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        
        }
        next=slow->next;
        slow->next=nullptr;
        slow=next;
        //temp=slow;
        while(slow!=nullptr){
            next=slow->next;
            slow->next=prev;
            prev=slow;
            slow=next;
        }
        
        while(prev!=nullptr){
            next=i->next;
            i->next=prev;
            prev=prev->next;
            i->next->next=next;
            i=next;




        }

        

    }
};
