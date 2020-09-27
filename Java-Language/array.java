// An array is a group of like-typed variables that are referred to by a common name.
// This Java program illustrates the creation af an array of integers, 
// and assigning some values in the array, and printing each value to standard output.

public class array {

    public static void main (String[] args) { 

        int arr[]; // Declaring an array of integers.

        arr = new int[5]; // Allocating memory for 5 integers. 

        arr[0] = 1; // Initialize the first element of the array.

        arr[1] = 2; // Initialize the second element of the array.

        arr[2] = 3; // Similarly initialize all the elements of the array.

        arr[3] = 4; 
        arr[4] = 5; 

        for(int i = 0; i < arr.length; i++) { // Accessing the elements of the array.
            
            System.out.println("The element at index " + i +  " is : " + arr[i]) ; 

        } 

    } 
    
}

// Output:
// The element at index 0 is : 1
// The element at index 1 is : 2
// The element at index 2 is : 3
// The element at index 3 is : 4
// The element at index 4 is : 5

