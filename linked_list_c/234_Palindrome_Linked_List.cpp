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
    bool isPalindrome(ListNode* head) {
		int length = 0,i;
		ListNode* temp;
		ListNode* head1, *head2;
		ListNode* tmp1,*tmp2;
		temp = head;
		while (temp!=NULL)
		{
			length++;
			temp = temp->next;
		}
		if (length<=1) return true;
		head1 = head;
		tmp1 = head1->next;
		head1->next = NULL;
		tmp2 = head1;
		for (i=1;i<(int)(length+1)/2;i++)
		{
			head1 = tmp1;
			tmp1 = head1->next;
			head1->next = tmp2;
			tmp2=head1;
		}
		
		head2 = tmp1;
		if (length%2!=0)
			head1=head1->next;
		while (head1!=NULL)
		{
			if (head1->val != head2->val)
				return false;
			head1 = head1->next;
			head2 = head2->next;
		}
		return true;
        
    }
};

int main(void)
{
	ListNode *l1=NULL;
	int a[]={1,2,2,1};
	Solution mysolution;
	CreateList(&l1,a,(int)sizeof(a)/sizeof(*a));
	PrintList(l1);
	if (mysolution.isPalindrome(l1))
		cout<<"This list is palindrome"<<endl;
	else
		cout<<"This list is not palindrome"<<endl;
	return 1;
}