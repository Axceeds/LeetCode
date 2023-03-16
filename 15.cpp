#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *head) : val(x), next(head) {}
};
ListNode *initList(vector<int> v1)
{
    ListNode *head = new ListNode;
    ListNode *ori = head;

    for (int i = 0; i < v1.size(); i++)
    {
        ListNode *temp = new ListNode();
        temp->val = v1[i];
        head->next = temp;
        head = head->next;
    }
    return ori->next;
}
void ergodic(ListNode *head)
{
    while (head)
    {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
}
class Solution
{
public:
    //思路是再开一个新链表，然后把a，b交替插入进去。
    // ListNode* mergeTwoLists(ListNode*list1,ListNode*list2){
    //     ListNode*a,*b;
    //     if(list1==nullptr||list2==nullptr)
    //         return list1==nullptr?list2:list1;
    //     if(list1->val<=list2->val)
    //         a=list1,b=list2;
    //     else
    //         a=list2,b=list1;
    //     ergodic(a);
    //     ergodic(b);
    //     ListNode*h1=new ListNode();
    //     ListNode*h2=new ListNode();
    //     h1->val = a->val;
    //     h2->val = b->val;
    //     h1->next=h2;
    //     a=a->next;b=b->next;
    //     ListNode*head = h1;
    //     ListNode*temp;
    //     while(b!=nullptr&&a!=nullptr){
    //         ListNode*ptr1 = new ListNode();
    //         temp = head;
    //         ptr1->val = a->val;
    //         // while(!(temp->next==nullptr||(temp->val<=a->val<=temp->next->val))){
    //         //     temp=temp->next;
    //         // }
    //         while(temp->next!=nullptr){
    //             if(temp->val<=a->val&&a->val<=temp->next->val)
    //                 break;
    //             else
    //                 temp=temp->next;
    //         }
    //         ptr1->next=temp->next;
    //         temp->next=ptr1;

    //         ListNode*ptr2 = new ListNode();
    //         temp = head;
    //         ptr2->val = b->val;
    //         while(temp->next!=nullptr){
    //             if(temp->val<=b->val&&b->val<=temp->next->val)
    //                 break;
    //             else
    //                 temp=temp->next;
    //         }
    //         ptr2->next=temp->next;
    //         temp->next=ptr2;
    //         a=a->next;
    //         b=b->next;
    //     }
    //     if(!a&&!b)
    //         return head;
    //     else{
    //     ListNode*tail;
    //     tail = a==nullptr?b:a;
    //     temp = head;
    //     while(tail){
    //         ListNode *tempt = new ListNode();
    //         tempt->val = tail->val;
    //         while(temp->next!=nullptr){
    //             if(temp->val<=tail->val&&tail->val<=temp->next->val)
    //                 break;
    //             else
    //                 temp=temp->next;
    //         }
    //         tempt->next=temp->next;
    //         temp->next=tempt;
    //         tail=tail->next;
    //     }
    //     }

    // return head;
    // }

    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *a, *b;
        if (list1 == nullptr || list2 == nullptr)
            return list1 == nullptr ? list2 : list1;
        if (list1->val <= list2->val)
            a = list1, b = list2;
        else
            a = list2, b = list1;
        ListNode *head = a;
        ergodic(a);
        ergodic(b);

        while (b)
        {
        ListNode* temp = new ListNode(b->val);
        while(a->next!=nullptr){
            if(a->val<=temp->val&&temp->val<=a->next->val){
                cout<<"yes"<<endl;
                break;
            }  
            else
                a=a->next;
            }
        temp->next=a->next;
        a->next= temp;
    
        b=b->next;
        }
        return head;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *ans = nullptr;
        for (size_t i = 0; i < lists.size(); ++i)
        {
            ans = mergeTwoLists(ans, lists[i]);
        }
        return ans;
    }
};
int main()
{
    vector<int> v1 = {1,4,5};
    vector<int> v2 = {1,3,4};
    ListNode *list1 = initList(v1);
    ListNode *list2 = initList(v2);
    Solution s;

    ListNode *head = s.mergeTwoLists(list1, list2);
    ergodic(head);
    system("pause");
    return 0;
}
