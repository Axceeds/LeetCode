#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* initListNode()
    {
        ListNode* head = new ListNode;

        ListNode* ori = head;
        for(int i=0;i<0;i++){
            ListNode* temp = new ListNode;
            temp->val = i;
            temp->next = nullptr;
            head->next = temp;
            head = head->next;
        }
        return ori;
    }
    
void ergodic(ListNode*head){
    // head = head->next;
    while(head!=nullptr){
        cout<<head->val;cout<<' ';
        head=head->next;
    }
    cout<<endl;
}
class Solution{
public:

    int getLength(ListNode *ptr){
        int length = 0;
        while(ptr!=nullptr){
            length ++;
            ptr = ptr->next;
        }
        return length;
    }
    ListNode* removeNthFromEnd(ListNode *head, int n){
        ListNode*dummy = new ListNode(0,head);
        ListNode*ptr = dummy;
        int length = getLength(head);
        for(int i=1;i<length-n+1;i++)
            ptr=ptr->next;
        ptr->next=ptr->next->next;
        return dummy->next;
    }
};

int main()
{
    Solution a = Solution();
    ListNode* head = initListNode();
    ergodic(head);
    cout<<a.getLength(head)<<endl;
    ergodic(a.removeNthFromEnd(head,3));
    system("pause");
    return 0;
}