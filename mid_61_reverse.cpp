struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int getLength(ListNode*head){
    int length = 0;
    while(head){
        length++;
        head = head->next;
    }
    return length;
}
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head){
            return head;
        }
        ListNode*phead = head;
        ListNode*ptail = head;
        int length=getLength(head);
        // cout<<"length="<<length<<endl;
        while(ptail->next){
            ptail=ptail->next;
        }
        ptail->next = head;
        int reo = length-k%length;
        // cout <<"result = " <<reo <<endl;
        for(int i=0;i<reo;i++){
            phead=phead->next;
            ptail=ptail->next;
        }
        ptail->next = nullptr;
        return phead;
    }
};
