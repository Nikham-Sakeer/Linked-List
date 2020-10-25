#include<stdlib.h>
#include <stdio.h>

void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();

//creating node for storing data and link part of linked list
struct node
{
    int data;
    struct node *link;
};

//header node creation
struct node *header=NULL;

int main()
{
    int choice;
    while(1) {
        //printing MENU to take user input (will repeat to print until exit option (9) is selected)
        printf("\n--------------------------------------\n");
        printf("\n\t\tMENU");
        printf("\n\t\t~~~~\n");
        printf("\n 1.Create    \n");
        printf("\n 2.Display    \n");
        printf("\n 3.Insert at the beginning    \n");
        printf("\n 4.Insert at the end  \n");
        printf("\n 5.Insert at specified position       \n");
        printf("\n 6.Delete from beginning      \n");
        printf("\n 7.Delete from the end        \n");
        printf("\n 8.Delete from specified position     \n");
        printf("\n 9.Exit       \n");
        printf("\n--------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert_begin();
            break;
        case 4:
            insert_end();
            break;
        case 5:
            insert_pos();
            break;
        case 6:
            delete_begin();
            break;
        case 7:
            delete_end();
            break;
        case 8:
            delete_pos();
            break;

        case 9:
            exit(0);
            break;

        default:
            printf("\n Wrong Choice !\n");
            break;
        }
    }
    return 0;
}

//create a linked list (singly linked list)
void create()
{
    struct node *temp,*ptr;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\nOut of Memory Space:\n");
        exit(0);
    }
    printf("\nEnter the data value for the node: ");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(header==NULL)
    {
        header=temp;
    }
    else
    {
        ptr=header;
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=temp;
    }
}

//display the linked list
void display()
{
    struct node *ptr;
    if(header==NULL)
    {
        printf("\nList is empty:\n");
        return;
    }
    else
    {
        ptr=header;
        printf("\nThe List elements are:\n");
        while(ptr!=NULL)
        {
            printf("%d\t",ptr->data );
            ptr=ptr->link ;
        }
    }
}

//insert at beginning of linked list
void insert_begin()
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\nOut of Memory Space:\n");
        return;
    }
    printf("\nEnter the data value for the node: " );
    scanf("%d",&temp->data);
    temp->link =NULL;
    if(header==NULL)
    {
        header=temp;
    }
    else
    {
        temp->link=header;
        header=temp;
    }
}

// insert at end of linked list
void insert_end()
{
    struct node *temp,*ptr;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\nOut of Memory Space:\n");
        return;
    }
    printf("\nEnter the data value for the node: " );
    scanf("%d",&temp->data );
    temp->link =NULL;
    if(header==NULL)
    {
        header=temp;
    }
    else
    {
        ptr=header;
        while(ptr->link !=NULL)
        {
            ptr=ptr->link ;
        }
        ptr->link =temp;
    }
}

//insert to a specific position in linked list
void insert_pos()
{
    struct node *ptr,*temp;
    int i,pos;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\nOut of Memory Space:\n");
        return;
    }
    printf("\nEnter the position for the new node to be inserted: ");
    scanf("%d",&pos);
    pos-=1;
    printf("\nEnter the data value of the node:");
    scanf("%d",&temp->data) ;

    temp->link=NULL;
    if(pos==0)
    {
        temp->link=header;
        header=temp;
    }
    else
    {
        for(i=0,ptr=header; i<pos-1; i++) {
            ptr=ptr->link;
            if(ptr==NULL)
            {
                printf("\nPosition not found\n"); //handle with care
                return;
            }
        }
        temp->link =ptr->link ;
        ptr->link=temp;
    }
}

//delete from beginning of linked list
void delete_begin()
{
    struct node *ptr;
    if(ptr==NULL)
    {
        printf("\nList is Empty:\n");
        return;
    }
    else
    {
        ptr=header;
        header=header->link ;
        printf("\nThe deleted element is :%d\t",ptr->data);
        free(ptr);
    }
}

//delete from end of linked list
void delete_end()
{
    struct node *temp,*ptr;
    if(header==NULL)
    {
        printf("\nList is Empty:");
        exit(0);
    }
    else if(header->link ==NULL)
    {
        ptr=header;
        header=NULL;
        printf("\nThe deleted element is:%d\t",ptr->data);
        free(ptr);
    }
    else
    {
        ptr=header;
        while(ptr->link!=NULL)
        {
            temp=ptr;
            ptr=ptr->link;
        }
        temp->link=NULL;
        printf("\nThe deleted element is:%d\t",ptr->data);
        free(ptr);
    }
}

//delete from specific position in linked list
void delete_pos()
{
    int i,pos;
    struct node *temp,*ptr;
    if(header==NULL)
    {
        printf("\nThe List is Empty:\n");
        exit(0);
    }
    else
    {
        printf("\nEnter the position of the node to be deleted: ");
        scanf("%d",&pos);
        pos-=1;
        if(pos==0)
        {
            ptr=header;
            header=header->link ;
            printf("\nThe deleted element is:%d\t",ptr->data  );
            free(ptr);
        }
        else
        {
            ptr=header;
            for(i=0; i<pos; i++) {
                temp=ptr;
                ptr=ptr->link ;
                if(ptr==NULL)
                {
                    printf("\nPosition not Found:\n");
                    return;
                }
            }
            temp->link =ptr->link ;
            printf("\nThe deleted element is:%d\t",ptr->data );
            free(ptr);
        }
    }
}
