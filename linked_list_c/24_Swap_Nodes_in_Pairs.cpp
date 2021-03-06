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
    ListNode* swapPairs(ListNode* head) {
        ListNode *tmp0 = new ListNode(0),*tmp1,*tmp2,*tmp3,*tmp4;
		tmp0->next = head;
		tmp1 = tmp0;
		while (tmp1->next!=NULL&&tmp1->next->next!=NULL)
		{
			tmp2 = tmp1->next;
			tmp3 = tmp2->next;
			tmp4 = tmp3->next;
			tmp1->next = tmp3;
			tmp3->next = tmp2;
			tmp2->next = tmp4;
			tmp1 = tmp1->next->next;
		}
	
		return tmp0->next;
		
    }
};

int main(void)
{
	ListNode *l1=NULL;
	Solution mysolution;
	int a[]={};

	CreateList(&l1,a,(int)sizeof(a)/sizeof(*a));
	PrintList(mysolution.swapPairs(l1));
 
	return 1;
}