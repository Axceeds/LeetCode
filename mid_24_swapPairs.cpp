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
    ListNode* swapPairs(ListNode* head) {
        ListNode *tail = head;
        while(head){

        }

    }
};
int main(){
    Solution s;
    vector<int> v1 = {1,4,5};
    vector<int> v2 = {1,3,4};
    ListNode *list1 = initListNode(v1);
    ListNode *list2 = initListNode(v2);
    Solution s;

}