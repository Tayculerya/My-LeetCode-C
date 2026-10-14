//24. 两两交换链表中的节点
//思路:先建立虚拟头节点，然后交换相邻两节点，最后释放虚拟头节点，返回原节点。
//复杂度：O(n)/O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
   struct ListNode* dummy=(struct ListNode*)malloc(sizeof(struct ListNode));
   dummy->next=head;
   struct ListNode* p=dummy;
   while(p->next!=NULL&&p->next->next!=NULL){
    struct ListNode* n1=p->next;
    struct ListNode* n2=n1->next;
    struct ListNode* newb=n2->next;
    p->next=n2;
    n2->next=n1;
    n1->next=newb;
    p=n1;
   }
   struct ListNode* newhead=dummy->next;
   free(dummy);
   return newhead;
   
}