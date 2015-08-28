#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void AppendList(ListNode** head, int value)
{
    ListNode *appnode = new ListNode(value);
	ListNode *temp = *head;
	if (*head == NULL)
	{
		*head = appnode;
	}
	else
	{
		while(temp->next!=NULL)
			temp = temp->next;
        temp->next = appnode;
	}
}

void CreateList(ListNode** head, int* array,int n)
{
	int i;
	
	for (i=0;i<n;i++)
		AppendList(head,array[i]);
}

void PrintList(ListNode* head)
{
	ListNode * temp = head;
	while (temp != NULL)
	{
		cout<<temp->val<<endl;
		temp = temp->next;
	}	
}
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *head1=new ListNode(0);
		ListNode *head2=new ListNode(0);
		ListNode *tmp1,*tmp2;
		ListNode *tmp;
		tmp1 = head1;
		tmp2 = head2;
		while (head!=NULL)
		{
			tmp=new ListNode(head->val);
		    if (head->val<x)
			{
				tmp1->next = tmp;
				tmp1 = tmp1->next;
			}
			else
			{
				tmp2->next = tmp;
				tmp2 = tmp2->next;
			}
			head = head->next;
				
		}
		tmp1->next = head2->next;
		return head1->next;
    }
};

int main(void)
{
	ListNode *l1=NULL,*l2=NULL;
	Solution mysolution;
	int a[]={1,4,3,2,5,2};

	CreateList(&l1,a,(int)sizeof(a)/sizeof(*a));

	PrintList(mysolution.partition(l1,3));
	
	return 1;
}