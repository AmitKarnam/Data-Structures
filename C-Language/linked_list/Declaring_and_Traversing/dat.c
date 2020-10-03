#include<stdio.h>
#include <limits.h>
#include <malloc.h> 

//this structure defines what each node in linked list should looklike
struct Node{
    int data;
    struct Node *next;
};

//this function prints each node in the linked list
void printLS(struct Node *n){
    
    while(n!=NULL){
        printf("%d " , n->data);
        // since we are passing pointers of the structure Node, we have to use the -> notation
        n = n->next;
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
    
    //assigning data to each created node
    
    head->data = 1; // assign data in first node 
    head->next = second; // Link first node with 
    // the second node 
    
     second->data = 2; 
     // Link second node with the third node 
    second->next = third; 
    
    third->data = 3; // assign data to third node 
    third->next = NULL; 
  
    printLS(head);
    
    return 0;
}
