
#include <stdio.h>
#include <stdlib.h>




//BST Tree Structure
typedef struct treeNode
{
    int data;
    int declerationLineNumber; 
    char * id; 
    struct treeNode *left;
    struct treeNode *right;
}treeNode;


//Linked List Stack Structure 
struct node
{
    int level;
    struct treeNode *treePtr;
    struct node *ptr;
}*top,*cursor,*temp;





int  getTop();

 
int count = 0;
 
void init()
{
    top = NULL;
    
}
 
void push(int data)
{
    if (top == NULL)
    {
        top =(struct node *)malloc(1*sizeof(struct node));
        top->ptr = NULL;
        top->level = data;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = top;
        temp->level = data;
        top = temp;
    }
    count++;
    
    
}
 

void display()
{
    cursor = top;
 
    if (cursor == NULL)
    {
     
        
    }
 
    while (cursor != NULL)
    {
        printf("%d\n ", cursor->level);
        cursor = cursor->ptr;
    }
    
    
 }
 

void pop()
{
    cursor = top;
 
    if (cursor == NULL)
    {
        
    }
    else
    {
    cursor = cursor->ptr;
    free(top);
    top = cursor;
    count--;
    
    }
}
 

int topelement()
{
    return(top->level);
}
 
int isEmpty()
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
void destroy()
{
    if(!isEmpty())
    {
        
        cursor = top;
        
        while (cursor != NULL)
        {
            cursor = top->ptr;
            free(top);
            top = cursor;
            cursor = cursor->ptr;
        }
        free(cursor);
        top = NULL; 
        count = 0;
    }
}


/*-----------------------------------------------------------------------------------*/



void PrintInorder(treeNode *leaf)
{
        if(leaf==NULL)
        {
                return;
        }
        PrintInorder(leaf->left);
        printf("%d ",leaf->data);
        PrintInorder(leaf->right);
}

treeNode * Insert(treeNode *leaf,int data)
{
        if(leaf==NULL)
        {
                treeNode *temp;
                temp = (treeNode *)malloc(sizeof(treeNode));
                temp -> data = data;
                temp -> left = temp -> right = NULL;
                return temp;
        }

        if(data >(leaf->data))
        {
                leaf->right = Insert(leaf->right,data);
        }
        else if(data < (leaf->data))
        {
                leaf->left = Insert(leaf->left,data);
        }

        return leaf;

}

treeNode * Delete(treeNode *leaf, int data)
{
        treeNode *temp;
        if(leaf==NULL)
        {
                printf("Element Not Found");
        }
        else if(data < leaf->data)
        {
                leaf->left = Delete(leaf->left, data);
        }
        else if(data > leaf->data)
        {
                leaf->right = Delete(leaf->right, data);
        }
        else
        {
                if(leaf->right && leaf->left)
                {
                        temp = leaf->right;
                        while(temp->left!= NULL){
                            temp = leaf->left;
                        }

                        leaf -> data = temp->data; 
                        leaf -> right = Delete(leaf->right,temp->data);
                }
                else
                {
                        temp = leaf;
                        if(leaf->left == NULL)
                                leaf = leaf->right;
                        else if(leaf->right == NULL)
                                leaf = leaf->left;
                        free(temp); 
                }
        }
        return leaf;

}

treeNode * Find(treeNode *leaf, int data)
{
        if(leaf==NULL)
        {
                return NULL;
        }
        if(data > leaf->data)
        {
                return Find(leaf->right,data);
        }
        else if(data < leaf->data)
        {
            
                return Find(leaf->left,data);
        }
        else
        {
                
                return leaf;
        }
}

