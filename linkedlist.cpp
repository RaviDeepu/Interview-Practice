#include<iostream>
#include<stdlib.h>

using namespace std;




class Node
{
    public:
        int info;
        Node *next;
                                
    public:
        Node(int item=0)
        {
            info=item;
            next = NULL;
        }
};

class list
{
    private:
        Node *root;
        
    public:
        list()
        {
            root = NULL;
        }

        void pushRear(int item)
        {
            Node *tempNode = new Node(item);
            if(root == NULL)
            {
                root = tempNode;
                return;
            }
            
            Node *temp = root;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = tempNode;

        }

        void pushFront(int item)
        {
            Node *temp = new Node(item);
            if(root == NULL)
            {
                root = temp;
                return;
            }
            temp->next = root;
            root = temp;
        }

        void deleteFront()
        {
            if(root == NULL)
            {
                cout<<"List Empty\n";
                return;
            }
            Node *temp = root;
            root = root->next;
            cout<<"Deleting : "<<temp->info<<endl;
            delete temp;
        }


        void deleteRear()
        {
            if(root == NULL)
            {
                cout<<"List Empty\n";
                return;
            }

            Node *cur,*prev;
            cur = root;
            prev = NULL;

            while(cur->next != NULL)
            {
                prev = cur;
                cur = cur->next;
            }

            prev->next = NULL;
            cout<<"Deleting : "<<cur->info<<endl;
            delete cur;
        }

        void display()
        {
            if(root == NULL)
            {
                cout<<"List Empty\n";
                return;
            }
            Node *temp = root;

            cout<<"Linked List Contains\n";
            while(temp != NULL)
            {
                cout<<temp->info<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }

        void nthNode(int n)
        {
            if(root == NULL)
            {
                cout<<"List Empty\n";
                return;
            }
            int count = 1;
            Node *temp = root;
            while(temp != NULL)
            {
                if(count == n)
                {
                    cout<<"Nth Item : "<<temp->info<<endl;
                    break;
                }
                count++;
                temp = temp->next;
            }
            if(temp == NULL)
            {
                cout<<"Item not present"<<endl;
            }
        }

        void findMiddleElement_twoPointer()
        {
            if(root == NULL)
            {
                cout<<"List Empty\n";
                return;
            }

            Node *oneStep, *twoStep;

            oneStep = root;
            twoStep = root;
            while(twoStep != NULL && twoStep->next != NULL)
            {
                oneStep = oneStep->next;
                twoStep = twoStep->next->next;
            }

            cout<<"The Middle Element is : "<<oneStep->info<<endl;
        }


        void findMiddleElement()
        {

        }

};

int main()
{
    list linkedlist;

    while(1)
    {
        int choice,item,n;
        cout<<"1. Insert Item Front\n2. Insert Item Back\n3. Delete Item Front\n4. Delete Item Back\n";
        cout<<"5. Display List\n6. Print Nth Node\n";
        cout<<"7. Find Middle Element\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter Item\n";
                cin>>item;
                linkedlist.pushFront(item);
                break;
            case 2:
                cout<<"Enter Item\n";
                cin>>item;
                linkedlist.pushRear(item);
                break;
            case 3:
                linkedlist.deleteFront();
                break;
            case 4:
                linkedlist.deleteRear();
                break;
            case 5:
                linkedlist.display();
                break;
            case 6:
                cout<<"Enter the Nth Node to be displayed\n";
                cin>>n;
                linkedlist.nthNode(n);
                break;
            case 7:
                linkedlist.findMiddleElement_twoPointer();
                break;
            default:
                exit(0);
        }
    }
}
