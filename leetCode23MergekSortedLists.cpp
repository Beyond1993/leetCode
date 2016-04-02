/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void swap(vector<ListNode*> &heap,int i,int j){
        ListNode * tmp;
        tmp = heap[i];
        heap[i] = heap[j];
        heap[j] = tmp;
    }
    void siftDown(vector<ListNode*> &heap,int i){
        int left  = 2*i + 1;
        int right = 2*i + 2;
        int min = i;
        if(left <= heap.size() -1 && heap[left]->val < heap[i]->val) {
            min = left;
        }
        
        if(right <= heap.size() -1 && heap[right]->val < heap[min]->val){
            min = right;
        }
        
        if(min != i){
            swap(heap,min,i);
            siftDown(heap,min);// 6 7 5 we find 5 < 6 so exchange 5 and 6 ,than right 5 become 6,might not is the heap
        }
    }
    void buildHeap(vector<ListNode*> &heap){
        int len = heap.size();
        for(int i =  (len-2)/2 ; i>=0;i--){ // the last leaf node's parent
            siftDown(heap , i);
        }    
    
    }
    
    void heapPush(vector<ListNode*> &heap, ListNode * node){
        heap.push_back(node);
        int currentNode = heap.size() -1;
        int i = (currentNode-1)/2;
        while(i>=0){
            if(heap[i]->val > heap[currentNode]->val){
                swap(heap,i,currentNode);
                currentNode = i;
                i = (currentNode -1)/2;
            }
            else break;
        }
    }
    
    ListNode * heapPop(vector<ListNode*> &heap){
        ListNode * res = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        siftDown(heap,0);
        return res;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        if( len == 0) return NULL;
        
        vector<ListNode*> heap;
        for(int i=0;i < len;i++){
            heap.push_back(lists[i]);
        }
        
        buildHeap(heap);
        
      //  for(int i=0;i<heap.size();i++){
     //       cout<<heap[i]->val<<" ";
     //   }
                
       // cout<<endl;
        ListNode*  head = new ListNode(-1);
        ListNode * p = head;
        while(!heap.empty()){
            ListNode * minNode = heapPop(heap);
            p->next = minNode;
            p = p->next;
            
            ListNode * next = minNode->next;
            if(next) heapPush(heap,next);
        
        }
        while(head){
            cout<<head->val<<" ";
        }
        return head->next;
    }
};