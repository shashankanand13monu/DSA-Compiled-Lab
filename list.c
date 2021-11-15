// #include <stdio.h>
// #include <stdlib.h>
struct node 
{
    int num;                       
    struct node *nextptr;          
}*stnode;

void cL(int n)
{
    struct node *fnNode, *temp;
    int num, i;
    stnode = (struct node *)malloc(sizeof(struct node));
    if(stnode == NULL) 
    {
     printf(" List is full.");
    }
    else
    {
        printf(" Enter data for node 1 : ");
        scanf("%d", &num);
        stnode->num = num;      
        stnode->nextptr = NULL; 
        temp = stnode;
        for(i=2; i<=n; i++)
        {
            fnNode = (struct node *)malloc(sizeof(struct node));
            if(fnNode == NULL)
            {
                printf(" List is Full.");
                break;
            }
            else
            {
                printf(" Input data for node %d : ", i);
                scanf(" %d", &num);
 
                fnNode->num = num;      
                fnNode->nextptr = NULL; 
 
                temp->nextptr = fnNode; 
                temp = temp->nextptr; 
            }
        }
    }

}
void dl()
{
    struct node *temp;
    if(stnode == NULL)
    {
        printf(" List is empty.");
    }
    else
    {
        temp = stnode;
        while(temp != NULL)
        {
            printf(" Data = %d\n", temp->num);       
            temp = temp->nextptr;                     
        }
    }
}

int list()
{
    int n;
    printf(" Input the number of nodes : ");
    scanf("%d", &n);
    cL(n);
    printf("\n Data entered in the list : \n");
    dl();
    return 0;
}