#include "APC.h"
#include<ctype.h>
Node *headR=NULL,*tailR=NULL,*head1=NULL,*tail1=NULL,*head2=NULL,*tail2=NULL;

/*READ AND VALIDATING STRINGS OR CLA
INPUT: Value through CLA
OUTPUT: Return SUCCESS OR FAILURE
DESCRIPTION: Ensure that the user enters the valid arguments */
Status read_validate(int argc,char *argv[]){
    if(argv[1]){
        for(int i=0;argv[1][i]!='\0';i++){
            if(!isdigit(argv[1][i])){
                return FAILURE;
            }
        }
    }
    if((strcmp(argv[2],"+")&&strcmp(argv[2],"-")&&strcmp(argv[2],"x")&&strcmp(argv[2],"/"))!=0){
        return FAILURE;
    }
    if(argv[3]){
        for(int i=0;argv[3][i]!='\0';i++){
            if(!isdigit(argv[3][i])){
                return FAILURE;
            }
        }
    }

    return SUCCESS;
}

/*CONVERTING STRING TO INTEGER
INPUT:  CLA
OUTPUT: Return SUCCESS OR FAILURE
DESCRIPTION: Convert the strings to integers and stored in the Linked List */
Status convert_atoi(char *argv[]){
        if(argv[1]){
           
            
            for(int i=0;argv[1][i]!='\0';i++){
                Node *new=(Node *)malloc(sizeof(Node ));
                new->data=(argv[1][i]-'0');
                new->prev_link=NULL;
                new->next_link=NULL;
                

                if(head1==NULL){
                    head1=new;
                    tail1=new;
                }
                else{
                    new->prev_link=tail1;
                    tail1->next_link=new;
                    tail1=new;
                }
            }
            Node *temp=head1;
            printf("OPERAND 1: ");
            while (temp!=NULL)
            {
                printf("%d",temp->data);
                temp=temp->next_link;
            }
            printf("\n");
        
    }
    if(argv[3]){
        
            for(int i=0;argv[3][i]!='\0';i++){
                Node *new1=(Node *)malloc(sizeof(Node ));
                new1->data=(argv[3][i]-'0');
                new1->prev_link=NULL;
                new1->next_link=NULL;
                

                if(head2==NULL){
                    head2=new1;
                    tail2=new1;
                }
                else{
                    new1->prev_link=tail2;
                    tail2->next_link=new1;
                    tail2=new1;
                }
            }
            Node *temp1=head2;
            printf("OPERAND 2: ");
            while (temp1!=NULL)
            {
                printf("%d",temp1->data);
                temp1=temp1->next_link;
            }
            printf("\n");
    }
    
    return SUCCESS;
}


/*ADDITION
INPUT: Value through CLA
OUTPUT: Value
DESCRIPTION: Adding two numbers */
void addition(Node **headR,Node **head1,Node **head2,Node **tailR,Node **tail1,Node **tail2){

    int res,carry=0;
    Node *temp1=*tail1,*temp2=*tail2;
    while(temp1!=NULL||temp2!=NULL){

        if(temp1!=NULL&&temp2==NULL){
            res=temp1->data+0+carry;
        }
        else if(temp1==NULL && temp2!=NULL){
            res=temp2->data+0+carry;
        }
        else{
            res=temp1->data+temp2->data+carry;
        }
        carry =0;
        if(res>9){
            carry=1;
            res=res%10;
        }
       
         Node *new=(Node *)malloc(sizeof(Node));
         new->data=res;
         new->prev_link=NULL;
         new->next_link=NULL;
         if(*headR==NULL&&*tailR==NULL){
            (*headR)=new;
            (*tailR)=new;
       
         }
         else {
            
            new->next_link = (*headR);
            (*headR)->prev_link = new;
            *headR = new;
         }
        if(temp1) 
        temp1=temp1->prev_link;
        if(temp2)
        temp2=temp2->prev_link;
    }
    if(carry==1){
        Node *neww=(Node *)malloc(sizeof(Node));
        neww->data=1;
        neww->prev_link=NULL;
        neww->next_link=NULL;
        if(*headR){
            neww->next_link=*headR;
            (*headR)->prev_link=neww;
            *headR=neww;
        }
    }
}


