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
    void reorderList(ListNode* head) {
        ListNode* head1, *head2;
		int length=0,i;
		if (head==NULL || head->next==NULL||head->next->next==NULL) return;
		head1 = head;
		while (head1!=NULL)
		{
			length++;
			head1 = head1->next;
		}
		head1 = head;
		
		for (i=0;i<(int)(length-1)/2;i++)
			head1=head1->next;
		head2 = head1->next;
		head1->next = NULL;
		head1 = head;

			
		// reverse list 2
		if (head2->next!=NULL)
		{
			ListNode *tmp1=head2,*tmp2;
			head2 = tmp1->next;
			tmp1->next = NULL;
			while (head2->next!=NULL)
			{
				tmp2 = head2->next;
				head2->next = tmp1;

				tmp1 = head2;
				head2 = tmp2;
			
			}
			head2->next = tmp1;
		}
		
		//interleave head1 and head2
		while(head2!=NULL)
		{
			ListNode *tmp1 = head2->next;
			
			head2->next = head1->next;
			head1->next = head2;
			
			head1 = head1->next->next;
			head2 = tmp1;
		}
				
		
		
		
	}
};

int main(void)
{
	ListNode *l1=NULL;
	Solution mysolution;
	int a[]={0,1,2};

	CreateList(&l1,a,(int)sizeof(a)/sizeof(*a));
    PrintList(l1);
    mysolution.reorderList(l1);
	//PrintList(l1);
	return 1;
}