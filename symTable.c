
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


void display()
{
    cursor = top;
 
    if (cursor == NULL)
    {
     
        
    }
 
    while (cursor != NULL)
    {
        printf("%s\n", "Level:");
        printf("%d\n", cursor->level);
        printf("%s\n", "IDS at that Level:");
        PrintInorder(cursor->treePtr);
        printf("\n");
        cursor = cursor->ptr;
    }
    
    
 }
 

treeNode* shadows(int id){

    int i = 0;
    
    cursor = top->ptr;
     
    
    if(cursor == NULL)
    {
        return NULL; 
        
    }
    
   
     while (cursor != NULL)
    {
    
        if( Find(cursor->treePtr, id ) != NULL)
        {
            printf("but... it shadows a variable in level %d , nice programming asshole \n", cursor->level );
            return cursor->treePtr;
        }
        cursor = cursor->ptr;

    }

    return NULL;


}
 
int main(){


    //Simulate First Level


    int id = 16;
    
    push(0); 
    top->treePtr = Insert(top->treePtr, 11);
    top->treePtr = Insert(top->treePtr, 12);
    top->treePtr = Insert(top->treePtr, 13);
    top->treePtr = Insert(top->treePtr, 14);
    top->treePtr = Insert(top->treePtr, 15);
    top->treePtr = Insert(top->treePtr, 16);


    push(1); 
    top->treePtr = Insert(top->treePtr, 21);
    top->treePtr = Insert(top->treePtr, 22);
    top->treePtr = Insert(top->treePtr, 23);
    top->treePtr = Insert(top->treePtr, 24);
    top->treePtr = Insert(top->treePtr, 25);
    top->treePtr = Insert(top->treePtr, 100);

    push(2); 
    top->treePtr = Insert(top->treePtr, 31);
    top->treePtr = Insert(top->treePtr, 32);
    top->treePtr = Insert(top->treePtr, 33);
    top->treePtr = Insert(top->treePtr, 34);
    top->treePtr = Insert(top->treePtr, 35);
    top->treePtr = Insert(top->treePtr, 16);



    display();

    if(Find(top->treePtr, id) != NULL){
    
            printf("Found ID: 100 \n");
            if(shadows(id) != NULL){
            

            
            }

    
    }




return 0; 




}


