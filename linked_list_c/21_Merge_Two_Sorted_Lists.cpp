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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode(0),*tmp=head;

		while (l1!=NULL && l2!=NULL)
		{
			if (l1->val<l2->val)
			{
				tmp->next = l1;
				l1 = l1->next;
				tmp = tmp->next;
			}
			else
			{
				tmp->next = l2;
				l2 = l2->next;
				tmp = tmp->next;
			}
		}
		if (l1==NULL)
		{
			tmp->next = l2; return head->next;
		}
		else
		{
			tmp->next = l1; return head->next;
		}
    }
};

int main(void)
{
	ListNode *l1=NULL,*l2=NULL;
	Solution mysolution;
	int a[]={1};
	int b[]={};
	CreateList(&l1,a,(int)sizeof(a)/sizeof(*a));
	CreateList(&l2,b,(int)sizeof(b)/sizeof(*b));
	PrintList(mysolution.mergeTwoLists(l1,l2));
	return 1;
}