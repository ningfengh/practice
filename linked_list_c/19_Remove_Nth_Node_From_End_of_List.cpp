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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i;
		ListNode* tmp1=new ListNode(0), *tmp2,*tmp3;
		tmp1->next = head;
		tmp2 = tmp1;
		tmp3 = tmp1;
		
		for (i=0;i<n;i++)
			tmp2 = tmp2->next;
		while (tmp2->next!=NULL)
		{
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
		tmp1->next = tmp1->next->next;
		return tmp3->next;
			
    }
};

int main(void)
{
	ListNode *l1=NULL;
	Solution mysolution;
	int a[]={1};
	CreateList(&l1,a,(int)sizeof(a)/sizeof(*a));
	PrintList(mysolution.removeNthFromEnd(l1,0));
 
	return 1;
}