/*ALL THE HEADER FILES AND FUNCTION PROTOTYPE PRESENT HERE*/
#ifndef APC_H
#define APC_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>

#define MAX_BUFF 100

typedef enum {
    SUCCESS=1,
    FAILURE=0
}Status;

typedef struct node{
    int data;
    struct node *prev_link;
    struct node *next_link; 
}Node;


Status read_validate(int argc,char *argv[]);
Status convert_atoi(char *argv[]);
void compare_list(char *argv[],Node **headR,Node **head1,Node **head2,Node **tailR,Node **tail1,Node **tail2);
void free_list(Node **head,Node **tail);
void addition(Node **headR,Node **head1,Node **head2,Node **tailR,Node **tail1,Node **tail2);
void subtraction(int sign,Node **headR,Node **head1,Node **head2,Node **tailR,Node **tail1,Node **tail2);
void multiplication(Node **headR,Node **head1,Node **head2,Node **tailR,Node **tail1,Node **tail2);
void division(char *argv[],Node **headR,Node **head1,Node **head2,Node **tailR,Node **tail1,Node **tail2);
void print(Node *headR);

/*Helper functions*/
int dl_insert_first(Node **head, Node **tail, int data);
int dl_insert_last(Node **head, Node **tail, int data);
int cmp_list(Node **head1,Node **head2);
void inc_list(Node **headR1,Node **tailR1);
void trim_leading_zeros(Node **head, Node **tail);

#endif