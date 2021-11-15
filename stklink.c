// #include <stdio.h>  
// #include <stdlib.h>  
 
struct nodes   
{  
int val;  
struct nodes *next;  
};  
struct nodes *head;  
  

void poosh ()  
{  
    int val;  
    struct nodes *ptr = (struct nodes*)malloc(sizeof(struct nodes));   
    if(ptr == NULL)  
    {  
        printf("not able to poosh the element");   
    }  
    else   
    {  
        printf("Enter the value");  
        scanf("%d",&val);  
        if(head==NULL)  
        {         
            ptr->val = val;  
            ptr -> next = NULL;  
            head=ptr;  
        }   
        else   
        {  
            ptr->val = val;  
            ptr->next = head;  
            head=ptr;  
               
        }  
        printf("Item pooshed");  
          
    }  
}  
  
void poops()  
{  
    int item;  
    struct nodes *ptr;  
    if (head == NULL)  
    {  
        printf("Underflow");  
    }  
    else  
    {  
        item = head->val;  
        ptr = head;  
        head = head->next;  
        free(ptr);  
        printf("Item poopsped");  
          
    }  
}  
void dis()  
{  
    int i;  
    struct nodes *ptr;  
    ptr=head;  
    if(ptr == NULL)  
    {  
        printf("Stack is empty\n");  
    }  
    else  
    {  
        printf("Printing Stack elements \n");  
        while(ptr!=NULL)  
        {  
            printf("%d\n",ptr->val);  
            ptr = ptr->next;  
        }  
    }  
} 

void stklink ()  
{  
    int choice=0;     
    printf("\n*********Stack operations using linked list*********\n");  
    printf("\n----------------------------------------------\n");  
    while(choice != 4)  
    {  
        printf("\n\nChose one from the below options...\n");  
        printf("\n1.push\n2.poop\n3.Show\n4.Exit");  
        printf("\n Enter your choice \n");        
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            {   
                poosh();  
                break;  
            }  
            case 2:  
            {  
                poops();  
                break;  
            }  
            case 3:  
            {  
                dis();  
                break;  
            }  
            case 4:   
            {  
                printf("Exiting....");  
                break;   
            }  
            default:  
            {  
                printf("Please Enter valid choice ");  
            }   
    };  
}  
}  