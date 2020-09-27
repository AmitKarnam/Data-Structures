# Stack is a linear data structure which follows a particular order in which the operations are performed. 
# The order is to be LIFO(Last In First Out).

stack = []                 # Stack is an Abstract Data Structure, here it is implemented with the help of LIST Data structure 
top = -1

def is_empty():
    if top == -1:
        return True
    return False


def push(x):
    global top
    top += 1
    stack.append(x)       # Add's the element at the end of the list
    return

def pop():
    global top
    if is_empty():
        print('Stack Underflow.')
    else:
        stack.remove(stack[top])
        top -= 1
    return

if __name__ == '__main__':
    push(10)
    push(20)
    push(30)
    push(40)
    push(50)
    push(60)
    push(70)
    push(80)
    push(90)
    push(100)
    push(110)
    print(stack)
    print("After a pop operation.")
    pop()
    print(stack)
    
 # OUTPUT 
 # [10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110]
 # After a pop operation.
 # [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
