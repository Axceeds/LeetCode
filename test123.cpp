
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
ListNode* initList(vector<int> v1)
    {
        
        ListNode* head = new ListNode;
        ListNode* ori = head;
        for(int i=0;i<v1.size();i++){
            ListNode* temp = new ListNode;
            temp->val = v1[i];
            temp->next = nullptr;
            head->next = temp;
            head = head->next;
        }
        return ori->next;
    }
class Solution {
public:
ListNode* mergeTwoLists(ListNode*list1,ListNode*list2){
        ergodic(list1);
        ergodic(list2);
        ListNode*a,*b;
        if(list1==nullptr||list2==nullptr)
            return list1==nullptr?list2:list1;
        if(list1->val<=list2->val)
            a=list1,b=list2;
        else
            a=list2,b=list1;
        
        ergodic(a);
        ergodic(b);
        ListNode*h1=new ListNode();
        ListNode*h2=new ListNode();
        h1->val = a->val;
        h2->val = b->val;
        h1->next=h2;
        a=a->next;b=b->next;
        ListNode*head = h1;
        while(b!=nullptr&&a!=nullptr){
            ListNode*temp = h1;
            ListNode*ptr1 = new ListNode(a->val);
            while(!(temp->next==nullptr||(temp->val<=a->val<=temp->next->val))){
                temp=temp->next;    
            }
            ptr1->next=temp->next;
            temp->next=ptr1;
            h1 = ptr1;
            ListNode*temp = h2;
            ListNode*ptr1 = new ListNode(b->val);
            while(!(temp->next==nullptr||(temp->val<=b->val<=temp->next->val))){
                temp=temp->next; 
            }
            ptr1->next=temp->next;
            temp->next=ptr1;
            h2 = ptr1;
            a=a->next;
            b=b->next;
        }       
    return head;
    }
};
int main()
{
    vector<int> v1 = {1,3,3,5,7};
    vector<int> v2 = {2,3,3,4,9};
    ListNode*list1 = initList(v1);
    ListNode*list2 = initList(v2);
    cout<<"yes"<<endl;
    Solution s;
    ListNode*head =  s.mergeTwoLists(list1,list2);
    system("pause");
    return 0;
}