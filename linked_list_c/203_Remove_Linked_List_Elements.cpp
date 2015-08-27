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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* tmp1 = new ListNode(0),*tmp2;
		tmp1->next = head;
		tmp2 = tmp1;
		while (tmp1->next!=NULL)
		{
			if (tmp1->next->val==val)
				tmp1->next = tmp1->next->next;
			else
				tmp1=tmp1->next;
		}
		return tmp2->next;
    }
};
int main(void)
{
	ListNode *l1=NULL;
	Solution mysolution;
	int a[]={};
	CreateList(&l1,a,(int)sizeof(a)/sizeof(*a));
	PrintList(mysolution.removeElements(l1,1));
	return 1;
}