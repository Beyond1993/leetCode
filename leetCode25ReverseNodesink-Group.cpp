#include<iostream>
using namespace std;

struct ListNode {
      int val;
       ListNode *next;
       ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* reverse(ListNode* pre, ListNode* suf){
        ListNode * last = pre->next;
        ListNode * current = last->next;
        while(current != suf){
            last->next = current->next;
            current->next = pre->next;
            pre->next = current;
            current = last->next;
        }


        return last;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k<=1) return head;
        ListNode * dumy = new ListNode(-1);
        dumy->next = head;
        ListNode * pre = dumy;
        ListNode * suf = head;
        int count = 0;
        while(suf != NULL){
            count ++;
            if(count%k ==0){
                //cout<<count<<endl;
                pre = reverse(pre,suf->next); // pay attention , this is suf->next,not suf, the key is pre and suf is not in the reverse area
                suf = pre->next;
            }else {
                suf = suf->next;
            }
        }

        return dumy->next; // can not be head, because head is 1, the dumy->next is 4

    }
};

int main(){
    Solution s;

    ListNode * node1 = new ListNode(1);
    ListNode * node2 = new ListNode(2);
    ListNode * node3 = new ListNode(3);
    ListNode * node4 = new ListNode(4);
    ListNode * node5 = new ListNode(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    ListNode * res = s.reverseKGroup(node1,2);

    while(res != NULL){
        cout<<res->val<<endl;
        res = res->next;
    }
    return 0;
}
