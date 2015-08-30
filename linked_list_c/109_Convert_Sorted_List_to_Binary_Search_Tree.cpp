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

void PrintTreeDFS(TreeNode* root)
{
	if (root!=NULL)
	{
		cout<<root->val<<endl;
		PrintTreeDFS(root->left);
		PrintTreeDFS(root->right);
	}
}

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
		if (head==NULL) return NULL;
		if (head->next==NULL) return new TreeNode(head->val);
		ListNode* tmp;
		tmp = head;
		int length=0,i;
		while (tmp!=NULL)
		{
			tmp = tmp->next;
			length++;
		}
		tmp = head;
		for (i=0;i<length/2-1;i++)
			tmp = tmp->next;
		TreeNode* root = new TreeNode(tmp->next->val);
		root->right = sortedListToBST(tmp->next->next);
		tmp->next = NULL;
		root->left = sortedListToBST(head);
		
		
			
    }
};

int main(void)
{
	ListNode *l1=NULL;
	Solution mysolution;
	int a[]={1,2,3};

	CreateList(&l1,a,(int)sizeof(a)/sizeof(*a));
	PrintTreeDFS(mysolution.sortedListToBST(l1)); 
	return 1;
}