// refer to insert_beg and declare and traverse before this 
#include<stdio.h>
#include <limits.h>
#include <malloc.h> 

struct Node{
    int data;
    struct Node *next;
};

//function to display the linked list
void printLS(struct Node *n){
   
    while(n!=NULL){
        printf("%d " , n->data);
        n = n->next;
    }
    printf("\n");
}

//function to push a node at the end of the linked list
struct Node * pushEnd(struct Node *start){
    struct Node *newNode;
    struct Node *ptr;
    int num = 5; //dummy data for  adding
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->next = NULL; // since last node points to null
    
    if(start!=NULL){ //checking if the linked list is empty
    ptr = start; // ptr points to start
    while(ptr->next!=NULL){
        ptr = ptr->next; // while the node pointing to ptr doesn't point to NULL go ahead
    }
    ptr->next = newNode; // assigning the last node the pointer to the newNode
    
    return start;}
    else{
        printf("Linked List is Empty!");
    }
}


int main(){
    //declaring three empty nodes
    struct Node *head = NULL; 
    struct Node *second = NULL; 
    struct Node *third = NULL;
    
    //assigning each declared nodes the memory of the size of the Struct Node
    head = (struct Node*)malloc(sizeof(struct Node)); 
    second = (struct Node*)malloc(sizeof(struct Node)); 
    third = (struct Node*)malloc(sizeof(struct Node)); 
    
    
    head->data = 1; // assign data in first node 
    head->next = second; // Link first node with 
    // the second node 
    
     second->data = 2; 
     // Link second node with the third node 
    second->next = third; 
    
    third->data = 3; // assign data to third node 
    third->next = NULL; 
  
    printLS(head); // display linked list before insertion
    
    head = pushEnd(head);//function call to add node
    
    printLS(head); // display linked list afte insertion
    
    return 0;
}
