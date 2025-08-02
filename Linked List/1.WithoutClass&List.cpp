#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next = NULL;
};

void push_front(Node* &head, Node* &tail, int val){
    Node* new_node = new Node;
    new_node->data = val;
    if(head == NULL){
        head = tail = new_node;
        return;
    }
    new_node->next = head;
    head = new_node;
}

void push_back(Node* &head, Node* &tail, int val){
    Node* new_node = new Node;
    new_node->data = val;
    if(head == NULL){
        head = tail = new_node;
        return;
    }
    tail->next = new_node;
    tail = new_node;
    tail->next = NULL;
}

void print(Node* head, Node* tail){
    Node* tmp = head;
    while(tmp != NULL){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main(){
    Node* head;
    Node* tail;
    
    head = tail = NULL;


    push_front(head, tail, 6);
    push_front(head, tail, 7);
    push_front(head, tail, 8);
    push_front(head, tail, 9);

    push_back(head, tail, 6);
    push_back(head, tail, 7);
    push_back(head, tail, 8);
    push_back(head, tail, 9);


    print(head, tail);
    return 0;
}