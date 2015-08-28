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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *head_new = new ListNode(0);
		ListNode *tail;
		ListNode *tmp1,*tmp2,*tmp3;
		int i;
		head_new->next = head;
		tmp1 = head_new;
		for (i=0;i<m-1;i++)
			tmp1 = tmp1->next;
		tmp2 = tmp1->next;
		head = tmp2->next;
		if (head!=NULL)	tmp3 = head->next;
		
		for (i=0;i<n-m;i++)
		{
			head->next = tmp2;
			tmp2 = head;
			head = tmp3;
			if (tmp3!=NULL)	tmp3 = tmp3->next;
		}
		tmp1->next->next = head;
		tmp1->next = tmp2;
		return head_new->next;
		
    }
};

int main(void)
{
	ListNode *l1=NULL;
	Solution mysolution;
	int a[]={1};

	CreateList(&l1,a,(int)sizeof(a)/sizeof(*a));
	PrintList(mysolution.reverseBetween(l1,1,1));
 
	return 1;
}