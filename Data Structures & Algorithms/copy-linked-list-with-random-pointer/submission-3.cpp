/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr=head;
        Node* copycurr;
        if (head == nullptr)
    return nullptr;

        while(curr!=nullptr){
            copycurr=new Node(curr->val);
            copycurr->next=curr->next;
            curr->next=copycurr;
            curr=copycurr->next;
        }
        curr=head;
        copycurr=curr->next;
        Node* ans=copycurr;
        while(curr!=nullptr){
            if(curr->random!=nullptr){
        copycurr->random=curr->random->next;
        
            }
            curr=copycurr->next;
            if(copycurr->next!=nullptr){
        copycurr=copycurr->next->next;
            }
           
           }
           curr=head;
           copycurr=curr->next;
          
           while(curr!=nullptr){
            copycurr=curr->next;
            curr->next=copycurr->next;
            
            if(copycurr->next!=nullptr){
            copycurr->next=copycurr->next->next;
            
            }
            
            curr=curr->next;
            }
    return ans;
    }

    
};
