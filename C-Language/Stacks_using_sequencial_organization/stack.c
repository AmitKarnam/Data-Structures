#include <stdio.h>
#define MAXIM 10

int st[MAXIM] , top = -1; // maxim gives max size of the stack ; top points to the top most element of the stack
void push(int st[] , int val);
int pop(int st[]);
int peek(int st[]);
void display(int st[]);

//function to push an element to the stack
void push(int st[] , int val){
	if(top == MAXIM -1){
		printf("\n Stack overflow \n"); //check if stack is full?
	}
	else{
		top = top+1;
		st[top] = val;  // if stack is not full increment top and add element there
	}
}

//function to pop element from a stack
int pop(int st[]){
	int val; 
	if(top == -1){
		printf("\n stack empty \n");
		return -1;   // check if stack is empty
	}else{
		val = st[top];
		top = top -1;
		return val;   // if not empty then remove element and return the removed stack element's value
	}
}

//function to peep at the top most element in the stack
int peep(int st[]){
	if(top ==-1){
		printf("\n stack empty \n");  // check if stack is empty
		return -1;
	}else{
		return st[top];  // if not return the top most element of the stack
	}
}

//function to display stack elements (topo to bottom)
void display(int st[]){
	int i;
	if(top ==-1){
		printf("\n stack empty \n"); // check if stack is empty
	}else{
		for(i=top ; i>=0 ; i--){
			printf("\n %d" , st[i]);   // if not empty diaplay the elements 
		}
		printf("\n");
	}
}

int main(){
	int p;
	
	printf("\n Display Result : \n");
	display(st); // function call to display stack elements
	
	push(st , 1);
	push(st , 2);
	push(st , 3);
	push(st , 4); // adding four numbers to stack st
	
	printf("\n pushed 4 numbrs in stack \n");
	
	printf("\n Display Result : \n");
	display(st); // displaying the stack after pushing
	
	pop(st); // functin call to pop the stack st
	printf("\n popped stack element \n");
	printf("\n Display Result : \n");
	display(st); //displaying the stack after pop function
	
	p = peep(st); // function call to peep the stack
	printf("\n peep result : %d \n" , p);
}
