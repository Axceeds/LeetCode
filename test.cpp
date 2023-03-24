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
int sum(int a,int b=2){
    cout<<"using1"<<endl;
    cout<<a+b<<endl;
    return a+b;
}
double sum(double a, double b){
    cout<<"using2"<<endl;
    cout<<a+b<<endl;
    return a+b;
}

void shift(vector<pair<int, int>>& nums) {
for (size_t i = 0; i < nums.size(); ++i) {
auto [num1, num2] = nums[i];
num1++;
num2++;
}
}
struct test{
    int a;
    char b;
};
int main(){
    int x;
    while(1){
        cin>>x;
        cout<<x<<endl;
    }
    system("pause");
    return 0;
}