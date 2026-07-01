/*
*Title			    : Addition
*Description		: This function performs addition of two given large numbers and store the result in the resultant list.
*Implemented addition for integers of unlimited length using doubly linked lists, where each node stores a single digit.
*Traverse both linked lists from the least significant digit (tail).
*Add corresponding digits along with the carry.
*Store the result digit in a new linked list.
*Continue until all digits and carry are processed.
Ex:
99999999999999999999
+1
----------------
100000000000000000000
*/
#include "apc.h"

void addition(node *tail1, node *tail2, node **headR, node **tailR)
{
    int data = 0,carry =0;
    // adding the data from the tail to head traversing
    while(tail1 || tail2)// upto both condition becom false loop runs
    {
        int value1 = 0,value2 = 0; //for every iteration these 2 values becom initalize with 0 beacause updated value gives wrong result
        if(tail1 ) // it runs upto tail becoms NULL
        {
            value1 = tail1->data; // taking the LSB data from the list1
            tail1 = tail1->prev; // traversing to prev node 
        }

        if(tail2 )
        {
            value2 = tail2->data;// taking the LSB data from the list2
            tail2 = tail2->prev;
        }
        data = value1 + value2 + carry;// here adding two values initally carry becoms 
        if(data > 9)// her checking the condition if it > 10 we initialize with carry with 1
        {
            carry=1;// here initializing 
            data = data % 10;// ex 9+9 = 18 so i want 8 so 18%10 = 8 value we get
        }
        else
        {
            carry = 0; // if next iteration value < 10 carry becoms 0
        }
        // Calling insert at first Result of List contaians final value
        insert_first(headR,tailR,data); // each iteration we are creating node DLL and adding data upto N 
    }
    if(carry)// In case carry is there again we add that value by calling inerst_first fun
    insert_first(headR,tailR,1);
}
