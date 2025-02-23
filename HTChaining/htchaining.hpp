#include<iostream>
#include<vector>
#include "hashtable.hpp"
#include "LinkedList.hpp"
using namespace std;

class HTChaining : public HashTable{

    int N;
    vector<LinkedList> table;

    int hash_code(string key){
        int hash = 0;
        for(char c : key){
            hash = (hash*5+c);
        }
        return hash;
    }

    int compress(int code){
        return code%N;
    }

    int hashfn(string key){
        return compress(hash_code(key));
    }

    public:



    HTChaining(int N){
        this->N = N;
        table.resize(N);
    }

    int insert(string key){
        int hash = this->hashfn(key);
        if(table[hash].search(key) != -1){
            throw runtime_error("Already add key " + key );
        }
        table[hash].add(key);
        return table[hash].getSize();
    }


    int search(string key){
        int hash = this->hashfn(key);
        return table[hash].search(key);
    }

    int remove(string key){
        int hash = this->hashfn(key);
        return table[hash].remove(key);
    }

    void print(){
        for(int i = 0; i < N; i++){
            cout << i << "\t";
            table[i].print();
        }
    }

};