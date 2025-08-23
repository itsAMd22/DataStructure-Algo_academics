#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int value){
        //default constructor
        data = value;
        next = NULL;
    }
};

void print(Node* &head){
    Node* tmp = head;
    cout << "HEAD |>>> ";
    while(tmp){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << " <<<| TAIL\n";
}

Node* insertAtHead(Node* &head, int value){
    Node* new_node = new Node(value);
    new_node->next = head;
    head = new_node;
    return head;
}

Node* insertAtTail(Node* &head, int value){
    Node* new_node = new Node(value);
    if(head == NULL){
        head = new_node;
    }else{
        Node* tmp = head;
        while(tmp->next)    tmp = tmp->next;
        tmp->next = new_node;
    }
    return head;
}

Node* insertAtPos(Node* &head, int value, int pos){
    Node* new_node = new Node(value);
    if(pos == 0){
        //insert at head
        new_node->next = head;
        head = new_node;
        //automatically handles the case where the list is emtpy
    }else{
        Node* tmp = head;
        for(int i = 0; i <= pos - 2 && tmp ; i++){
            tmp = tmp->next;
        }
        if(tmp == NULL){
            //pos > maximum index + 1
            cout << "insertion not possible, overflow!\n";
            return head;
        }else if(!tmp->next){
            //insert at tail
            tmp->next = new_node;
        }else{
            //insert in-between
            new_node->next = tmp->next;
            tmp->next = new_node;
        }
    }
    return head;
}

Node* insertAfterPos(Node* &head, int value, int pos){
    //inserting after pos = inserting at position + 1
    pos++;

    Node* new_node = new Node(value);
    if(pos == 0){
        //insert at head
        new_node->next = head;
        head = new_node;
        //automatically handles the case where the list is emtpy
    }else{
        Node* tmp = head;
        for(int i = 0; i <= pos - 2 && tmp ; i++){
            tmp = tmp->next;
        }
        if(pos < 0){
            cout << "insertion not possible, underflow!\n";
            return head;
        }else if(tmp == NULL){
            //pos > maximum index + 1
            cout << "insertion not possible, overflow!\n";
            return head;
        }else if(!tmp->next){
            //insert at tail
            tmp->next = new_node;
        }else{
            //insert in-between
            new_node->next = tmp->next;
            tmp->next = new_node;
        }
    }
    return head;
}

Node* insertBeforePos(Node* &head, int value, int pos){
    Node* new_node = new Node(value);


    if(pos == 0){
        //insert at head
        new_node->next = head;
        head = new_node;
        //automatically handles the case where the list is emtpy
    }else{
        
        Node* tmp = head;
        for(int i = 0; i <= pos - 2 && tmp ; i++){
            tmp = tmp->next;
        }
        if(pos < 0){
            cout << "insertion not possible, underflow!\n";
            return head;
        }else if(tmp == NULL){
            //pos > maximum index + 1
            cout << "insertion not possible, overflow!\n";
            return head;
        }else if(!tmp->next){
            //insert at tail
            tmp->next = new_node;
        }else{
            //insert in-between
            new_node->next = tmp->next;
            tmp->next = new_node;
        }
    }
    return head;
}

Node* deleteHead(Node* &head){
    if(!head){
        cout << "underflow!\n";
        return head;
    }
    Node* tmp = head;
    head = head->next;
    delete tmp;
    tmp = NULL;
    return head;
}

Node* deleteTail(Node* &head){
    if(!head){
        cout << "underflow!\n";
        return head;
    }else if(!head->next){
        delete head;
        head = NULL;
        return head;
    }

    Node* tmp = head;
    while(tmp->next->next)    tmp = tmp->next;
    Node* tobedel = tmp->next;
    delete tobedel;
    tobedel = NULL;
    tmp->next = NULL;
    return head;
}


Node* deleteAtPos(Node* &head, int pos){
    if(pos < 0 || !head){
        cout << "Deletion not possible, underflow!\n";
    }else if(pos == 0){
        Node* tmp = head;
        head = head->next;
        delete tmp;
        tmp = NULL;
    }else{
        Node* tmp = head;
        for(int i = 0 ; tmp && i <= pos - 2 ; i++){
            tmp = tmp->next;
        }
        if(!tmp || !tmp->next){
            cout << "Deletion not possible, overflow!\n";
        }else{
            Node* tobedel = tmp->next;
            tmp->next = tmp->next->next;
            delete tobedel;
            tobedel = NULL;
        }
    }
    return head;
}

int main(){
    Node* head = NULL;
    // / Insertion tests
    // cout << "Inserting at head: ";
    insertAtHead(head, 30);
    insertAtHead(head, 20);
    insertAtHead(head, 10);
    print(head); 
     // 10 -> 20 -> 30 -> NULL

    
    insertAtTail(head, 40);
    insertAtTail(head, 50);
    print(head);  // 10 -> 20 -> 30 -> 40 -> 50 -> NULL

    
    insertAfterPos(head, 35, 2);
    print(head);  // 10 -> 20 -> 30 -> 35 -> 40 -> 50 -> NULL

    insertBeforePos(head, 38, 4);
    print(head);  // 10 -> 20 -> 30 -> 35 -> 38 -> 40 -> 50 -> NULL

    // cout << "Insert at position 3: ";
    insertAtPos(head, 25, 2);
    print(head);  // 10 -> 20 -> 25 -> 30 -> 35 -> 38 -> 40 -> 50 -> NULL


    cout << endl << endl;
    insertBeforePos(head, 99, -1);
    print(head);
    // // // Deletion tests
    // // cout << "Delete head: ";
    // deleteHead(head);
    // // printList(head);  // 20 -> 25 -> 30 -> 35 -> 38 -> 40 -> 50 -> NULL

    // // cout << "Delete tail: ";
    // deleteTail(head);
    // printList(head);  // 20 -> 25 -> 30 -> 35 -> 38 -> 40 -> NULL

    // cout << "Delete at position 4: ";
    // deleteAtPosition(head, 10);
    // printList(head);  // 20 -> 25 -> 30 -> 38 -> 40 -> NULL
    return 0;
}
