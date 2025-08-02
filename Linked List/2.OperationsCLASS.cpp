#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    Node* tail;
    Node* head;
public:
    List(){
        tail = head = NULL;
    }

    void push_back(int val){
        Node* new_node = new Node(val);
        
        if(head == NULL){
            head = tail = new_node;
            return;
        }else{
            tail->next = new_node;
            tail = new_node;
            tail->next = NULL;
        }
    }

    void push_front(int val){
        Node* new_node = new Node(val);
        
        if(head == NULL){
            head = tail = new_node;
            return;
        }else{
            new_node->next = head;
            head = new_node;
        }
    }

    void print(){
        Node* tmp = head;
        while(tmp != NULL){
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
};


// class Node{
// public:
//     int data;
//     Node* next;

//     Node(int val){
//         data = val;
//         next = NULL;
//     }
// };

// class List{
//     Node* head;
//     Node* tail;

// public:
//     List(){
//         head = tail = NULL;
//     }

//     void push_front(int val){
//         Node* new_node = new Node(val);
//         // Node new_node(val);
//         // basically creates a static object

//         if(head == NULL){ // meaning empty list
//             head = tail = new_node;
//             return;
//         }else{
//             new_node->next = head;
//             head = new_node;
//         }
//     }


//     void print(){
//         Node* tmp = head;
//         while(tmp != NULL){
//             cout << tmp->data << " ";
//             tmp = tmp->next;
//         }
//         cout << endl;
//     }

// };

int main(){
    List ll;
    
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(5);
    ll.push_front(19);

    ll.print();

    cout << endl;

    ll.push_back(12);
    ll.push_back(23);
    ll.push_back(98);
    ll.push_back(19);

    ll.print();
    return 0;
}