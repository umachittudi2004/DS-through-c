#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start=NULL;
void insert_begin ();
void insert_end ();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
void display();
void main ()
{
    int choice;
    while(1)
    {
        
        printf("Enter your choice\n1.Insert in begining\n2.Insert at last\n3.insert at given position\n4.Delete from Beginning\n5.Delete from last\n6.delete from given position\n7.display\n8.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            insert_begin();
            break;
            case 2:
            insert_end();
            break;
            case 3:
            insert_pos();
            break;
            case 4:
            delete_begin();
            break;
            case 5:
            delete_end();
            break;
            case 6:
            delete_pos();
            break;
            case 7:
            display();
            break;	
            case 8:
            exit(0);
            break;
            default:
            printf("invalid choice\n");
        }
    }
}
void insert_begin()
{
    struct node *temp,*newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("memory not allocated\n");
    }
    else
    {
        printf("Enter the node data\n");
        scanf("%d",&newnode->data);
        if(start == NULL)
        {
            start= newnode;
            newnode->next = start;
        }
        else
        {
            temp = start;
            while(temp->next != start)
            {
                temp= temp->next;
            }
            newnode->next = start;
            temp-> next = newnode;
            start=newnode;
        }
    }

}
void insert_end()
{
    struct node *temp,*newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if(newnode== NULL)
    {
        printf("memory not allocated\n");
    }
    else
    {
        printf("\nEnter value\n");
        scanf("%d",&newnode->data);
        if(start== NULL)
        {
            start=newnode;
            newnode-> next = start;
        }
        else
        {
            temp= start;
            while(temp -> next != start)
            {
                temp = temp-> next;
            }
            temp-> next = newnode;
            newnode-> next = start;
        }

    }

}
void insert_pos()
{
        struct node *temp,*newnode;
        int i,pos;
        newnode=(struct node *)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
                printf("memory not allocated\n");
                return;
        }
        printf("\n Enter the position for the new node to be inserted: ");
        scanf("%d",&pos);
        printf("\n Enter the data value of the node: ");
        scanf("%d",&newnode->data) ;

        newnode->next=NULL;
        if(pos==0)
        {
                newnode->next=start;
                start=newnode;
        }
        else
        {
            temp=start;
                for(i=0;i<pos-1;i++) 
                {
                    temp=temp->next;
                        if(temp==start)
                        {
                                printf("\n Position not found\n");
                                return;
                        }
                }
                                newnode->next =temp->next ;
                temp->next=newnode;
        }
}

void delete_begin()
{
    struct node *temp,*ptr;
    if(start== NULL)
    {
        printf("linked list is empty\n");
    }
    else if(start->next ==start)
    {
        free(start);
        start = NULL;
    }

    else
    {   temp =start;
        while(temp ->next != start)
        {
            temp= temp->next;
        }
        temp->next =start->next;
        ptr=start;
        start = temp->next;
        free(ptr);
    }
}

void delete_end()
{
    struct node *temp, *prevnode;
    if(start==NULL)
    {
        printf("linked list is empty\n");
    }
    else if (start->next ==start)
    {
        free(start);
        start= NULL;

    }
    else
    {
        temp= start;
        while(temp->next != start)
        {
            prevnode=temp;
            temp = temp->next;
        }
        prevnode->next = temp -> next;
        free(temp);

    }
}

void delete_pos()
{
        int i,pos;
        struct node *prevnode,*temp;
        if(start==NULL)
        {
                printf("\n The List is Empty:\n");
                return;
        }
        else
        {
                printf("\n Enter the position of the node to be deleted: ");
                scanf("%d",&pos);
                if(pos==0)
                {
                        temp=start;
                        start=start->next ;
                        printf("\n The deleted element is:%d ",temp->data  );
                        free(temp);
                }
                else
                {
                        temp=start;
                        for(i=0;i<pos;i++) 
                        {
                            prevnode=temp; 
                            temp=temp->next ;
                                if(temp==start)
                                {
                                        printf("\n Position not Found:\n");
                                        return;
                                }
                        }
                        prevnode->next =temp->next ;
                        printf("\n The deleted element is:%d\n ",temp->data );
                        free(temp);
                }
        }
}
void display()
{
    struct node *temp;
    temp=start;
    if(start == NULL)
    {
        printf("linked list is empty nothing to print\n");
        return;
    }
    else
    {
        printf("\n printing values ... \n");

        while(temp-> next != start)
        {

            printf("%d\n", temp-> data);
            temp =temp-> next;
        }
        printf("%d\n", temp -> data);
    }

}

