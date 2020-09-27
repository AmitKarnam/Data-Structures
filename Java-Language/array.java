/* 
    
    An Array Is A Group Of Like - Typed Variables That Are Referred To By A Common Name .
    This Java Program Illustrates Creation Of An Array Of Integers , And Assigning 
    Some Values In The Array , And Printing Each Value To Standard Output .

*/

public class array 

{
     public static void main ( String [ ] args )  
    
    {          
      // Declararing An Array Of Integers .

      int  array [ ] ; 
          
      // Allocating Memory For 5 Integers . 

      array = new int [ 5 ] ; 
          
      // Initialize The First Element Of The Array .

      array [ 0 ] = 1 ; 
          
      // Initialize The Second Element Of The Array . 

      array [ 1 ] = 2 ; 
          
      // Similarly Initialize All The Elements Of The Array .

      array [ 2 ] = 3 ; 

      array [ 3 ] = 4 ; 

      array [ 4 ] = 5 ; 
          
      // Accessing The Elements Of The Array .

      for ( int i = 0 ; i < arr.length ; i ++ ) 

      {

        System.out.println("The Element At Index " + i +  " Is : " + arr [ i ] ) ;       

      } 

    } 

}
