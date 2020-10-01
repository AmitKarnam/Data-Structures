/*
    c program for the insertion/deletion at the head/tail,
    insertion/deletion at the nth position,
    showing the elements of the linked list

    Functions involved:

    insertAtHead()
    insertAtTail()
    insertAtN()
    deleteAtN()
    displayLinkedList()
    deleteAtHead()
    deleteAtTail()
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

// defining the head node as global
struct node* head=NULL;

// function to create a memory block for the nodes
struct node* getNode(int x)
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->link=NULL;
    return temp;
}

// function for insertion in the head
void insertAtHead()
{
    int x;
    printf("\n Enter the element for inserting at the head: ");
    scanf("%d",&x);

    struct node* createnode=getNode(x);
    createnode->link=head;
    head=createnode;
}

void insertAtTail()
{
    int x;
    printf("\n Enter the element for inserting at the tail: ");
    scanf("%d",&x);

    struct node* createnode=getNode(x);

    // if the linked list is empty
    if( head==NULL )
    {
        head=createnode;
        return;
    }

    // traversing to the end of the linked list
    struct node* traverse;
    while(traverse->link!=NULL)
    {
        traverse=traverse->link;
    }
    traverse->link=createnode;
}

// position starts from 1 for inserting at head it is position 1
void insertAtN()
{
    displayLinkedList();

    int pos;
    printf("\n Enter the position of the element to insert: ");
    scanf("%d",&pos);

    int x;
    printf("\nEnter the element to insert at %d position: ",pos);
    scanf("%d",&x);

    struct node* createnode = getNode(x);

    if(pos==1)
    {
        createnode->link=head;
        head=createnode;
        return;
    }

    struct node* traversenode=head;
    int i;
    for(i=1; i<pos-1; i++)
    {
        traversenode=traversenode->link;
    }
    createnode->link=traversenode->link;
    traversenode->link=createnode;
}

void deleteAtN()
{
    struct node* traversenode=head;

    displayLinkedList();

    int position;
    printf("\n Enter the position for deletion of node: ");
    scanf("%d",&position);

    if(position==1)
    {
        head=traversenode->link;
        free(traversenode);
        return;
    }

    // going to the n-1th node
    int i;
    for(i=1; i<position-1; i++)
    {
        traversenode=traversenode->link;
    }

    // going to the nth node
    struct node* traversenode1=traversenode->link;
    traversenode->link=traversenode1->link;
    free(traversenode1);// freeing the nth node
}

void displayLinkedList()
{
    printf("\n Status of Linked List: ");
    if( head == NULL )
    {
        printf("\n Linked list is empty please enter some elements first. \n");
        return;
    }
    struct node* traverse=head;
    printf("\n Linked List elements are: ");
    while(traverse!=NULL)
    {
        printf("%d ",traverse->data);
        traverse=traverse->link;
    }
    printf("\n");
}

void deleteAtHead()
{
    if(head==NULL)
    {
        printf("\n Linked List is empty please enter something first. \n");
        return;
    }

    struct node* temp=head;
    head=head->link;

    free(temp);
}

void deleteAtTail()
{
    struct node* temp;
    struct node* temp1;
    if(head == NULL)
    {
        printf("\n Linked List is empty please enter something first. \n");
        return;
    }

    else if ( head->link == NULL)
    {
       temp = head;
       head = NULL;
       printf("\n Element deleted is %d \n",temp->data);
       free(temp);
    }

    else
    {
        temp = head;
        temp1 = head->link;

        while( temp1->link!=NULL )
        {
            temp = temp1;
            temp1= temp1->link;
        }

        temp->link = NULL;
        printf("\nDeleted item is: %d \n",temp1->data);
        free(temp1);
    }
}

int main()
{
    insertAtHead();
    insertAtHead();
    deleteAtTail();
    displayLinkedList();
}