/*COMPARE LIST->SUBTRACTION
INPUT: argument 1 and argument 3
DESCRIPTION:Compare the two arguments and calls the subtraction */
void compare_list(char *argv[],Node **headR,Node **head1,Node **head2,Node **tailR,Node **tail1,Node **tail2)
{
    int res=0,sign=0;
    
    if(strlen(argv[1])>strlen(argv[3])){
        res=1;
        free_list(headR, tailR);
        subtraction(sign,headR,head1,head2,tailR,tail1,tail2);
    }
    else if(strlen(argv[1])<strlen(argv[3])){
        sign=1;
        free_list(headR, tailR);
        subtraction(sign,headR,head2,head1,tailR,tail2,tail1);
    }
    else{
        Node *temp1=*head1,*temp2=*head2;
        while(temp1!=NULL&&temp2!=NULL){
            if(temp1->data>temp2->data){
                
                res=1;
                break;
            }
            else if(temp1->data<temp2->data){
                sign=1;
                res=0;
                break;
            }
            else{
                temp1=temp1->next_link;
                temp2=temp2->next_link;
            }
            
        }
        if(res){
            free_list(headR, tailR);
            subtraction(sign,headR,head1,head2,tailR,tail1,tail2);
        }
        else{
            free_list(headR, tailR);
            subtraction(sign,headR,head2,head1,tailR,tail2,tail1);
        }
    }
    if(sign){
        printf("-");
    }
    
}


/*SUBTRACTION
INPUT: Value through CLA
OUTPUT: Value
DESCRIPTION: Subtracting two numbers */
void subtraction(int sign,Node **headR,Node **head1,Node **head2,Node **tailR,Node **tail1,Node **tail2){
    int res;
    int d1=0,d2=0,borrow=0;
    Node *temp1=*tail1,*temp2=*tail2;
    while(temp1!=NULL||temp2!=NULL){
        if(temp1)
        d1=temp1->data;
        else
        d1=0;
        if(temp2)
        d2=temp2->data;
        else
        d2=0;
        d1-=borrow;
        borrow=0;
        if(d1<d2){
            d1+=10;
            borrow=1;
        }
        res=d1-d2;
        Node *new=(Node*)malloc(sizeof(Node));
        new->data=res;
        new->prev_link=NULL;
        new->next_link=NULL;
        if(*headR==NULL&&*tailR==NULL){
            *headR=new;
            *tailR=new;
        }
        else{
            new->next_link = (*headR);
            (*headR)->prev_link = new;
            *headR = new;
        }
        if(temp1)
        temp1=temp1->prev_link;
        if(temp2)
        temp2=temp2->prev_link;
    }
}


/*INSERT FIRST
TYPE:Helper function
DESCRIPTION: inserting numbers at first */
int dl_insert_first(Node **head, Node **tail, int data)
{
    Node *new=(Node *)malloc(sizeof(Node));  //creating a new node
    new->prev_link=NULL;
    new->data=data;
    new->next_link=*head;

     if (*head != NULL)
        (*head)->prev_link = new;
    else
        *tail = new; // if list was empty, tail also points to new

    *head = new;
    return SUCCESS;

}


/*INSERT LAST
TYPE:Helper function
DESCRIPTION: inserting numbers at last */
int dl_insert_last(Node **head, Node **tail, int data)
{
    Node *new=(Node *)malloc(sizeof(Node));
    new->data = data;
    new->next_link = NULL;
    new->prev_link = NULL;

    if(*head == NULL) {
        *head = new;
        *tail = new;
    } else {
        new->prev_link = *tail;
        (*tail)->next_link = new;
        *tail = new;
    }
    return SUCCESS;
}


/*MULTIPLICATION
INPUT: Value through CLA
OUTPUT: Value
DESCRIPTION: Multiplying two numbers */
void multiplication(Node **headR,Node **head1,Node **head2,Node **tailR,Node **tail1,Node **tail2){
    Node *temp1=NULL,*temp2=*tail2,*headR1=NULL,*tailR1=NULL,*headR2=NULL,*tailR2=NULL;
    int count=0,carry,res;
    while(temp2!=NULL){
        temp1 = *tail1;
        carry = 0;
        headR2 = tailR2 = NULL;
        
        carry =0;
        while(temp1!=NULL){
            res=temp1->data*temp2->data+carry;
            carry=res/10;
            res=res%10;

            dl_insert_first(&headR2, &tailR2, res);
            temp1 = temp1->prev_link;
        }
            if(carry>0){
               dl_insert_first(&headR2, &tailR2, carry);
            }
            for (int i = 0; i < count; i++)
            dl_insert_last(&headR2, &tailR2, 0);

             if (headR1 == NULL)
            {
                headR1 = headR2;
                tailR1 = tailR2;
            }
            else
            {
                Node *tempHeadR = NULL, *tempTailR = NULL;
                addition(&tempHeadR, &headR1, &headR2, &tempTailR, &tailR1, &tailR2);
                headR1 = tempHeadR;
                tailR1 = tempTailR;
                
                
            }
            count++;
            temp2 = temp2->prev_link;
        }
        *headR=headR1;
        *tailR=tailR1;
        
}


