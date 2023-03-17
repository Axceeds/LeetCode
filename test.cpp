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

int main(){
    int a = 10,b=3;
    int c = a/b;
    cout << c;
    system("pause");
    return 0;
}