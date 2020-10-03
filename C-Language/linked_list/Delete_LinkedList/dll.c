#include<stdio.h>
#include <limits.h>
#include <malloc.h> 

struct Node{
    int data;
    struct Node *next;
};

void printLS(struct Node *n){
    if(n!=NULL){
   
    while(n!=NULL){
        printf("%d " , n->data);
        n = n->next;
    }
    printf("\n");}
}

//function to delete the begining element of the linked list
struct Node * deleteBeg(struct Node *start){ //delete beginning node
    struct Node *ptr; 
    ptr = start; // ptr points to start
    start = ptr->next; // now start points to what ptr->next points to
    free(ptr); // Now we will free the ptr where start used to be
    return start;
}

//function that calls *deleteBeg repetedly till the linked list is empty
void deleteList(struct Node *start){
    struct Node *ptr;
    
    if(start!=NULL){
        ptr = start;
        while(ptr!=NULL){
        	printf("deleting %d \n" , ptr->data);
            start = deleteBeg(ptr);
            ptr = start;
        }
        if(ptr==NULL){
        	printf("LinkedList is Now Empty\n");
        }
    }else{
    	printf("LinkedList is already Empty\n");
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
  
    printLS(head); //printing linked list data before deletion
    
    deleteList(head); //function call to delete linked list
    //printLS(head);
    return 0;
}
