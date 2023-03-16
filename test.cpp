#include <iostream>
using namespace std;
#include <vector>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
int getLength(ListNode *ptr){
        int length = 0;
        while(ptr!=nullptr){
            length ++;
            ptr = ptr->next;
        }
        return length;
    }
void ergodic(ListNode*head){
    // head = head->next;
    while(head!=nullptr){
        cout<<head->val;cout<<' ';
        head=head->next;
    }
    cout<<endl;
}
ListNode* initListNode(vector<int> v1)
    {
        
        ListNode* head = new ListNode;
        ListNode* ori = head;
        for(int i=1;i<=v1.size();i++){
            ListNode* temp = new ListNode;
            temp->val = i;
            temp->next = nullptr;
            head->next = temp;
            head = head->next;
        }
        return ori->next;
    }
ListNode* reverse(ListNode*ptr){
    ListNode*head = ptr;
    ListNode*nhead = new ListNode();
    nhead->val = head->val;
    head = head->next;
    while(head!=nullptr){
        ListNode *temp = new ListNode();
        temp->val = head->val;
        temp->next = nhead;
        nhead = temp;
        // delete temp;
        head = head->next;
    }
    return nhead;
}
class Solution{
public:
    ListNode* abc;


    

};

int main()
{
    Solution a = Solution();
    vector<int> v1 = {1,2,3,4,5};
    ListNode* ll = initListNode(v1);
    ergodic(ll);


    system("pause");
    return 0;
}