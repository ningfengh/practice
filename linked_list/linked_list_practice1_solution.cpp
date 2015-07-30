#include <iostream>
using namespace std;

class ListNode {
	public:
		int value;
		ListNode *next;
		ListNode (int x): value(x),next(NULL) {}
};

class LinkedList {
	public:
		ListNode *head;
		int size;
		LinkedList ()
		{
			head = NULL;
			size = 0;
		}
		LinkedList (int x)
		{
			head = new ListNode(x);
			size  = 1;
		}		
		insert (int x)
		{
			// fill in this section to insert value x to the linked-list
			if (head == NULL)
			{
				head = new ListNode(x);
				size++;
			}
			else
			{
				ListNode *tmp = head;
				while (tmp->next!=NULL)
						tmp = tmp->next;
				ListNode *newnode = new ListNode(x);
				tmp->next = newnode;
				size++;
			}
		}
		print ()
		{
			// fill in this section to print the linked-list
			ListNode *tmp = head;
			while (tmp!=NULL)
			{
					cout<<tmp->value<<endl;
					tmp = tmp->next;
			}
		}
};



int main (void)
{
	int data[] = {0,1,3,5,2,5,6,1,0};
	int length = (int)sizeof(data)/sizeof(*data);
	LinkedList mylist;
	for (int i=0;i<length;i++)
	{
		mylist.insert(data[i]);
	}	
	mylist.print();
	cout<<"the size of the linked list is "<<mylist.size;
	return 0;
}