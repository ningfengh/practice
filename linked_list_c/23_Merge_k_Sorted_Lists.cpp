#include <iostream>
#include <vector>
using namespace std;
/*
O(log (size))

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		int size=lists.size();
		if (size == 0 ) return NULL;
		else if (size == 1) return lists[0];
		else
		{
			ListNode *head = new ListNode(0);
			ListNode *tmp = head;

			vector<ListNode*> lists1(lists.begin(),lists.begin()+size/2);
			vector<ListNode*> lists2(lists.begin()+size/2,lists.end());


			ListNode *tmp1 = mergeKLists(lists1);
			ListNode *tmp2 = mergeKLists(lists2);


			while (tmp1!=NULL && tmp2!=NULL)
			{
				if (tmp1->val<=tmp2->val)
				{
					tmp->next = tmp1;
					tmp1 = tmp1->next;
				}
				else
				{
					tmp->next = tmp2;
					tmp2 = tmp2->next;
				}
				tmp = tmp->next;			
			}
			if (tmp1!=NULL)
				tmp->next = tmp1;
			else
				tmp->next = tmp2;
			return head->next;
		}

    }
};

int main(void)
{
	ListNode *l1=NULL,*l2=NULL,*l3=NULL;
	Solution mysolution;
	vector<ListNode*> lists;
	int a[]={1,3,5,7,9};
	int b[]={2,4,6};
	int c[]={8,10};
	CreateList(&l1,a,(int)sizeof(a)/sizeof(*a));
	CreateList(&l2,b,(int)sizeof(b)/sizeof(*b));
	CreateList(&l3,c,(int)sizeof(c)/sizeof(*c));
	lists.push_back(l1);
	lists.push_back(l2);
	lists.push_back(l3);
	PrintList(mysolution.mergeKLists(lists));
	return 1;
}