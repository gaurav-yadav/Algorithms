#include<iostream>


struct node{
    int data;
    node *left;
    node *right;
};

node * root;

void insertInBst(int x){
    node *newnode = new node;
    newnode->data=x;
    newnode->left=NULL;
    newnode->right=NULL;
    
    node * iterator= root;
    //check if root null -- easiest case
    if(iterator==NULL)
        root=newnode;
    else
    {
        //keep looping and everytime deciding if to go left or right. when we find a proper empty space insert it there and
        //do not forget to return
        while(1){
            //decide
            if(x>iterator->data)//we r big we go right
            {
                if(iterator->right==NULL)//check for open space
                {
                    iterator->right=newnode;
                    return;
                }
                else // we move on
                    iterator=iterator->right;
                
            }
            else //check the left branch
            {
                if(iterator->left==NULL)
                {
                    iterator->left=newnode;
                    return;
                }
                else
                    iterator=iterator->left;
            }
            
        }
        
    }
}

void bstInorder(node* head){
    //LRoR
    if(head==NULL)
        return;
    bstInorder(head->left);
    std::cout << head->data << " -->";
    bstInorder(head->right);
    
    
}

void bstPostorder(node* head){
    //LRRo
    if(head==NULL)
        return;
    
    bstPostorder(head->left);
    bstPostorder(head->right);
    std::cout << head->data <<  "  " ;
}

//delete a node --
void DeleteNode(int x){
    //find the node and then -- check the case ..
    node * iterator= new node;
    node * parent = new node;
    
    iterator=root;
    
    while(iterator){
        
        //std::cout<< parent->data << "i am here now \n ";
        if (iterator->data==x) //yay we got the node
        {
            //std::cout<< "got the node breaking \n ";
            
            break;
        }
        else if (iterator->data>x)
        {
            parent=iterator; //to keep track of the node above connecting it..
            iterator=iterator->left;
        }
        else
        {
            parent=iterator; //to keep track of the node above connecting it..
            iterator=iterator->right;
        }
    }
    //handle the case of match not found ..
    std::cout << parent->data << "parent data \n";
    std::cout <<iterator->data<<"iterator data \n";
    //iterator is the node to be deleted
    //handle the cases now - both null  , one is null , nothing is null ,,
    if (iterator->left==NULL && iterator->right==NULL){
        ///parent's left or right to be decided...
        std::cout<< iterator->data << "should get 16 here \n";
        std::cout<< parent->data<< "should get 20 hrer \n";
        if (x>parent->data)
        {
            parent->right=NULL;
            free(iterator);
            return;
        }
        else{
            parent->left=NULL;
            free(iterator);  //have to fix the issue
            return;
        }
    }
    //only one is null
    else if(iterator->left==NULL)
    {
        std::cout<< " one side is null case is null\n";
        if(parent->data>iterator->data)
        {
            parent->left=iterator->right;
            free(iterator);
        }
        else
        {
            parent->right=iterator->right;
            free(iterator);
        }
    }
    else if (iterator->right==NULL)
    {
        std::cout<<"right is null";
        if(parent->data>iterator->data)
        {
            parent->left=iterator->left;
            free(iterator);
        }
        else
        {
            parent->left=iterator->right;
            free(iterator);
        }
    }
    else
    {
    //both are not null
    std::cout << "toughest case ";
    node * temp= new node;
    temp=iterator;
        iterator=iterator->right; //find min in right branch.
        
    while(iterator->left!=NULL)
    {
        iterator=iterator->left;
    }//reached the left most elt copy and delete now
    temp->data=iterator->data;
    std::cout <<temp->data << "trying to delete this node \n";
    //free(iterator);
       free(iterator);
    
}
}

int main(int argc, char const *argv[])
{
    insertInBst(10);
    insertInBst(12);
    insertInBst(15);
    insertInBst(20);
    insertInBst(16);
    insertInBst(21);
    insertInBst(5);
    insertInBst(3);
    insertInBst(6);
    insertInBst(1);
    insertInBst(2);
    
    //bstInorder(root);
    
    //bstInorder(root);
    //bstPostorder(root);
    DeleteNode(5);
    bstInorder(root);
    DeleteNode(16);
    bstInorder(root);
    /* code */
    return 0;
}