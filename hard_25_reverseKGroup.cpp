#include <iostream>
#include <vector>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x, ListNode *head):val(x),next(head){}
};
ListNode*initListNode(vector<int> v1){
    ListNode*head = new ListNode();
    ListNode*ori = head;
    for(int i=0;i<v1.size();i++){
        ListNode*temp = new ListNode(v1[i]);
        head->next = temp;
        head = temp;
    }
    return ori->next;
}
void ergodic(ListNode*head){
    while(head){
        cout<<head->val<<' ';
        head=head->next;
    }
    cout << endl;
}
class Solution {
public:
    int getLength(ListNode *head){
        int i=0;
        while(head){
            head=head->next;
            i++;
        }
        return i;
    }
    ListNode* reverseKGroup(ListNode* head0, int k)  {
        if(head0==nullptr)
            return head0;
        ListNode*ori = new ListNode(0,head0);
        ListNode*head = ori;
        ListNode*nori = new ListNode(0);
        ListNode*nhead = nori;
        int length = getLength(head0);
        int epoch = length / k;
        for(int i=0;i<epoch;i++){
            ListNode *temp = head->next;
            ListNode *tmphead = new ListNode(temp->val);
            ListNode *tmp2 = tmphead;
            for(int j=1;j<k;j++){
                temp=temp->next;
                ListNode *tmp0 = new ListNode(temp->val);
                tmp0->next=tmphead;
                tmphead =tmp0;
            }
            nhead->next = tmphead;
            nhead = tmp2;  
            head = temp;

        }
        ListNode *temp = ori;
        for(int s=0;s<epoch*k;s++){
            temp = temp->next;  
        }
        nhead->next = temp->next;
        // ergodic(nori->next);
        return nori->next;

    }
    
};
int main(){
    Solution s;
    vector<int> v1 = {1,2,3,4,5,7,8,9,10};
    vector<int> v2 = {1,3,4};
    ListNode *list1 = initListNode(v1);
    ListNode *list2 = initListNode(v2);
    s.reverseKGroup(list1, 2);
    system("pause");
    return 0;

}