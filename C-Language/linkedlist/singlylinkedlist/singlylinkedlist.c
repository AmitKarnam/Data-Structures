/*
    c program for the insertion/deletion at the head/tail,
    insertion/deletion at the nth position,

    for insertion/deletion at the nth position
    the position starts from 1 
    1 is the starting node
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

// defining the head node as global
struct node *head = NULL;

// function to create a memory block for the nodes
struct node *getNode(int x)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->link = NULL;
    return temp;
}

void Insert()
{
    int choice;
    fflush(stdin);
    printf("\n--------------------------------Insertion Menu---------------------------------\n");
    printf("-----------------------Press 1 for Insertion In The Head Node------------------\n");
    printf("-----------------------Press 2 for Insertion In The Tail Node-------------------\n");
    printf("-----------------------Press 3 for Insertion In The Nth  Node------------------\n");
    printf("Enter Your Choice for insertion: ");
    scanf("%d", &choice);

    // getting the input
    int x, pos;
    printf("\n Enter the value to insert at the linked list: ");
    scanf("%d", &x);

    // creating a node;
    struct node *createnode = getNode(x);

    // traversing node
    struct node *traverse = head;

    switch (choice)
    {
    //  INSERTION IN THE HEAD
    case 1:
        createnode->link = head;
        head = createnode;
        break;

    // INSERTINO AT THE LAST
    case 2:
        // if the linked list is empty
        if (head == NULL)
        {
            head = createnode;
            return;
        }

        // traversing to the end of the linked list
        while (traverse->link != NULL)
        {
            traverse = traverse->link;
        }
        traverse->link = createnode;
        break;

    case 3:
        // INSERTING AT THE NTH NODE

        printf("\n Enter the position of the element to insert: ");
        scanf("%d", &pos);

        if (pos == 1)
        {
            createnode->link = head;
            head = createnode;
            displayLinkedList();
            return;
        }

        struct node *traversenode = head;
        int i;
        for (i = 1; i < pos - 1; i++)
        {
            traversenode = traversenode->link;
        }
        createnode->link = traversenode->link;
        traversenode->link = createnode;
        break;
    }
    displayLinkedList();
}

void Delete()
{
    int choice, position;
    struct node *temp = head;
    struct node *temp1;

    fflush(stdin);
    printf("\n--------------------------------Deletion Menu---------------------------------\n");
    printf("-----------------------Press 1 for Deleting The Head Node------------------\n");
    printf("-----------------------Press 2 for Deleting The Tail Node-------------------\n");
    printf("-----------------------Press 3 for Deleting The Nth  Node------------------\n");
    printf("Enter Your Choice for Deletion: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        if (head == NULL)
        {
            printf("\n Linked List is empty please enter something first. \n");
            return;
        }

        temp = head;
        head = head->link;

        free(temp);
        break;

    case 2:
        if (head == NULL)
        {
            printf("\n Linked List is empty please enter something first. \n");
            return;
        }

        // if the only node is head node
        else if (head->link == NULL)
        {
            temp = head;
            head = NULL;
            printf("\n Element deleted is %d \n", temp->data);
            free(temp);
        }

        else
        {
            temp = head;
            temp1 = head->link;

            while (temp1->link != NULL)
            {
                temp = temp1;
                temp1 = temp1->link;
            }

            temp->link = NULL;
            printf("\nDeleted item is: %d \n", temp1->data);
            free(temp1);
        }
        break;

    case 3:
        temp = head;
        printf("\n Enter the position for deletion of node: ");
        scanf("%d", &position);

        if (position == 1)
        {
            head = temp->link;
            free(temp);
            displayLinkedList();
            return;
        }

        // going to the n-1th node
        int i;
        for (i = 1; i < position - 1; i++)
        {
            temp = temp->link;
        }

        temp1 = temp->link;
        temp->link = temp1->link;
        free(temp1); // freeing the nth node
        break;
    }
    displayLinkedList();
}

void displayLinkedList()
{
    printf("\n Status of Linked List: ");
    if (head == NULL)
    {
        printf("\n Linked list is empty please enter some elements first. \n");
        return;
    }
    struct node *traverse = head;
    printf("\n Linked List elements are: ");
    while (traverse != NULL)
    {
        printf("%d ", traverse->data);
        traverse = traverse->link;
    }
    printf("\n");
}

int main()
{
    Insert();
    Insert();
    Insert();

    Delete();
    Delete();
    Delete();

    displayLinkedList();
    return 0;
}

/*
Output:


--------------------------------Insertion Menu---------------------------------
-----------------------Press 1 for Insertion In The Head Node------------------
-----------------------Press 2 for Insertion In The Tail Node-------------------
-----------------------Press 3 for Insertion In The Nth  Node------------------
Enter Your Choice for insertion: 1

 Enter the value to insert at the linked list: 1

 Status of Linked List:
 Linked List elements are: 1

--------------------------------Insertion Menu---------------------------------
-----------------------Press 1 for Insertion In The Head Node------------------
-----------------------Press 2 for Insertion In The Tail Node-------------------
-----------------------Press 3 for Insertion In The Nth  Node------------------
Enter Your Choice for insertion: 2

 Enter the value to insert at the linked list: 3

 Status of Linked List:
 Linked List elements are: 1 3

--------------------------------Insertion Menu---------------------------------
-----------------------Press 1 for Insertion In The Head Node------------------
-----------------------Press 2 for Insertion In The Tail Node-------------------
-----------------------Press 3 for Insertion In The Nth  Node------------------
Enter Your Choice for insertion: 3

 Enter the value to insert at the linked list: 7

 Enter the position of the element to insert: 1

 Status of Linked List:
 Linked List elements are: 7 1 3

--------------------------------Deletion Menu---------------------------------
-----------------------Press 1 for Deleting The Head Node------------------
-----------------------Press 2 for Deleting The Tail Node-------------------
-----------------------Press 3 for Deleting The Nth  Node------------------
Enter Your Choice for Deletion: 1

 Status of Linked List:
 Linked List elements are: 1 3

--------------------------------Deletion Menu---------------------------------
-----------------------Press 1 for Deleting The Head Node------------------
-----------------------Press 2 for Deleting The Tail Node-------------------
-----------------------Press 3 for Deleting The Nth  Node------------------
Enter Your Choice for Deletion: 2

Deleted item is: 3

 Status of Linked List:
 Linked List elements are: 1

--------------------------------Deletion Menu---------------------------------
-----------------------Press 1 for Deleting The Head Node------------------
-----------------------Press 2 for Deleting The Tail Node-------------------
-----------------------Press 3 for Deleting The Nth  Node------------------
Enter Your Choice for Deletion: 3

 Enter the position for deletion of node: 1

 Status of Linked List:
 Linked list is empty please enter some elements first.

 Status of Linked List:
 Linked list is empty please enter some elements first.

*/
