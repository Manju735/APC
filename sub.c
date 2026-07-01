#include "apc.h"
/*
*Title			    : Substraction
*Description		: Developed subtraction logic for very large numbers using linked lists with borrow handling.
*Compare both operands to determine the larger number.
*Traverse from tail to head.
*If a digit is smaller than the corresponding digit, borrow from the next higher digit.
*Remove leading zeros from the final result.
Ex :
1000000000000
-999999999999
--------------
1*/
void subtraction(node *tail1, node *tail2, node **headR, node **tailR)
{
    int data = 0,barrow = 0;
    // adding the data from the tail to head traversing
    while(tail1 || tail2)// upto both condition becom false loop runs
    {
        int value1 = 0, value2 = 0;//for every iteration these 2 values becom initalize with 0
        if(tail1 )
        {
            value1 = tail1->data;// taking data from the list1
            tail1 = tail1->prev;// traves to prev node
        }

        if(tail2 )
        {
            value2 = tail2->data;// taking data from the list1
            tail2 = tail2->prev;// traves to prev node
        }

        data = value1 - value2 - barrow; //substracting the TWo value if & barrow Expplained bellow
        if(data<0) // if value becom -ve value 
        {
            barrow = 1;// taking barrow 
            data = data + 10;// and making that value -ve to positive
        }
        else
        {
            barrow = 0;//else it remains 0
        }
        // Calling insert at first Result of List contaians final value
        insert_first(headR,tailR,data);
    }
    remove_pre_zeros(headR);// in case any zeros present means deleting the zeros
}
