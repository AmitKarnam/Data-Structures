/*
    c program for the insertion/deletion at the head/tail,
    insertion/deletion at the nth position,
    showing the elements of the doubly linked list

    the program treats the node element consisting of
    integer value for it's data portion
    for  the program

    Functions involved:

    getNode(int x);
    DeleteFirstNode()
    DeleteLastNode()
    InsertAtHead()
    InsertAtEnd()
    InsertAtNthPosition()
    DeleteAtNthPosition()
    display()

    for insertion/deletion of the nodes
    at the nth position the position is
    treated as:

    for the position of the nodes
    position starts from 1
    1 is treated as the first node
    and so 2 for 2nd node and so on

*/

#include <stdio.h>
#include <stdlib.h>

// defining the Node through structure
struct Node{
int data;
struct Node* prev;
struct Node* next;
};

// head node
struct Node* head;

// function to create a memory block for the nodes
struct node *getNode(int x)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

// FUNCTION TO INSERT THE NEW NODE AT THE BEGINNING
void InsertAtHead()
{
    int x;
    printf("\nEnter the value to insert at the beginning of the linked list: ");
    scanf("%d",&x);

    struct Node* createnode=getNode(x);
    // if the head node is empty
    if(head==NULL)
    {
        head=createnode;
        return;
    }

    head->prev=createnode;
    createnode->next=head;
    head=createnode;
}

void InsertAtEnd()
{
    int x;
    printf("\nEnter the value to insert at the end of the linked list: ");
    scanf("%d",&x);

    struct Node* createnode=getNode(x);

    // if the head node is empty
    if(head==NULL)
    {
        head=createnode;
        return;
    }

    struct Node* travellingnode=head;
    // TRAVELLING TO THE LAST NODE
    while(travellingnode->next!=NULL)
    {
        travellingnode=travellingnode->next;
    }
    travellingnode->next=createnode;
    createnode->prev=travellingnode;
}

void DeleteFirstNode()
{
    if(head == NULL)
    {
        printf("\nLinked list is empty");
        return;
    }
    struct Node* temp=head;
    head=head->next;
    free(temp);
}

void DeleteLastNode()
{
    struct Node* lastnode=head;
    struct Node* secondlastnode;
    while(lastnode->next!=NULL)
    {
        secondlastnode=lastnode;
        lastnode=lastnode->next;
    }
     secondlastnode->next=NULL;
    free(lastnode);
}

/*
for the position of the nodes
position starts from 1
1 is treated as the first node
*/
void InsertAtNthPosition()
{
    int pos,x;
    printf("\nEnter the position for insertion:");
    scanf("%d",&pos);

    printf("\n Enter the element for insertion at position:%d : ",pos);
    scanf("%d",&x);

    struct Node* newNode = getNode(x);

    if(pos == 1)
    {
        InsertAtHead();
        return;
    }

    struct Node *traversenode = head;
    int i;
    for (i = 1; i < pos - 1; i++)
    {
        traversenode = traversenode->next;
    }

    newNode->prev = traversenode;
    newNode->next = traversenode->next;
    traversenode->next = newNode;

}

/*
for the position of the nodes
position starts from 1
1 is treated as the first node
*/
void DeleteAtNthPosition()
{
    struct Node* traverseNode = head;
    struct Node* NodeBeforeTraverse;

    int pos;
    printf("\nEnter the position for deletion: ");
    scanf("%d",&pos);

    if( pos == 1 )
    {
        head = head->next;
        free(traverseNode);
        return;
    }

    int i;
    for (i = 1; i <pos ; i++)
    {
        NodeBeforeTraverse = traverseNode;
        traverseNode = traverseNode->next;
    }

    if(traverseNode->next == NULL)
    {
        DeleteLastNode();
        return;
    }
    printf("\nDeleted node is: %d",traverseNode->data);

    NodeBeforeTraverse->next = traverseNode->next;
    (traverseNode->next)->prev = NodeBeforeTraverse;

    free(traverseNode);


}
void display()
{
    struct Node* travellingnode=head;
    printf("\nStatus of linked list is: \n");

    if(head == NULL)
    {
        printf("Linked List is empty. \n");
        return;
    }
    printf("Elements of linked list are: ");
    while(travellingnode!=NULL)
    {
        printf("%d ",travellingnode->data);
        travellingnode=travellingnode->next;
    }
    printf("\n");
}



int main()
{
    head=NULL;
    InsertAtHead();
    display();
    return 0;
}
