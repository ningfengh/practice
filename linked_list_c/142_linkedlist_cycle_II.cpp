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
    ListNode *detectCycle(ListNode *head) {
		ListNode *slow, *fast;
		if (head==NULL) return NULL;
		slow = head;
        fast = head;
		while (fast->next!=NULL && fast->next->next!=NULL)
		{
		    slow = slow->next;
			fast = fast->next->next;
			if (slow==fast)
			{
				fast = head;
				while (fast!=slow)
				{
					fast = fast->next;
					slow = slow->next;
				}
				return fast;
			}
		}
		return NULL;
    }
};

int main(void)
{
	ListNode *l1=NULL,*tail,*insert,*result;
	Solution mysolution;
	//int a[]={1,2,3,4,5,6,7};
	int a[]={5};
	CreateList(&l1,a,(int)sizeof(a)/sizeof(*a));
	// create a loop
	/*
	tail = l1;
	while (tail->next!=NULL) tail=tail->next;
	insert = l1->next->next;
	tail->next = insert;
	*/
	result = mysolution.detectCycle(l1);
	
	if (result==NULL) cout<<"The linked-list doesn't have cycle"<<endl;
	else cout<<"The point of cycle has the value of "<<result->val<<endl;
	//PrintList(l1);
	return 1;
}