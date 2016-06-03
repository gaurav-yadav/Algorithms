#include <iostream>

struct node{
int data;
node *next;
node *prev;

};

node * head;


void insert(int x){
	node *iterator=head;
node *newNode = new node ; //create the node before using it .. 

newNode->data=x;
newNode->next=NULL;
newNode->prev=NULL;
//check if head null 
if(iterator==NULL)
{
	head=newNode;//our work here is done
	return;
}
else{
	//iterate and add it to the end
	while(iterator->next!=NULL)
	{
		iterator=iterator->next;
	}
	//reached end now add the node and return;
iterator->next=newNode;
newNode->prev=iterator;

}

}

void printll(){
node* iterator;
iterator=head;
while(iterator){
	std::cout << iterator->data << "-->";
	iterator=iterator->next;
}

}

int main(int argc, char const *argv[])
{
	/* code */
head=NULL;
int i=0;
for (i=0 ;i<10;i++){
	insert(i);
}
printll();

	return 0;
}