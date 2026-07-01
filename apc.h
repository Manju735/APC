#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define SUCCESS		1
#define FAILURE		0

#define SAME		0
#define OPERAND1	1
#define OPERAND2	2

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
}node;
/*We can call these functions based on the operations when we need like follows bellow*/
/* Addition function */
void addition(node *tail1, node *tail2, node **headR, node **tailR);
/*Substraction function*/
void subtraction(node *tail1, node *tail2, node **headR, node **tailR);
/*Multiplication function*/
void multiplication(node *tail1, node *tail2, node **headR, node **tailR);
/*Division function*/
void division(node *head1, node *head2, node **headR, node **tailR);
/*validating Cammand line arguments */
int cla_validation(int argc, char *argv[]);
/*Creating the linked list*/
void create_list(char *opr, node **head, node **tail);

/*Insert At first Function*/
int insert_first(node **head, node **tail, int data);
/*Insert At Last Function*/
int insert_last(node **head, node **tail, int data);
/*Delete Function*/
int delete_list(node **head, node **tail);
/*print Function*/
void print_list(node *head);
/*Comparing the two list*/
int compare_list(node *head1, node *head2);
/*Length of the list function*/
int list_len(node *head);
/*Removing the prezeros*/
void remove_pre_zeros(node **head);
/*Operation decider like (-A + B) Based on sign we decide operation*/
void operation_decider(char Ooper,char Lopr,char Ropr,node *head1,node *head2,node *tail1,node *tail2,node **headR,node **tailR);

int is_zero(node *head);


#endif
