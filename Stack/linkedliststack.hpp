#include "stack.hpp"
#include "node.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;

class LinkedListStack : public Stack {
	node* head;
	node* tail;
	int _size;

	public:
		LinkedListStack() {
            head = NULL;
            tail = NULL;
            head = tail;
            _size = 0;
		}

		void push(int num) {
		    node* n = new node();
		    n->elem = num;
		    n->next = NULL;
		    if(!head){
		        head = n;
		        tail = n;
		        _size++;
		    }else{
		        tail->next = n;
                tail = n;
                _size++;
		    }
            tail->next= NULL;
            
		}

		int pop() {
		    node* temp;
		    int value = 0;
            if(_size == 0){
                throw logic_error("Cannot remove from empty stack");
            }
         
            if(head == tail){
		        value = tail->elem;
		        delete tail;
		        head = NULL;
		        tail = NULL;
		  
		    }else{
	
		        node* curr = head;
		        while(curr->next != tail){
		            curr = curr->next;
		        } 
		        value = curr->next->elem;
		        delete tail;
		        curr->next = nullptr;
		        tail = curr;
		    } 
		    _size--;
		    return value;
		}

		int top() {
		    if(_size == 0){
                throw logic_error("Cannot retrieve from empty stack");
            }
            return tail->elem;
		}

		int size() {
            return _size;
		}

		bool isEmpty() {
            return _size==0;
		}
};