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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*longList;
        ListNode*shortList;
        if(getLength(l1)>=getLength(l2)){
            longList = l1;
            shortList = l2;
        }
        else{
            longList = l2;
            shortList = l1;
        }

        // ListNode*ll=reverse(longList);
        // ListNode*sl=reverse(shortList);
        ListNode*ll=longList;
        ListNode*sl=shortList;
        ergodic(ll);
        ergodic(sl);
        ListNode*result=new ListNode;
        ListNode*ori = result;
        int carry = 0;
        int sum = 0;
        while(ll!=nullptr){
            if(sl==nullptr)
                sum=ll->val+0+carry;
            else
                sum=ll->val+sl->val+carry;
            // cout<<sum<<' ';
            ListNode*temp=new ListNode;
            if(sum>=10){
                carry = 1;
                temp->val=sum%10;
            }
            else{
                carry = 0;
                temp->val=sum;
            }
            result->next = temp;
            result = temp;
            if(sl!=nullptr)
                sl=sl->next;
            ll=ll->next;
        }
        if (carry==1){
            ListNode*temp=new ListNode;
            temp->val=1;
            result->next = temp;
            result = temp;
        }
        return reverse(ori->next);
    }

};

int main()
{
    Solution a = Solution();
    vector<int> v1 = {1,2,3,4,5};
    ListNode* ll = initListNode(v1);
    ergodic(ll);


    system("pause");
    system("pause");
    return 0;
}