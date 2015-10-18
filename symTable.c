#include "driver.h"
#include <stdlib.h>

node * createTable(node * top)
{
    top = NULL;
    return top;
    
}

node * pushLevel(node * top, int data)
{
    
    if (top == NULL)
    {
      
        top =(struct node *)malloc(1*sizeof(struct node));
        top->ptr = NULL;
        top->level = data;
        top->treePtr = NULL;
        top->size = 0;
    }
    else
    {
        node * temp;
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = top;
        temp->level = data;
        top = temp;
    }
    top->size++;
    
    return top;
    
    
}

node * popLevel(node * top)
{
    node * cursor;
    cursor = top;
 
    if (cursor == NULL)
    {
        
    }
    else
    {
    cursor = cursor->ptr;
    free(top);
    top = cursor;
    top->size--;
    
    }
    
    return top;
}

 
node * destroy(node * top)
{
    node * cursor;
    if(top != NULL)
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
        top->size = 0;
        return top;
    }
}
/***************************************/

void printIdentifiers(treeNode *leaf)
{
        if(leaf==NULL)
        {
                return;
        }
        
        /* LISTITEM */ 
        printIdentifiers(leaf->left);
        fprintf(symbolTableFile,"%d ",leaf->id);
        fprintf(symbolTableFile,"%d ",leaf->dataI);
        printIdentifiers(leaf->right);
}

treeNode * insertIdentifier(treeNode *leaf,int data)
{
        if(leaf==NULL)
        {
                treeNode *temp;
                temp = (treeNode *)malloc(sizeof(treeNode));
                temp -> id = data;
                temp -> left = temp -> right = NULL;
                return temp;
        }

        if(data >(leaf->id))
        {
                leaf->right = insertIdentifier(leaf->right,data);
        }
        else if(data < (leaf->id))
        {
                leaf->left = insertIdentifier(leaf->left,data);
        }

        return leaf;

}

treeNode * deleteIdentifier(treeNode *leaf, int data)
{
        treeNode *temp;
        if(leaf==NULL)
        {
                printf("Element Not Found");
        }
        else if(data < leaf->id)
        {
                leaf->left = deleteIdentifier(leaf->left, data);
        }
        else if(data > leaf->id)
        {
                leaf->right = deleteIdentifier(leaf->right, data);
        }
        else
        {
                if(leaf->right && leaf->left)
                {
                        temp = leaf->right;
                        while(temp->left!= NULL){
                            temp = leaf->left;
                        }

                        leaf -> id = temp->id; 
                        leaf -> right = deleteIdentifier(leaf->right,temp->id);
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

treeNode * findIdentifier(treeNode *leaf, int data)
{
        if(leaf==NULL)
        {
                return NULL;
        }
        if(data > leaf->id)
        {
                return findIdentifier(leaf->right,data);
        }
        else if(data < leaf->id)
        {
            
                return findIdentifier(leaf->left,data);
        }
        else
        {
                
                return leaf;
        }
}


void printTable(node * top)
{
    node * cursor;
    cursor = top;
 
    if (cursor == NULL)
    {
     
        
    }
 
    while (cursor != NULL)
    {
        fprintf(symbolTableFile,"%s\n", "Level:");
        fprintf(symbolTableFile,"%d\n", cursor->level);
        fprintf(symbolTableFile,"%s\n", "IDS at that Level:");
        printIdentifiers(cursor->treePtr);
        cursor = cursor->ptr;
    }
    
    
 }
 

treeNode* shadows(int id, node * top){

    int i = 0;
    node * cursor;
    cursor = top->ptr;
     
    
    if(cursor == NULL)
    {
        return NULL; 
        
    }
    
   
     while (cursor != NULL)
    {
    
        if( findIdentifier(cursor->treePtr, id ) != NULL)
        {
            printf("but... it shadows a variable in level %d\n", cursor->level );
            return cursor->treePtr;
        }
        cursor = cursor->ptr;

    }

    return NULL;


}


/* LISTITEM */ 


treeNode * deleteTree(treeNode *leaf){

        if(leaf->left !=NULL)
        {
                return deleteTree(leaf->right);
        }
        if(leaf->right !=NULL)
        {
                return deleteTree(leaf->right);
        }

        free(leaf);
        leaf = NULL;


}
