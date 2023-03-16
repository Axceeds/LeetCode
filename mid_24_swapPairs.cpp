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
    ListNode* swapPairs(ListNode* head0) {
        ListNode*ori = new ListNode(0,head0);
        ListNode*head = ori;
        if(head->next==nullptr)
            return head->next;
        while(head->next&&head->next->next){
            ListNode *ta = head->next;
            ListNode *tb = head->next->next;
            ta->next=tb->next;
            tb->next = ta;
            head->next = tb;
            head=head->next->next;
        }
    // ergodic(ori);
    return ori->next;
    }
};
int main(){
    Solution s;
    vector<int> v1 = {};
    vector<int> v2 = {1,3,4};
    ListNode *list1 = initListNode(v1);
    ListNode *list2 = initListNode(v2);
    s.swapPairs(list1);
    system("pause");
    return 0;

}