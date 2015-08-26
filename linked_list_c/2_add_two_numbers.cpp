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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
		ListNode* head=new ListNode(0);
		ListNode* temp=head;
		ListNode* temp1;
		int carry = 0;
		int sum = 0;
		while (l1!=NULL && l2!=NULL)
		{
			sum = l1->val+l2->val+carry;
			if (sum>=10)
			{
				sum = sum-10;
				carry =1;
			}
			else{carry = 0;}
			temp1 = new ListNode(sum);
			temp->next = temp1;
			temp = temp->next;
			l1 = l1->next;
			l2 = l2->next;
		}
		if (l2!=NULL)
		{
			while (l2!=NULL)
			{
				sum = l2->val+carry;
				if (sum>=10)
				{
					sum = sum-10;
					carry =1;
				}
				else{carry = 0;}
				temp1 = new ListNode(sum);
				temp->next = temp1;
				temp = temp->next;
				l2 = l2->next;
			}
		}
		else if (l1!=NULL)
		{
			while (l1!=NULL)
			{
				sum = l1->val+carry;
				if (sum>=10)
				{
					sum = sum-10;
					carry =1;
				}
				else{carry = 0;}
				temp1 = new ListNode(sum);
				temp->next = temp1;
				temp = temp->next;
				l1 = l1->next;
			}			
		}
		if (carry==1)
		{
			temp1 = new ListNode(carry);
			temp->next = temp1;
			temp = temp->next;
		}
		head = head->next;
		return head;
    }
};

int main(void)
{
	ListNode *l1=NULL,*l2=NULL;
	Solution mysolution;
	int a[]={5};
	int b[]={5};
	CreateList(&l1,a,(int)sizeof(a)/sizeof(*a));
	CreateList(&l2,b,(int)sizeof(b)/sizeof(*b));
	
	ListNode *result = mysolution.addTwoNumbers(l1,l2);
	PrintList(result);
	return 1;
}