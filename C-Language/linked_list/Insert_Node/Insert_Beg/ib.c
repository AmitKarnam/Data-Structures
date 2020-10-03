#include<stdio.h>
#include <limits.h>
#include <malloc.h> 

//refer to declare and traverse before coming to this

struct Node{
    int data;
    struct Node *next;
};

void printLS(struct Node *n){
   
    while(n!=NULL){
        printf("%d " , n->data);
        n = n->next;
    }
    printf("\n");
}

// function that pushes a node in the beginning
struct Node * pushBeg(struct Node *start){
	
	//creating a new node 
    struct Node *newNode;
    int num = 5; //data for new node (can be user taken)
    //allocating memory to the newNode
    newNode= (struct Node*)malloc(sizeof(struct Node));
    
    //providing data to newNode
    newNode->data = num;
    //since we are adding it to the beginning the newNode will point to the now start of the 		linked list
    newNode->next = start;
    
    //setting the pointer pointing to newNode as start
    //since we are using pointers the pointer has been updated in the entire program.
    start = newNode;
    //returning the new start Node
    return start;
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
  
    printLS(head); // displaying linked list before insertion
    
    head = pushBeg(head); //function call to insert node
    
    printLS(head); // displaying the linked list after insertion
    
    return 0;
}
