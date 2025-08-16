#include<iostream>
using namespace std;


//Definition of node
struct Node{
    int data;
    Node* next;
    Node(int value){
        data = value;
        next = NULL;
    }
};

Node* insertAtHead(Node* &head, int value){
    // 1. create a node
    Node* new_node = new Node(value);

    // // 2. connect it to the list
    // if(head == NULL){
    //     // Case 1 : list is empty, new_node will be the head.
    //     head = new_node;
    //     return head;
    // }else{
    //     // Case 2 : list is not empty, so head will be updated apon insertion.
    //     new_node -> next = head;
    //     head = new_node;
    // }

    // // both case can be handled at once, using the code below.
    new_node -> next = head;
    head = new_node;

    return head;
}

Node* insertAtTail(Node* &head, int value){
    // 1. create a node
    Node* new_node = new Node(value);

    // 2. connect it to the list
    if(head == NULL){
        // Case 1 : list is empty, new_node will be both - the head and tail
        head = new_node;
        return head;
    }else{
        // Case 2 : list is not empty, so traverse until the tail before insertion.
        Node* tmp = head;
        while(tmp -> next != NULL){
            tmp = tmp -> next;
        }
        tmp -> next = new_node;
    }

    return head;
}

Node* insertAtPos(Node* &head, int value, int position){
    // 1. create a node
    Node* new_node = new Node(value);

    // 2. connect it to the list
    if(position == 0){
        // Case 1 : insert at head.
        new_node -> next = head;
        head = new_node;
    }else{
        // Case 2 : insert at any position except head, this case covers insert at tail too.
        Node* tmp = head;
        for(int i = 0 ; tmp != NULL && i < position - 1 ; i++){
            tmp = tmp -> next;
        }

        if(tmp == NULL){
            // position is out of bound.
            return head;
        }
        new_node -> next = tmp -> next;
        tmp -> next = new_node;
    }

    return head;
}


Node* insertAfterPos(Node* &head, int value, int position){
    // 1. create a node
    Node* new_node = new Node(value);

    // 2. connect it to the list
    if(position == -1){
        // Case 1 : insert at head.
        new_node -> next = head;
        head = new_node;
    }else{
        // Case 2 : insert after any position except head, this case covers insert after tail too.
        Node* tmp = head;
        for(int i = 0 ; tmp != NULL && i < position ; i++){
            tmp = tmp -> next;
        }

        if(tmp == NULL){
            // position + 1 is out of bound.
            return head;
        }

        new_node -> next = tmp -> next;
        tmp -> next = new_node;
    }

    return head;
}

Node* insertBeforePos(Node* &head, int value, int position){
    // inserting before position n is basically inserting afer position (n - 1).

    // 1. create a node
    Node* new_node = new Node(value);
    Node* tmp = head;


    for(int i = 0 ; tmp != NULL &&  i < position - 1 ; i++){
        tmp = tmp -> next;
    }

    if(tmp == NULL){
            // position - 1 is out of bound.
            return head;
    }

    new_node -> next = tmp -> next;
    tmp -> next = new_node;

    return head;
}

Node* DeleteNode(Node* &head, int position){
    // deleting a node creates a vacancy, that vacancy must be eraditcated.

    Node* tmp = head;
    for(int i = 0 ; tmp != NULL && i < position - 1 ; i++){
        tmp = tmp -> next;
    }


    if(tmp == NULL){
            // position - 1 is out of bound.
            return head;
    }

    if(position == 0){
        // Case 1 : delete head
        head = tmp -> next;
        delete tmp;
        tmp = NULL;
    }else{
        // Case 2
        Node* tobedeleted = tmp -> next;
        tmp -> next = tmp -> next -> next;
        delete tobedeleted;
        tobedeleted = NULL;
    }
    
    return head;
}



int main(){

    return 0;
}