//
//  main.cpp
//  Algorithms
//
//  Created by Yadav, Gaurav on 5/31/16.
//  Copyright © 2016 Yadav, Gaurav. All rights reserved.
//

#include <iostream>
struct node{
    int data;
    struct node *next;
    
};
node *head=NULL;


void insert(int x){
//create a new node
    //check if head == null new node==heaad
    //else iterate and assign.
    node *newNode = new node;
    newNode->data=x;
    newNode->next=NULL;
    node *cur =head ;
    if(cur==NULL)
    {
        head=newNode;
        return;
    }
    else
    {
    while(cur->next!=NULL)
    {
        cur=cur->next;
    }
        cur->next=newNode;
        return;
    }

}

void print(){

    if(head==NULL){return;}
    else{
        node *temp = head;
        while(temp){
            std::cout << temp->data << "-->";
            temp=temp->next;
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    insert(334);
    insert(56);
    insert(34);
 
    print();
    
}