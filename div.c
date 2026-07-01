#include "apc.h"
/* 
*Title			: Division
*Description		: This function performs division of two given large numbers and store the result in the resultant list.
Implemented division for arbitrary-length integers using repeated comparison and subtraction concepts similar to manual long division.
Division was built using repeated subtraction. The real challenge was comparing two large numbers stored as linked lists and performing 
subtraction multiple times with proper borrow handling. Since subtraction is the core operation of division in my implementation,
I focused heavily on making the comparison and subtraction logic accurate and efficient.

Challenges Faced:
The most challenging part was implementing efficient subtraction and comparison between two linked lists. 
During division, subtraction is executed multiple times , Managing leading zeros 
maintaining correct list traversal were critical challenges that I successfully resolved.
*/
void division(node *head1, node *head2, node **headR, node **tailR)
{

    if(is_zero(head2))// this it will check any zeros means it will gives zero
    {
        printf("Error: Division by zero is not allowed!\n");// These not divisable by 0 10/0 is undefined so printing usage message
        exit(1);// immidiatly terminating the program
    }
 
    /* 0 / anything = 0 it will print and exit*/
    if(is_zero(head1))
    {
        printf("0\n");
        exit(1);
    }

    *headR = NULL,*tailR = NULL;
    node *tail1 = head1,*tail2 = head2;
    while(tail1->next)// moving the head1 to the end
    tail1 = tail1->next;

    while(tail2->next)// moving the head2 to the end
    tail2 = tail2->next;

    int len1=0,len2=0;
    len1 = list_len(head1);// checking the lenght of the list1
    len2 = list_len(head2);// checking the lenght of the list1
    unsigned long int count = 0;
    // comparing  list1 count and list2 count if it is list1 digits < list2 digits
    if(len1<len2) 
    {
        printf("0\n");
        exit(1);// we are returning immidiatly
    }
    int cmp1,cmp2;
    // for every interation we are chaking the condition
    while(compare_list(head1,head2) != OPERAND2)
    {
        // Each ieteration we are substracting the values
        subtraction(tail1,tail2,headR,tailR);// Result storing to the Resultant list 
        delete_list(&head1,&tail1);// list1 is deleting 
        head1 = *headR, tail1 = *tailR;// and assinging with result list address
        len1 = list_len(head1);// here checking the lenght of head1
        *headR = NULL, *tailR = NULL;//now resultant list initializing with NULL
        count++; // Each iteration we are increamenting the count This count is the Result
    }
    insert_first(headR,tailR,count);// so After lsit1 < list2 result is count storing to this list
}