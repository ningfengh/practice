/********************************************************/
/*         Linked-list   Practice 1                     */
/*         construct a Linked-list                      */
/********************************************************/


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
	LinkedList (ListNode *list1, ListNode *list2)
	{
		// merging construction function
		
		// put your code here
        ListNode *head1 = list1;
        ListNode *head2 = list2;
        
        if(list1->value<=list2->value){
            head = new ListNode(head1->value);
            head1 = head1->next;
        }
        else{
            head = new ListNode(head2->value);
            head2 = head2->next;
        }
        size = 1;
        
        while (head1->next != NULL && head2->next != NULL) {
            //cout<<"val1 ="<<head1->value<<"val2 ="<<head2->value<<endl;
            if (head1->value<= head2->value){ 
                //cout<<"here1"<<endl;
                this->append(head1->value);
                head1 = head1->next;
            }
            else{
                // cout<<"here2"<<endl;
                this->append(head2->value);
                head2 = head2->next;
            }
            size++;
		}
        
        if (head1->next == NULL) {
            while (head2->next!=NULL) {
                if (head1!= NULL && head1->value<=head2->value) {
                    this->append(head1->value);
                    head1 = NULL;
                }
                else{
                    this->append(head2->value);
                    head2 = head2->next;
                }
                size++;
            }
            if (head1!= NULL && head1->value<=head2->value) {
                this->append(head1->value);
                this->append(head2->value);
            }
            else{
                this->append(head2->value);
                this->append(head1->value);
            }
            size++;
        }
        else{
            
            while (head1->next != NULL) {
                if (head2!=NULL && head2->value<=head1->value) {
                    this->append(head2->value);
                    head2 = NULL;
                }
                else{
                    this->append(head1->value);
                    head1 = head1->next;
                }
                size++;
            }
            if (head2!=NULL && head2->value<=head2->value) {
                this->append(head2->value);
                this->append(head1->value);
            }
            else{
                this->append(head1->value);
                this->append(head2->value);
            }
            size++;
        }
        
		//
		list1 = NULL;
		list2 = NULL;
	}
    void prepend (int x)
    {
        if (size == 0) {
            head = new ListNode(x);
            size = 1;
            return;
        }
        
        ListNode *pNewNode = new ListNode(x);
        pNewNode->next = head;
        head = pNewNode;
        size++;
        return;
        
        
        //[TODO 1] fill in this section to insert value x to the linked-list
    }
    void append (int x)
    {
        if (size == 0) {
            head = new ListNode(x);
            size = 1;
            return;
        }
        
        ListNode *pNewNode = new ListNode(x);
        ListNode *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = pNewNode;
        size++;
        return;
        
        
        //[TODO 1] fill in this section to insert value x to the linked-list
    }
    
    void insert (int x) // insert in assending order
    {
        if (size == 0) {
            head = new ListNode(x);
            size = 1;
            return;
        }
        
        if (x <= head->value) {
            prepend(x);
            return;
        }
        
        if (x > head->value && size == 1){
            append(x);
            return;
        }
        
        ListNode *pNewNode = new ListNode(x);
        ListNode *current = head;
        while (current->next != NULL) {
            current = current->next;
            ListNode *pNext = current->next;
            if (pNext == NULL) {
                append(x);
                return;
            }
            if (x>=current->value && x<= pNext->value) {
                current->next = pNewNode;
                pNewNode->next = pNext;
                size++;
                return;
            }
        }
        
        return;
        
        
        //[TODO 1] fill in this section to insert value x to the linked-list
    }
    void reverse()
    {
        if (size ==0 || size == 1) {
            return;
        }
        ListNode *previous = head;
        head = head->next;
        ListNode *pNext = head->next;
        previous->next = NULL;
        
        while (pNext != NULL) {
            head->next = previous;
            previous = head;
            head = pNext;
            pNext = head->next;
        }
        head->next = previous;
        
    }
    
    void print ()
    {
        ListNode *current = head;
        while (current != NULL) {
            //printf("%d\n", head->value);
            cout<<current->value<<endl;
            current = current->next;
        }
        // [TODO 2]fill in this section to print the linked-list
    }
    ~LinkedList()
    {
        ListNode *current = head;
        while (current!=NULL) {
            ListNode *next = current->next;
            delete current;
            current = next;
        }
    }
};



int main (void)
{
    int data1[] = {0,1,3,5,2,5,6,1,0,5000};
    int length1 = (int)sizeof(data1)/sizeof(*data1);
    int data2[] = {2,4,1,10,8,9,3, 111, 1000};
    int length2 = (int)sizeof(data2)/sizeof(*data2);
	LinkedList mylist1,mylist2;
    for (int i=0;i<length1;i++)
    {
        mylist1.insert(data1[i]);
    }
    cout<<"list 1"<<endl;
    mylist1.print();
	
    for (int i=0;i<length2;i++)
    {
        mylist2.insert(data2[i]);
    }
    cout<<"list 2"<<endl;
    mylist2.print();	
	
    cout<<"list 3"<<endl;
	LinkedList mylist3(mylist1.head,mylist2.head);
	mylist3.print();
    
    return 0;
}