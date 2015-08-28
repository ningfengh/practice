#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    TreeNode* sortedListToBST(ListNode* head) {
		if (head==NULL) return NULL;
        TreeNode* root = new TreeNode(head->val);
		TreeNode* tmp1,*tmp2;
		tmp1 = root;
		while (head->next=NULL)
		{
			head = head->next;
			tmp2 = new TreeNode(head->val);
			tmp1->right = tmp2;
			tmp1 = tmp1->right;
			
		}
		return root;
			
    }
};

int main(void)
{
	ListNode *l1=NULL;
	Solution mysolution;
	int a[]={1,2,3,4,5,6};

	CreateList(&l1,a,(int)sizeof(a)/sizeof(*a));
	 
	return 1;
}