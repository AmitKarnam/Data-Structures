#include<stdio.h>
#include <limits.h>
#include <malloc.h> 

struct Node{
    int data;
    struct Node *next;
};

//function to print linked list elements
void printLS(struct Node *n){
   
    while(n!=NULL){
        printf("%d " , n->data);
        n = n->next;
    }
    printf("\n");
}


struct Node * pushAfter(struct Node *start){
    
    struct Node *newNode , *ptr , *temp;
    
    int data = 5; // dumy data for insert node
    int afterNum = 2; // node added after this number
    
    newNode = (struct Node*)malloc(sizeof(struct Node)); //allocating space to newNode
    newNode->data = data; // filling data of newNode
    
    ptr = start; // ptr pointing to first node of linkedlist
    
    if(start!=NULL){
    	
        while(ptr->data!=afterNum){ // till we reach afterNum
            ptr = ptr->next;
        }
        temp = ptr->next; // temp is a temporary pointer storing the address of the node that ptr->next has  
        ptr->next = newNode; // ptr->next will now point to NewNode
        newNode->next = temp; // newNode->next will point to temp
        printf("Adding a node  \n");
        return start;
        
    }else{
        printf("Linked List is empty!");
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
  
    printLS(head); // printing linked list data before insertion
    
    head = pushAfter(head); // funcrion call to insert element
    
    printLS(head); // printing linked list data after insertion
    
    return 0;
}

