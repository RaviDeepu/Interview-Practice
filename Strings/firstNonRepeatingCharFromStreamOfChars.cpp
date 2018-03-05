#include<iostream>
#include<string.h>
#define MAX_CHAR 256

using namespace std;

/*
    It used the below data structures.
    a. DLL - head will have the first non repeating char.
    b. inDLL - An array of pointers, which will have the respective addresses of DLL. inDLL[x] will have the adress of item x in DLL.
    c. repeated[] = An boolean array - repeated[x] is true if x is repeated two or more times. Otherwise false.

*/
   

struct node
{
    char item;
    struct node *next;
    struct node *prev;
};


void appendNode(struct node **headRef, struct node **tailRef, char x)
{
    struct node *temp = new node;
    temp->item = x;
    temp->next = temp->prev = NULL;

    if(*headRef == NULL)
    {
        *headRef = *tailRef = temp;
        return;
    }
    
    (*tailRef)->next = temp;
    temp->prev = *tailRef;

    *tailRef = temp;
}


void removeNode(struct node** headRef, struct node **tailRef, struct node *temp)
{   
    if(*headRef == NULL)
        return;

    if(*headRef == temp)
        *headRef = (*headRef)->next;

    if(*tailRef == temp)
        *tailRef = (*tailRef)->prev;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    if(temp->prev != NULL)
        temp->prev->next = temp->next;
}


void printFirstCharFromStream(char *stream)
{
    //
    bool repeated[MAX_CHAR];
    struct node *inDLL[MAX_CHAR];


    for(int i=0 ; i<MAX_CHAR ; ++i)
    {
        repeated[i] = false;
        inDLL[i] = NULL;
    }

    struct node* head = NULL;
    struct node* tail = NULL;

    for(int i=0 ; i<strlen(stream) ; ++i)
    {
        char x = stream[i];
    
        // repeated[x] is true if the character x is repeated more than 2 times.
        // So, we will ignore the false entry.
        if(!repeated[x])
        {
            // inDLL will be NULL in the starting.
            // So, we will insert x in the DLL and assign the address in inDLL.
            if(inDLL[x] == NULL)
            {
                appendNode(&head,&tail,x);
                inDLL[x] = tail; 
            }
            else
            {
                removeNode(&head,&tail,inDLL[x]);
                inDLL[x] = NULL;
                repeated[x] = true;
            }
        }
    }

    cout<<"First Repeated char is : "<<head->item<<endl;;
    cout<<"Second Repeated Char is : "<<head->next->item<<endl;
    cout<<"Third Repeated Char is : "<<head->next->next->item<<endl;
}


int main()
{
    char stream[]="abcdaecbefg";
    printFirstCharFromStream(stream);

}
