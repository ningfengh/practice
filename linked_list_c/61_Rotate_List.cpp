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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *tmp = head;
		int i,length=1;
		if (head==NULL) return NULL;
		while (tmp->next!=NULL)
		{
			tmp = tmp->next;
			length++;
		}
		
		tmp->next = head;
		for (i=0;i<(-k%length+length)%length;i++)
			tmp = tmp->next;
		head = tmp->next;
		tmp->next=NULL;
		return head;
			
    }
};
int main(void)
{
	ListNode *l1=NULL;
	Solution mysolution;
	int a[]={1,2};
	CreateList(&l1,a,(int)sizeof(a)/sizeof(*a));
	PrintList(mysolution.rotateRight(l1,3));
 
	return 1;
}