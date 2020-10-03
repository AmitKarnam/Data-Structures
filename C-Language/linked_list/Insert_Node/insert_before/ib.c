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

//function to insert element before a given node 
struct Node * pushBefore(struct Node *start){
    
    struct Node *newNode , *ptr , *temp;
    
    int data = 5; // dummy data
    int beforeNum = 1; // hard coded node data before which insertion to be done
    
    //temp is pointing to one node before the node that ptr is pointing to.
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    
    ptr = start;
    temp = start;
    if(start!=NULL){
        while(ptr->data!=beforeNum){
        	temp = ptr;
            ptr = ptr->next;
        }
        if(ptr == start){
        	newNode->next = start;
        	start = newNode;		// handling the case where the node to be added is the first start node
        	
        }else{
		    temp->next = newNode; 
		    newNode->next = ptr;
		}
        
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
    
    head = pushBefore(head); // function call to insert node before linked list
    
    printLS(head); //printing linked list data after insertion
    
    return 0;
}
