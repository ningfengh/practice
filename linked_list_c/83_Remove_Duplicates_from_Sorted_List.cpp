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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* tmp = head;
		while (tmp!=NULL)
		{
			while (tmp->next!=NULL && tmp->val==tmp->next-> val)
			{
				tmp->next = tmp->next->next;

			}
			tmp = tmp->next;
		}
		return head;
    }
};

int main(void)
{
	ListNode *l1=NULL;
	Solution mysolution;
	int a[]={};

	CreateList(&l1,a,(int)sizeof(a)/sizeof(*a));
	
	PrintList(l1);
	PrintList(mysolution.deleteDuplicates(l1));
	return 1;
}