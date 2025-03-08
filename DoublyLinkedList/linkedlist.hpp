// TODO entire implementation and add more header file/s as needed
#include<iostream>
#include"list.h"
#include"node.cpp"
using namespace std;


class LinkedList : public List{
    
    node* head;
    node* tail;
    int s;
    
    public:
    
    LinkedList(){
        head = tail = nullptr;
        s = 0;
    }
    
     void insert(int num){
         node* n = new node();
         n->elem = num;
         n->next = nullptr;
         
         if(!head){
             n->prev = nullptr;
             head = tail = n;
         }else{
             tail->next = n;
             n->prev = tail;
             tail = n;
         }
         s++;
     }
     
     int get(int pos){
         if(pos > s || pos < 1) throw logic_error("Invalid position");
         
         node* curr = head;
         for(int i = 1; i < pos; i++){
             curr = curr->next;
         }
         return curr->elem;
     }
     
     int remove(int num){
         
         node* curr = head;
         
         for(int i = 0; i < s; i++){
             if(curr->elem == num){
                 node* temp = curr;
                 
                 if(head == curr){
                     head = curr->next;
                     
                     
                     if(!head){
                         tail = nullptr;
                     }else{
                         head->prev = nullptr;
                     }
                     
                 }else if(curr == tail){
                     tail = curr->prev;
                     tail->next = nullptr;
                 }else{
                     curr->prev->next = temp->next;
                     curr->next->prev = temp->prev;
                 }
                 
                 
                 delete temp;
                 s--;
                 return i+1;
             }
             curr = curr->next;
         }
         
         
         return 0;
     }
     
     void print(){
         node* curr = head;
         
         cout << "FROM HEAD: ";
         if(s == 0){
             cout << "(none)";
         }
         for(int i = 0; i < s; i++){
             if(!curr->next){
                 cout << curr->elem << " ";
             }else{
                 cout << curr->elem << " -> ";
             }
             curr = curr->next;
         }
         cout << endl;
         
         cout << "FROM TAIL: ";
         if(s == 0){
             cout << "(none)";
         }
         curr = tail;
         for(int i = 0; i < s; i++){
             if(!curr->prev){
                 cout << curr->elem << " ";
             }else{
                 cout << curr->elem << " <- ";
             }
             curr = curr->prev;
         }
         cout << endl;
     }
     
     int size(){
         return s;
     }
     
     bool isEmpty(){
         return s == 0;
     }
     
     void addAt(int num, int pos){
         if(pos > s+1 || pos < 1) throw logic_error("Invalid position");
         
         node* n = new node();
         n->elem = num;
         
         
         if(pos == 1){
             n->prev = nullptr;
             n->next = head;
             if(head){
                head->prev = n;
             }else{
                 head = tail = n;
             }
             head = n;
         }else if(pos == s+1){
             
             tail->next = n;
             n->prev = tail;
             tail = n;
         }else{
             // 1 2 4 5                   s = 4
             //
             
             node* curr = head;
             for(int i = 0; i < pos-2; i++){
                curr = curr->next;
             }
             n->prev = curr;
             n->next = curr->next;
             if(curr->next){
             curr->next->prev = n;
             }
             curr->next = n;
         }
         s++;
     }
     
     int removeAt(int pos){
         if(pos > s || pos < 1) throw logic_error("Invalid position");
         
         node* temp;
         int value;
         node* curr = head;
         
         if(pos == 1){
             temp = curr;
             value = temp->elem;
             head = head->next;
             
             if(!head){
                 tail = head = nullptr;
             }else{
                 head->prev = nullptr;
             }
         }else if(pos == s){
             temp = tail;
             value = temp->elem;
             tail = temp->prev;
             tail->next = nullptr;
         }else{
             for(int i = 0; i < pos-1; i++){
                 curr = curr->next;
             }
             temp = curr;
             value = temp->elem;
             
             curr->prev->next = temp->next;
             curr->next->prev = temp->prev;
         }
         
         s--;
         delete temp;
         
         return value;
     }
    
};