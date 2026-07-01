#include "apc.h"
/*
*Function definitions Are present here so writing same code again and again I am using functions
*When the function is needed i will call that function
*Like doing operations like Insert at las,Inser at first ,compaing ,deleting ...ext
*/ 

/* Command line arguments validation */
int cla_validation(int argc, char *argv[])
{
    if(argc != 4)// VAlidating the command line arguments else printing proper usage and returing previos function and stop execution
    {
        printf("Usage: ./a.out operand1 operator operand2 \n");
        return FAILURE;
    }

    int i=0;// i is initially 0
    if(argv[1][0] == '+'||argv[1][0] == '-')// if user pass the sign with operand1 skiping that bacause next based on the that we perform the operation
    i=1;// if sign present skiping i=1;

    for(;argv[1][i]; i++)
    {
        if(!(argv[1][i]>='0' && argv[1][i]<='9'))// here we checking the inputs must be 0-9 else 
        {
            printf("Operand1 is not correct\n");// printing with the proper message and exiting
            return FAILURE;
        }
    }

    i=0;// again i is initially 0
    if(argv[3][0] == '+'||argv[3][0] == '-')//if user pass the sign with operand1 skiping
    i=1;// if sign present skiping i=1;

    for(;argv[3][i]; i++)
    {
        if(!(argv[3][i]>='0' && argv[3][i]<='9'))// here we checking the inputs must be 0 - 9 only integes allowed  else
        {
            printf("Operand2 is not correct\n");// proper message printing
            return FAILURE;//printing with the proper message and exiting
        }
    }
    return SUCCESS; // all validations are correct means returning Success next operation will start
}
/*Creating linked list converting argv char to int type  */
void create_list(char *opr, node **head, node **tail)
{
    int i=0,data = 0;
    if(opr[0] == '+' || opr[0] == '-')//if user pass the sign skiping
    i=1;// making i=1

    while(opr[i] )// loop will runs upto '\0' chracter 
    {
        data = opr[i]-'0';// data is in char converting to int type
        insert_last(head,tail,data);// after convering inseting into the doubly linked list
        i++;
    }
}
/*insert at last function*/
int insert_last(node **head, node **tail, int data)
{
    // we are allocating the memory dynamically temp pointer if it failes it returns NULL
    node *temp = malloc(sizeof(node)); if(temp == NULL) return FAILURE; // when allocation fails return failure macro

    temp->data = data;// every digits contains data one node adding at linked list
    temp->next = NULL;// inializing with NULL
    temp->prev = *tail;// tail address assinging to prev list
    if(*head == NULL) // when head == NULL node is empty 
    {
        *head = *tail = temp;// In time tail and head points to same node
    }
    else
    {
        (*tail)->next = temp;//else upadating the tail will continues every function call
        *tail = temp;// making tail to point towards at last node
    }
    return SUCCESS;// after inserted at last we return success
}
/*Insert at first*/
int insert_first(node **head, node **tail, int data)
{
    //we are allocating the memory dynamically temp pointer if it failes it returns NULL
    node *temp = malloc(sizeof(node)); if(temp == NULL) return FAILURE;

    temp->data = data;//every digits contains data one node adding at linked list
    temp->prev = NULL;// initially prev is NULL 
    temp->next = *head; // tail address assinging to prev list
    if(*head == NULL) // when head == NULL node is empty 
    {
        *head = *tail =temp; // In time tail and head points to same node
    }
    else
    {
        (*head)->prev = temp;//else upadating the head will continues every function call
        *head = temp; // making head to point towards at first of the list
    }
    return SUCCESS; // its completed returning success
}
/*print the values Result into consulewindow*/
void print_list(node *head)
{
    // inially result storing in result linked list 
    while(head)// by using the loop we are printing the data upto NULL
    {
        printf("%d",head->data);
        head = head->next;
    }
    putchar('\n');
}
/*Comparing the list*/
int compare_list(node *head1, node *head2)
{
    int list1 = list_len(head1);// To get the lengh of the list1 by calling function list len 
    int list2 = list_len(head2); // to get the leght of the list2 by calling function list_len

    if(list1 > list2) return OPERAND1;// if the list1 more nodes return the macro 1
    if(list2 > list1) return OPERAND2;//if the list2 more nodes return the macro 2

    //if the list1 and lsit2 both same lenght but different values inside loop we compare
    while(head1 && head2)
    {
        if(head1->data>head2->data) return OPERAND1;// if head1 value > head2 value we return macro 1
        if(head2->data>head1->data) return OPERAND2;// if head1 value < head2 value we return macro 2
        head1 = head1->next;
        head2 = head2->next;
    }
    return SAME;// if both are same we returning same values
}
/*IN this fiunction calculating length of the list*/
int list_len(node *head)
{
    int count = 0;// setting count is 0

    while(head) // loop will runs upto NULL 
    {
        count++;// count will increment every iteration
        head = head->next; // every iteration storing node address
    }
    return count;// returning the count
}
/*Remove pre zeros */
void remove_pre_zeros(node **head)
{
    if(*head == NULL) return;// if head ==NUll we are returning

    node *temp;// taking tempary pointer variable
    //In this loop we are checking any prezeros are there if it is there removing
    while( *head != NULL && (*head)->next != NULL && (*head)->data == 0)
    {
        temp = *head;// by storing that address to temp vaiable 
        *head = (*head)->next;// the updating with the next node link to the head
        (*head)->prev = NULL;// so head prev will point prev not initializing  with NULL
        free(temp); // freeing the temp variable;
        temp = NULL;
    }
}
/* Delete list */
int delete_list(node **head, node **tail)
{
    if(*head == NULL)// if head == NULL returning with proper message
    {
        printf("List is Empty\n");
        return FAILURE;
    }
    node *temp = *head;
    // if list is not empty deallocating the memory where dynamically allocated memory
    while(*head)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);// here deallocating memory
    }
    *head = *tail = NULL; // after deallocating head and tail initialize with NULL 
    return SUCCESS;
}
int is_zero(node *head)
{
    if(head == NULL) return 1;
    /* After remove_pre_zeros, a zero number is a single node with data=0 */
    if(head->next == NULL && head->data == 0) return 1;
    return 0;
}
/*For differant opration differant types of input I used operation decider*/
void operation_decider(char Ooper,char Lopr,char Ropr,node *head1,node *tail1,node *head2,node *tail2,node **headR,node **tailR)
{
    int cmp = compare_list(head1,head2);// comapring the list1 and lsit2 
    switch(Ooper)// used awitch cases based on operation we decide the operation
    {
        case '+':
            // -A + -B = -c
            if(Lopr=='-' && Ropr == '-') // in addition left oprand right oprant -ve means we print -ve  
            {
                printf("-");
                addition(tail1,tail2,headR,tailR);// and do the normal addition
            }
            else if(Lopr == '-')// if left only -ve 
            {
                if(cmp ==SAME)// comapre two lsit if same
                {
                    printf("0\n");// print 0
                    return ; // return exiting from the function
                }
                else if(cmp == OPERAND1)// if lsit1 lenght more we do normal sustraction with 
                {
                    printf("-");// printing sign value
                    subtraction(tail1,tail2,headR,tailR);
                }
                else
                {
                    subtraction(tail2,tail1,headR,tailR); // else passing argumets tail2 first and tail1 next
                }
                
            }
            // A + -B = C
            else if(Ropr == '-')//if right oprand is -ve as follows
            {
                if(cmp ==SAME) // both are same print 0 retirn back to prev func call
                {
                    printf("0\n");
                    return ;
                }
                else if(cmp == OPERAND1)
                {
                    subtraction(tail1,tail2,headR,tailR);// do the substration
                }
                else 
                {
                    printf("-");// printing -ve
                    subtraction(tail2,tail1,headR,tailR); // else passing argumets tail2 first and tail1 next 
                }
            } 
            // +A + +B = C
            else if(Lopr == '+' || Ropr == '+')// if both oprand + do the normal addition
            {
                addition(tail1,tail2,headR,tailR);
            }
            break;// break is used to controll the flow
        case '-':
            // +A - +B = C
            if(Lopr=='+' && Ropr == '+')// bth opreand +ve as follos
            {
                if(cmp ==SAME)
                {
                    printf("0\n");//both are same print 0 retirn back to prev func call
                    return ;
                }
                else if(cmp == OPERAND1)
                {
                    printf("-");
                    subtraction(tail1,tail2,headR,tailR);// do the substration with sign printing
                }
                else
                {
                    printf("-");
                    subtraction(tail2,tail1,headR,tailR);// do the substration
                }
            }
            // -A - -B = -C or C
            else if(Lopr=='-' && Ropr == '-')// bth opreand +ve as follos 
            {
                if(cmp ==SAME)
                {
                    printf("0\n");
                    return ;
                }
                else if(cmp == OPERAND1)
                {
                    printf("-");
                    subtraction(tail1,tail2,headR,tailR);// subtraction
                }
                else
                {
                    subtraction(tail2,tail1,headR,tailR);/// substraction
                }
            }
            // -A - B = -C additin prefoms
            else if(Lopr == '-')
            {
                if(cmp ==SAME)
                {
                    printf("0\n");
                    return ;
                }
                else if(cmp == OPERAND1)
                {
                    printf("-");
                    addition(tail2,tail1,headR,tailR);
                }
                else
                {
                    printf("-");
                    addition(tail2,tail1,headR,tailR);
                }
                //print_list(*headR);
            }
            else
            {
                if(cmp ==SAME)
                {
                    printf("0\n");
                    return ;
                }
                else if(cmp == OPERAND2)
                {
                    
                }
                addition(tail1,tail2,headR,tailR);
            }
           // print_list(*headR);
            break;
        case 'x':
        case 'X':
            
            multiplication(tail1,tail2,headR,tailR);// mustiplications
            remove_pre_zeros(headR);// removing zeros
            if(!is_zero(*headR)) // removing zeros
            {
                if(Lopr == '-' && Ropr != '-') printf("-");// left -ve is -ve value
                else if(Ropr == '-' && Lopr != '-') printf("-"); //right -ve is -ve
            }
            break;
            // division oprations performs
        case '/':
            // -A / -B = C
            if(Lopr == '-' && Ropr == '-')
            {
                if(cmp == SAME)
                {
                    printf("1\n");
                    exit(1);
                }
                else if(cmp == OPERAND2)
                {
                    printf("0\n");
                    exit(1);
                }
            }
            // -A / B = -C
            else if(Lopr == '-')
            {
                if(cmp == SAME)
                {
                    printf("1\n");
                    exit(1);
                }
                else if(cmp == OPERAND2)
                {
                    printf("0\n");
                    exit(1);
                }
                printf("-");
            }
            //A / -B  = -C
            else if(Ropr == '-')
            {
                if(cmp == SAME)
                {
                    printf("1\n");
                    exit(1);
                }
                else if(cmp == OPERAND2)
                {
                    printf("0\n");
                    exit(1);
                }
                else
                {
                printf("-");
                }
            }
            // performing division operation
            division(head1,head2,headR,tailR);
            break;
    }
    print_list(*headR);// after printg the result
    delete_list(headR,tailR);// deallocating the memory
}