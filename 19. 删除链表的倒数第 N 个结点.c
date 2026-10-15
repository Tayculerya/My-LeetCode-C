//19. 删除链表的倒数第 N 个结点
//思路：快慢指针。
//复杂度：O(n)/O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* dummy=(struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next=head;
    struct ListNode* a=dummy,* b=dummy;
    for(int i=0;i<n;i++){
        a=a->next;
    }
    while(a->next!=NULL){
        a=a->next;
        b=b->next;
    }
    struct ListNode* e=b->next;
    b->next=b->next->next;
    free(e);
    struct ListNode* newhead=dummy->next;
    free(dummy);
    return newhead;
}