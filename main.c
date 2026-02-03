/*
    NAME        : Divya S
    DATE        : 30-01-26
    TITLE       : Arbitary Precision Calculator
    DESCRIPTION : A console based application that allows users to perform basic operation in calculator 
    such as Addition,Subtraction,Multiplication and Division where inputs are given through CLA.
    VALIDATION FEATURES :
        -> Checking the user enters the valid input
        -> Converting the string to integer data type
*/

#include "APC.h"

extern Node *headR;
extern Node *tailR;
extern Node *head1;
extern Node *tail1;
extern Node *head2;
extern Node *tail2;

char ch;

int main(int argc,char *argv[]){

    if(argc==4){
        if(read_validate(argc,argv)==SUCCESS){
            //printf("Validation Success\n");
            ch=argv[2][0];
            if(convert_atoi(argv)==SUCCESS){
               // printf("Conversion Successfull\n");
                switch (ch)
                {
                case '+':
                    free_list(&headR, &tailR);  //free the memory
                    addition(&headR,&head1,&head2,&tailR,&tail1,&tail2);    //adding two number 
                    printf("Result : ");
                    print(headR);
                    break;
                case '-':
                    printf("Result : ");
                    compare_list(argv,&headR,&head1,&head2,&tailR,&tail1,&tail2);
                    print(headR);
                    break;
                case 'x':
                    free_list(&headR, &tailR);
                    multiplication(&headR,&head1,&head2,&tailR,&tail1,&tail2);
                    printf("Result : ");
                    print(headR);
                    break;
                case '/':
                    division(argv,&headR,&head1,&head2,&tailR,&tail1,&tail2);
                    break;
                default:
                    break;
                }
            }
            else{
                printf("Conversion Failure\n");
            }
        }
        else{
            printf("Usage: OPERAND1 OPERATOR OPERAND2\n");
        }
    }
    else{
        printf("Enter enough arguments \nNOTE : for multiplication please use 'x' than '*'\n");
    }
    
}