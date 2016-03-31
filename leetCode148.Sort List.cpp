#include<iostream>>
#include<vector>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:

    ListNode* getMiddle(ListNode * head){
        ListNode * fast = head;
        ListNode * slow = head;
        while(fast->next  && fast->next->next ){
            fast = fast->next->next;
            slow = slow->next;
        }

        //cout<<slow->val;
        return slow;
    }

    ListNode * merge(ListNode * start, ListNode * middle){
        ListNode * head = new ListNode(-1) ;
        ListNode * save = head;
        while(start && middle) {
            if(start->val <= middle->val){
                save->next = start;
                start = start->next;
            }
            else{
                save->next = middle;
                middle = middle->next;
            }
            //cout<<save->next->val;
            save = save->next;
        }

       if(start){
           save->next = start;
       }
       if(middle != NULL){
           save->next = middle;
       }

        return head->next;
    }

    ListNode * sort(ListNode * start){
        if( !start || !start->next )
            return start;

        ListNode * m = getMiddle(start);
        ListNode * next = m->next;
        m->next = NULL;
     //  while(start){
            //cout<<start->val;
       //     start = start->next;
       // }
        ListNode * h1 = sort(start);
        ListNode * m2 = sort(next);      //返回的头指针作为合并时的中点
        return merge(h1,m2);

    }

    ListNode* sortList(ListNode* head) {
        if(!head)
            return head;

       return sort(head);

    }
};
int main(){
    ListNode * head = new ListNode(1);
    ListNode * node2 = new ListNode(3);
    ListNode * node3 = new ListNode(2);
    ListNode * node4 = new ListNode(5);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    //while(head){
        //cout<<head->val<<endl;
       // head = head->next;
    //}

    Solution s;
    ListNode * res = s.sortList(head);
    while(res){
        cout<<res->val<<endl;
        res = res->next;
    }

    return 0;
}
