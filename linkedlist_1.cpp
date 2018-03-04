#include<iostream>

using namespace std;

struct node
{
	int info;
	struct node *link;
};


struct node * insert_front(struct node *head, int item)
{
	struct node *temp;
	temp = (struct node *) malloc(sizeof(struct node));
	temp->info = item;
	temp->link = NULL;

	if(head == NULL)
		return temp;
	
	struct node *cur;
	temp->link = head;
	
	return temp;
}

struct node *delete_front(struct node *head)
{
	if(head == NULL)
	{
		cout<<"List is Empty\n";
		return head;
	}

	cout<<"Deleted Item is "<<head->info<<"\n";
	head = head->link;
	return head;
}

void display(struct node *head)
{
	struct node *cur;
	if(head == NULL)
	{
		cout<<"List is Empty\n";
		return ;
	}

	cur = head;
	while(cur != NULL)
	{
		cout<<"Item : "<<cur->info<<"\n";
		cur = cur->link;
	}
}


struct node * reverse(struct node *head)
{
	struct node *prev,*cur;
	prev = NULL;
	while(head != NULL)
	{
		cur = head;
		head = head->link;
		
		cur->link = prev;
		prev = cur;
	}
	return prev;
}


int main()
{
	int ch,item;
	struct node *head = NULL;
	cout<<"1. Insert\n2. Delete\n3. Display\n4. Reverse\n";
	for(;;)
	{
		cout<<"Enter your choice\n";
		cin>>ch;
		
		switch(ch)
		{
			case 1:cout<<"Enter the Item\n";
					  cin>>item;
					head = insert_front(head,item);
					break;

			case 2:head = delete_front(head);
						break;

			case 3:display(head);
					break;

			case 4:head = reverse(head);
						break;
			
			default:exit(0);
		}
	}
}
