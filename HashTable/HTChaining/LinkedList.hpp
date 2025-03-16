#include "node.hpp"
#include <iostream>
using namespace std;

class LinkedList{

    Node* head;
    Node* tail;
    int size;

    public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void add(string key){
        Node* n = new Node(key);
        if(head == nullptr){
            head = n;
            tail = n;
        }else{
            tail->next = n;
            tail = n;
        }
        size++;
    }

    int search(string key){
        Node* curr = head;
        int count = 0;

        while(curr){
            if(curr->elem == key){
                return count;
            }
            curr = curr->next;
            count++;
        }
        return -1;
    }

    int remove(string key){
        Node* curr = head;
        Node* prev = nullptr;

        while(curr){
            if(curr->elem == key){
                if(prev){
                    prev->next = curr->next;
                }else{
                    head = curr->next;
                }
                delete curr;
                size--;
                return size;
            }
            prev = curr;
            curr = curr->next;
        }
        return -1;
    }

    void print(){
        Node* curr = head;
        while(curr){
            cout << curr->elem;
            if(curr->next){
                cout << "\t";
            }
            curr = curr->next;
        }
        cout << endl;
    }

    int getSize(){
        return size;
    }


};