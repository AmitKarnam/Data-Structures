#include<stdio.h>
#include <limits.h>
#include <malloc.h> 

struct Node{
    int data;
    struct Node *next;
};

//function that displays the linked list data
void printLS(struct Node *n){
   
    while(n!=NULL){
        printf("%d " , n->data); // while the next node doesn't point to null show the data
        n = n->next;
    }
    printf("\n");
}

struct Node * deleteBeg(struct Node *start){ //delete beginning node
    struct Node *ptr; 
    ptr = start; // ptr points to start
    start = ptr->next; // now start points to what ptr->next points to
    free(ptr); // Now we will free the ptr where start used to be
    return start;
}

//function to delete last element of the linked list
struct Node * deleteEnd(struct Node *start){
    struct Node *ptr, *preptr;
    ptr = start;
    
    if(start!=NULL){
        while(ptr->next!=NULL){
            preptr=ptr;
            ptr = ptr->next;
        }
        preptr->next = NULL; //preptr points to node previous to ptr
        free(ptr);
        return start;
        
    }else{
        printf("Linked List is Empty!");
    }
}

//function to delete a specific Node in the linked list
struct Node * deleteSpecific(struct Node *start){
    struct Node *ptr , *preptr; // initializing two pointers
    int del = 3;
    ptr = start;
    if(start!=NULL){
        if(ptr->data==del){
            start = deleteBeg(start); //we will have to handle the deletion of beiginning node this way
        }else{
        while(ptr->data!=del){
            preptr=ptr; //preptr points to the node just before the node that ptr points to
            ptr = ptr->next;
        }
        
        if(ptr->next == NULL){
            preptr->next = NULL;
            free(ptr); //free ptr frees the memory for future use
        }else{
            preptr->next = ptr->next;
            free(ptr);} 
        }
        printf("Deleting node \n");
        return start;
        
    }else{
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
  
    printLS(head); //displaying the linked list elements
    
    head = deleteSpecific(head); //function call to delete a node
    
    printLS(head); //displaying liked list elements after deletion
    return 0;
}
