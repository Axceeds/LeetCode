struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return head;
        ListNode*ori = new ListNode(0,head);
        ListNode*phead = head;
        ListNode*ptail = head;
        ListNode*ori2 = ori;
        while(ptail!=nullptr){
            while(ptail->val==phead->val){
                ptail=ptail->next;
                if(ptail==nullptr)
                    break;
            }
            if(phead->next==ptail){
                ori2 = phead;
                phead = ptail;
                
            }
            else{
                ori2->next=ptail;
                phead=ptail;


            }

        }
    return ori->next;
    }
};