/*DIVISION
INPUT: Value through CLA
OUTPUT: Value
DESCRIPTION: Dividing two numbers */
void division(char *argv[],Node **headR,Node **head1,Node **head2,Node **tailR,Node **tail1,Node **tail2){
  
  Node *headR1=NULL,*tailR1=NULL;
  dl_insert_last(&headR1, &tailR1, 0); 
    while (cmp_list(head1, head2) >= 0){
        *headR = NULL;
        *tailR = NULL;
        
        
        subtraction(0,headR,head1,head2,tailR,tail1,tail2);
        trim_leading_zeros(headR,tailR);
        
       
        free_list(head1,tail1);
        *head1=*headR;
        *tail1=*tailR;
        
        *headR=NULL;
        *tailR=NULL;
        inc_list(&headR1,&tailR1);
        
    }
    printf("Result : %d\n",headR1->data);
    free(headR1);
   
}


/*PRINTING
INPUT: Value through CLA
OUTPUT: printing the Value
DESCRIPTION: It will print the values in the linked list */
void print(Node *head)
{
	/* Cheking the list is empty or not */
    Node *temp=head;
    int printed=0;
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
        
	    while (temp)		
	    {
            
		    /* Printing the list */
            if(temp->data!=0 || printed){
                printf("%d", temp -> data);
                printed=1;
            }
		    

		    /* Travering in forward direction */
		    temp = temp -> next_link;
	    }
        if(!printed){
            printf("0");
        }
        printf("\n");
    }
}


/*COMPARE LIST -DIVISION
INPUT: Value through CLA
OUTPUT: Value
DESCRIPTION:It compare the lenght of the list */

int cmp_list(Node **head1,Node **head2){
   
    Node *temp1=*head1,*temp2=*head2;
    int len1=0,len2=0;
    while (temp1)
    {
        len1++;
        temp1=temp1->next_link;
    }
    while (temp2)
    {
        len2++;
        temp2=temp2->next_link;
    }
    if(len1>len2){
        return 1;
    }
    if(len1<len2){
        return -1;
    }
    temp1=*head1,temp2=*head2;
    while (temp1 && temp2)
    {
        if(temp1->data > temp2->data){
            return 1;
        }
        else if (temp1->data < temp2->data){
            return -1;
        }
        temp1=temp1->next_link;
        temp2=temp2->next_link;
    }
    
    return 0;
}


/*TRIMMING ZEROS
TYPE:Helper function
DESCRIPTION:Removing the leading zeros */
void trim_leading_zeros(Node **head, Node **tail)
{
    // Remove leading zeros but keep at least one node
    while (*head && (*head)->data == 0 && (*head)->next_link)
    {
        Node *temp = *head;
        *head = (*head)->next_link;
        (*head)->prev_link = NULL;
        free(temp);
    }

    // Fix tail pointer
    *tail = *head;
    while (*tail && (*tail)->next_link)
        *tail = (*tail)->next_link;
}
/*INCREMENTING THE LIST
DESCRIPTION: will increment the pointer */
void inc_list(Node **headR1,Node **tailR1){
    
    Node *temp = *tailR1;

    // Step 1: add 1 from last digit
    temp->data++;

    // Step 2: handle carry
    while (temp && temp->data == 10)
    {
        temp->data = 0;

        // If carry goes beyond head
        if (temp->prev_link == NULL)
        {
            Node *new = malloc(sizeof(Node));
            new->data = 1;
            new->prev_link = NULL;
            new->next_link = temp;
            temp->prev_link = new;
            *headR1 = new;
            return;
        }

        temp = temp->prev_link;
        temp->data++;
    }
}

           
/*FREE LIST
DESCRIPTION: Free the memory */

void free_list(Node **head,Node **tail)
{
    Node *temp=*head;
    while (temp)
    {
        (*head)=(*head)->next_link;
        free(temp);
        temp=(*head);
    }
    
}

