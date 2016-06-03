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

 int main(int argc, char const *argv[])
{
insertInBst(4);
insertInBst(3);
insertInBst(7);
insertInBst(5);
insertInBst(1);
insertInBst(2);

//bstInorder(root);
insertInBst(6);
insertInBst(28);
//bstInorder(root);
bstPostorder(root);
	/* code */
	return 0;
}