struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head){
            return head;
        }
        ListNode*lessNode = new ListNode();
        ListNode*largeNode = new ListNode();
        ListNode*ple = lessNode;
        ListNode*pla = largeNode;
        while(head){
            ListNode*temp = new ListNode(head->val);
            if(temp->val<x){
                ple->next = temp;
                ple = temp;
            }
                
            else{
                pla->next = temp;
                pla = temp;

            }
        head = head->next;
        }
        ple->next = largeNode->next;
    return lessNode->next;
    }
};