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
        ListNode* tmp = new ListNode(0),*tmp1;
		tmp->next = head;
		tmp1 = tmp;
		if (head==NULL || head->next==NULL) return head;
		while (tmp->next!=NULL)
		{
			int flag = 0;
			while (tmp->next->next!=NULL && tmp->next->val==tmp->next->next->val)
			{
				flag = 1;
				tmp->next->next = tmp->next->next->next;
			}
			if (flag ==1) tmp->next = tmp->next->next;
			else
				tmp = tmp->next;
		}
		return tmp1->next;
    }
};

int main(void)
{
	ListNode *l1=NULL;
	Solution mysolution;
	int a[]={1,1,1,2};

	CreateList(&l1,a,(int)sizeof(a)/sizeof(*a));
	
	PrintList(l1);
	cout<<endl;
	PrintList(mysolution.deleteDuplicates(l1));
	return 1;
}