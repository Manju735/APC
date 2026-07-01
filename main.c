#include "apc.h"
/*
PROJECT : Arbitrary Precision Palculator
NAME : MANJUNATHA H
DATE : 26 / 06 / 2026

DISCRIPTION : Arbitrary Precision Calculator
*/
/*
*Title		 :   Main function(Driver function)
*Description : 	 This function is used as the driver function for the all the functions
*/
int main(int argc, char *argv[])
{
    node *head1 = NULL, *tail1 = NULL; // This list for storing the operand1 data 
	node *head2 = NULL, *tail2 = NULL; // This list is storing the operand2 data
	node *headR = NULL, *tailR = NULL; // This list is After done the operation storing into the resultant lsit

    // Validating the all Commands else printing the proper usage message and terminating the program
	if(cla_validation(argc,argv) == FAILURE)
	return FAILURE;
	printf("Result : ");
    // Create 2 lists of operands
	create_list(argv[1],&head1,&tail1);// operand1 data storing by command argument
	create_list(argv[3],&head2,&tail2);// operand2 data storing by command argument
    // Remove pre zeros

	remove_pre_zeros(&head1);// In case of User Enter pre - zeros by using this function will remove
	remove_pre_zeros(&head2);// ex 0002 OUTPUT: 2
	// User Enter the operator with operand1 and operand2 this function will executes based on operation decides else move to the next step
	if(argv[1][0] == '+'||argv[1][0] == '-'|| argv[3][0] == '+'||argv[3][0] == '-')
	{
		operation_decider(argv[2][0],argv[1][0],argv[3][0],head1,tail1,head2,tail2,&headR,&tailR);
		return SUCCESS; 
	}
	// here we are checking the Operation based on the operation do the calculatons as follows
    char oper = argv[2][0];
	int cmp;
	// Switch using for the cleaner operation and better readability to perform operation
    switch(oper)
    {
	case '+':
		// if operator is '+'  and  addition will performs and result will storing into the Result list headR 
	    addition(tail1, tail2, &headR, &tailR);// Address of the headR and tailR we passing because whatever changes we made it is affected to main function
	    break;									// so incase we pass headR changes will not reflected to main function thats we are passing address
	case '-':
		// if operator is '+'  and  addition will performs and result will storing into the Result list headR 
		cmp = compare_list(head1,head2); // here we are comparing the list
		if(cmp == SAME)
		{
			// if all data are same and same lenght directly put 0
			printf("0");// EX : 852 - 852 = 0 so dont need operation
		}
		else if(cmp == OPERAND1)
		{
			// here the two list1 > list2 we do the substration passing tail, storing into the Result list headR
			subtraction(tail1,tail2,&headR,&tailR);// like 1234 - 4 = 123
		}
		else
		{
			// here the two list1 < list2 so for that we pass list2 ,list1  
			printf("-"); // 5 - 15 = -10 ;so  we print '-' to get result,storing into the Result list headR
			subtraction(tail2,tail1,&headR,&tailR);
		}
	    break;

	case 'x':
	case 'X': // for multiplication user Enter x or X both accepted By exluding *
		multiplication(tail1,tail2,&headR,&tailR);// multiplication opreation  after multiplication rsult will stoe in resultant lsit
	    break;

	case '/':
		division(head1,head2,&headR,&tailR);// Division operation after result will store in resultant lsit
	    break;

	default:
	    printf("Invalid operator\n");
    }
	// After exit from the switch case the we will print the result
	print_list(headR);// BY calling the printlist function 
	delete_list(&headR,&tailR);// in result list dynamically allocated memory in heap so we are freeing the memory after alloca
	//else it leads to be memory Leak by avoiding memory leak freeing the allocated memory blocks
}

