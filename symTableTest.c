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
        top->treePtr = NULL;
        top->level = data;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = top;
        temp->level = data;
        top = temp;
        top->treePtr = NULL;
    }
    count++;
    
    
}
 
treeNode * find(treeNode *leaf, int data)
{
        if(leaf==NULL)
        {
                return NULL;
        }
        if(data > leaf->data)
        {
                return find(leaf->right,data);
        }
        else if(data < leaf->data)
        {
            
                return find(leaf->left,data);
        }
        else
        {
                
                return leaf;
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



void printBST(treeNode *leaf)
{
        if(leaf==NULL)
        {
                return;
        }
        printBST(leaf->left);
        printf("%d ",leaf->data);
        printBST(leaf->right);
}

treeNode * insert(treeNode *leaf,int data)
{
        if(top != NULL){
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
                    leaf->right = insert(leaf->right,data);
            }
            else if(data < (leaf->data))
            {
                    leaf->left = insert(leaf->left,data);
            }

            return leaf;
        }
        
        return NULL;
}

treeNode * delete(treeNode *leaf, int data)
{
        treeNode *temp;
        if(leaf==NULL)
        {
                printf("Identifier Not Found");
                return NULL;
        }
        else if(data < leaf->data)
        {
                leaf->left = delete(leaf->left, data);
        }
        else if(data > leaf->data)
        {
                leaf->right = delete(leaf->right, data);
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
                        leaf -> right = delete(leaf->right,temp->data);
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


treeNode * deleteTree(treeNode *leaf){

    if(leaf != NULL){
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
    
    return NULL;

}


void display()
{
    cursor = top;
 
    if (cursor == NULL)
    {
           
    }
 
    while (cursor != NULL)
    {
        printf("Level: ");
        printf("%d\n", cursor->level);
        printf("%s\n", "IDS at that Level:");
        printBST(cursor->treePtr);
        printf("\n--------------------------\n");
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
    
        if( find(cursor->treePtr, id ) != NULL)
        {
            return cursor->treePtr;
        }
        cursor = cursor->ptr;

    }

    return NULL;

}

void pop()
{
    cursor = top;
 
    if (cursor == NULL){
    
       return;
    }
    else
    {
        deleteTree(cursor->treePtr);
    cursor = cursor->ptr;
    free(top);
    top = cursor;
    count--;
    
    
    }
}


int main(){
    int selection;
    init();
    while (1)
    {
        printf( "\t++++++++++++++++++\n"
                "\t1 to push level\n"
                "\t2 to add identifier\n"
                "\t3 to pop level\n"
                "\t4 to find an id\n"
                "\t5 to exit\n"
                "\t++++++++++++++++++\n"    );
        printf("\tEnter Selection Please.\n");
        scanf("%i", &selection);
        printf("\n");
        switch(selection){
            case (1):
            push(count);            
            break;
            case (2):
            if(top == NULL){break;}
            printf("Enter an integer to enter into top\n");
            scanf("%i", &selection);
            printf("\n");
            if(shadows(selection) != NULL){
                printf("WARNING WARNING WARNING WARNING\n");
                printf("%d shadows Varaiable in Level %d \n\n", selection ,cursor->level );
                printf("WARNING WARNING WARNING WARNING\n\n");
            } 
            top->treePtr = insert(top->treePtr, selection); 
            printf("Press 1 to Continue\n");
            scanf("%i", &selection); 
            printf("\n");      
            break;
            case (3):
  
            pop();            
            break;
            case(4):
                if(top == NULL){break;}
                printf("Enter an integer to find in top \n");
                scanf("%i", &selection);
                printf("\n");
                if(find(top->treePtr, selection) != NULL){
                
                    printf("Element Found in Top \n");
                    
                }
                
                else{
                
                        if(shadows(selection) != NULL){
                            
                            printf(" Found %d in Level %d \n", selection ,cursor->level );
                            printf("Press 1 to Continue\n");
                            scanf("%i", &selection);
                        }    
                
                }
            break;
            
            case(5):
                return 0;

        }
        display();
    }


return 0; 

}





