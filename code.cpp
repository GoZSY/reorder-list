/************************************************************************/
/* 题目描述
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
You must do this in-place without altering the nodes' values.
For example,
Given{1,2,3,4}, reorder it to{1,4,2,3}.
解题思路：先将链表从中间分割，然后将后面的链表反转，在按顺序合并两个子链表   */
/************************************************************************/
#include <iostream>
using namespace std;
 
//Definition for singly - linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (head!=NULL)
        {
            ListNode *head1 = head;
            ListNode *head1last = getMiddle(head);
            ListNode *head2 = head1last->next;
            head1last->next = NULL;
 
            head2 = reverseList(head2);
            head = mergeList(head1, head2);
        }
    }
 
    ListNode* getMiddle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast!=NULL &&fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast->next!=NULL)
            {
                fast = fast->next;
            }
        }
        return slow;
    }
 
    ListNode* reverseList(ListNode *head)
    {
        ListNode *prelist = NULL;
        ListNode *nextlist = NULL;
        while (head!=NULL)
        {
            nextlist = head->next;
            head->next = prelist;
            prelist = head;
            head = nextlist;
        }
        return prelist;
    }
 
    ListNode* mergeList(ListNode *head1, ListNode *head2)
    {
        ListNode *head = head1;
        ListNode *head1last = head1->next;
        ListNode *head2last = head2->next;
        while (head2!=NULL)
        {
            head1->next = head2;
            head1 = head1last;
            if (head1last!=NULL)
            {
                head1last = head1last->next;
            }
            head2->next = head1;
            head2 = head2last;
            if (head2last!=NULL)
            {
                head2last = head2last->next;
            }
             
        }
        return head;
    }
};
