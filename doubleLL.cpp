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
std::cout << std::endl;
}

void deletell(int x){
	node *iterator=head;
	if(iterator==NULL)
		return; //nothing to delete empty LL
	//edge cases in using a single pointer is delting the first and last elt.. 
	if(iterator->data==x)
	{
		head=iterator->next;
		iterator->next->prev=NULL; //break the backward connection
		iterator->next=NULL;
		free(iterator);
		return; //we are done here lets go back
	}
	while(iterator->next->data!=x || iterator==NULL) //either we found or we reached end -- not fixing it now
	{
		iterator=iterator->next;
	}
	//found the element
	//if its last elt-- iterator->next->NULL
	if(iterator->next->next==NULL){

	
	iterator->next=NULL;
	free(iterator->next);
	}
	else
	{
	//iterator--> next(to be deleted)-->next 
	iterator->next=iterator->next->next;
	iterator->next->next->prev=iterator;  //ye phtega end element pe without if 
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
deletell(9);
printll();	
deletell(0);
printll();

	return 0;
}