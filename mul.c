#include "apc.h"
/* 
*Title			: Multiplication
*Description	: Each digit of one number is multiplied with every digit of the other number,
generating partial products that are stored in a temporary linked list.
These partial products are then added to the  result to produce the final answer.
Multiply each digit of the second number with every digit of the first number.
Generate partial products. Shift partial results according to position value.

Challenge Faced:
The biggest challenge was not the digit multiplication itself, but managing the intermediate result lists.
After each iteration, I had to add the partial product to the accumulated result,
update the result head for the next iteration, and free the temporary list without losing data
*/
void multiplication(node *tail1, node *tail2, node **headR, node **tailR)
{
    node *listH1 = NULL,*listT1=NULL,*listH2 = NULL,*listT2 = NULL,*temp1 = NULL,*temp2 = NULL;// initializing required pointers NULL
   int i,j,count = 0,data,carry=0;

   temp1 = tail1;// temp1 is tail1 address to traverse
   temp2 = tail2;// temp1 is tail1 address to traverse
   while(temp2)// loop will runs upto list2 becom NULL
   {
        for(i=0; i<count; i++)
        {
            insert_first(&listH2,&listT2,0);//In this loop we are adding the at the firt of is zero to additin we want
        }
        temp1 = tail1;// each iteration temp1 becom NULL we need to multiply upto temp2 becom NULL
        while(temp1)
        {
            data = (temp1->data * temp2->data)+ carry;// getting the data from the list 
            if(data > 9) // ifdata > 9 
            {
                carry = data / 10;// setting carry with orinal value EX 86/10 = 8 is carry
                data = data % 10;// takin the 86 % 10 = 6 is we need tomultiply
            }
            else
            {
                carry = 0;//else carry becoms 0
            }
            if(count == 0) // at the First time lsitH1 is empty thats wy we are usung this
            {
                insert_first(&listH1,&listT1,data);
            }
            else
            {
                insert_first(&listH2,&listT2,data);// second iteration storing the data to the list2
            }
            temp1 = temp1->prev;// moving to the prev node 
        }
        if(count >= 1) //when count is >= 1 inside statements will executes
        {
            addition(listT1,listT2,headR,tailR);// list1 data and lsit2 data adding and storing to hte ressulttant List
            delete_list(&listH1,&listT1);// after that deleting the allocated node
            delete_list(&listH2,&listT2);
            listH1 = *headR,listT1 = *tailR;// after addition we have result storing to the list1 
            *headR = NULL,*tailR = NULL;// initialiing with NULL
        }
        count++;
        temp2 = temp2->prev;// this iteration will continues upto NULL
   }
   *headR= listH1;
   *tailR = listT1;
   if(carry)
   insert_first(headR,tailR,carry);// if we get carry inser to the lsit
}