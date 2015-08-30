#include <iostream>
using namespace std;
/*
This solution is kind of ugly. 

Before each reverse, need to check whether there are enough nodes

However, the running speed is not bad 

24 ms is amoung the fastest

*/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *head_new=new ListNode(0);
		ListNode *head_part;
		ListNode *tmp1,*tmp2,*tmp3;
		ListNode *head_part_tmp;
		if (head==NULL) return NULL;
		head_new->next = head;
		tmp1 = head_new;
		tmp2 = head->next;
		head_part = head_new;
		int i,j,length;
		while(1)
		{
			tmp3 = head;
			length = 0;
			while (tmp3!=NULL)
			{
				tmp3 = tmp3->next;
				length++;
			}
			if (length<k) break;
			for (i=0;i<k-1;i++)
			{
				tmp1 = head;
				head = tmp2;
				tmp2 = tmp2->next;
				head->next = tmp1;
			}
			head_part_tmp = head_part->next;
			head_part->next->next = tmp2;
			head_part->next = head;
		
			head_part = head_part_tmp;
			tmp1 = head_part;
			head = tmp2;
			if (head!=NULL)	tmp2 = head->next;
		}
		
		return head_new->next;
		
		
    }
};

int main(void)
{
	ListNode *l1=NULL;
	Solution mysolution;
	int a[]={1,2,3,4,5,6,7,8};

	CreateList(&l1,a,(int)sizeof(a)/sizeof(*a));
	PrintList(mysolution.reverseKGroup(l1,3));
 
	return 1;
}