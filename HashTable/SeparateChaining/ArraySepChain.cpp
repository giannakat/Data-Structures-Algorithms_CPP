#include<iostream>
#include"hashtable.hpp"
using namespace std;

class ArraySepChain:public HashTable{

    int N;
    int** table;
    
    public:
    
    ArraySepChain(int size){
        N = size;
        table = new int*[N];
        
        for(int i = 0; i < N; i++){
                table[i] = new int[5];
                    
                    for(int j = 0; j < 5; j++){
                            table[i][j] = -1;
                    }
                }
        }
        
        int hash_code(int key){
            return key;
        }
        
        int compress(int code){
            int a = 72;
            int b = 13;
            int p = 101;
            return ((a*code) + b) % p % N;
        }
        
        int insert(int key){
                int index = this->hashfn(key);
                
                if(search(key) > -1){
                    throw logic_error("Already exist");
                }
                
                for(int i = 0; i < 5; i++){
                    if(table[index][i]==-1){
                            table[index][i] = key;
                            return i+1;
                    }
                }
                throw logic_error("full bucket");
        }
        
        int search(int key){
            int index = this->hashfn(key);
            
            for(int i  = 0; i < 5; i++){
                if(table[index][i] == key){
                    return i;
                }
                if(table[index][i] == -1){
                    break;
                }
            }		
            return -1;
        }
        
        int remove(int key){
            int index = this->hashfn(key);
            
            
            for(int i = 0; i < 5; i++){
                if(table[index][i] == key){
                    
                    for(int j = 0; j < 4; j++){
                        table[index][j] = table[index][j+1];
                    }
                    
                    table[index][4] = -1;
                    
                    int count = 0;
                    for(int j = 0; j < 5; j++){
                        if(table[index][i] != -1){
                            count++;
                        }
                    }
                    return count;
                }
            }
            return -1;
        }
        
        void print(){
            for(int i = 0; i < N; i++){
                cout << i << "\t";
                    for(int j = 0; j < 5; j++){
                        if(table[i][j] == -1) break;
                        cout << table[i][j] << "\t";
                    } 
                cout << endl;
            }
            cout << endl; 
        }
                    
    };