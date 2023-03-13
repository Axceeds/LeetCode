#include <iostream>
#include <vector>
using namespace std;
struct listNode
{
    int val;
    listNode* next;
    listNode() : val(123),next(nullptr) {}
    listNode(int x) : val(x), next(nullptr){}
    listNode(int x ,listNode* head): val(x),next(head){}
};
listNode* initList(vector<int> v1){
    listNode*head = new listNode;
    listNode*ori = head;
    cout<<head->val;
    if(head->next==nullptr)
        cout<<"yes"<<endl;
    for(int i=0;i<v1.size();i++){
        listNode*temp = new listNode;
        temp->val=v1[i];
        head->next=temp;
        head=head->next;
    }
    return ori->next;
}
void ergodic(listNode*head){
    while(head){
        cout<<head->val<<' ';
        head=head->next;
    }
}
int main()
{
    vector<int> v1 = {1,8,3,5,7};
    listNode*head = initList(v1);
    ergodic(head);
    system("pause");
    return 0;

}
