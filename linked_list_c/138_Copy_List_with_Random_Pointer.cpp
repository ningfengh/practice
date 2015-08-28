#include <iostream>
#include <map>
using namespace std;


struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

void AppendList(RandomListNode** head, int value)
{
    RandomListNode *appnode = new RandomListNode(value);
	RandomListNode *temp = *head;
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

void CreateList(RandomListNode** head, int* array,int n)
{
	int i;
	
	for (i=0;i<n;i++)
		AppendList(head,array[i]);
}

void PrintList(RandomListNode* head)
{
	RandomListNode * temp = head;
	while (temp != NULL)
	{
		cout<<temp->label<<endl;
		temp = temp->next;
	}	
}

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *head_new,*tmp,*tmp_new1,*tmp_new2;
		map <RandomListNode*,RandomListNode*> mymap;
		tmp = head;
		
		if (head==NULL) return NULL;
		head_new = new RandomListNode(tmp->label);
		tmp_new1 = head_new;
		mymap[head] = head_new;
		while (tmp->next!=NULL)
		{
			tmp = tmp->next;
			tmp_new2 = new RandomListNode(tmp->label);
			mymap[tmp] = tmp_new2;
			tmp_new1->next = tmp_new2;
			tmp_new1 = tmp_new1->next;
		}
		tmp = head;
		tmp_new1 = head_new;
		while (tmp!=NULL)
		{
			if (tmp->random==NULL)	tmp_new1->random = NULL;
			else
				tmp_new1->random = mymap[tmp->random];
			tmp = tmp->next;
			tmp_new1 = tmp_new1->next;
		}
		return head_new;
    }
};


int main(void)
{
	RandomListNode *l1=NULL,*l2=NULL;
	Solution mysolution;
	int a[]={1,2,3,4,5};
	CreateList(&l1,a,(int)sizeof(a)/sizeof(*a));
	PrintList(l1);
	PrintList(mysolution.copyRandomList(l1));
	return 1;
}