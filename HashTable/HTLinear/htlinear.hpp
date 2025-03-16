#include <iostream>
#include <cstdlib>
#include "hashtable.hpp"
using namespace std;

template <typename K>
class HTLinear : public HashTable<K>{

    K* table;
    int N;
    int count;

    public:

    //constructor
    HTLinear<K>(int N){
        table = (K*)calloc(N, sizeof(K));
        this->N = N;
        count = 0;
    }

    //returns the hash code of the specific value(key)
     int hash_code(K key){
        return key;
     }

     //a function that will provide us a distint code using MAD 
     //formula (a * code + b) % p % N
     int compress(int code){
        return (59 * code + 17) % 509 % N;
     }

     //insert in hashtable while returning number of collisions it had to deal with
     int insert(K key){
        if(count == N){
            throw logic_error("table is already full");
        }

        if(search(key) >= 0){
            throw logic_error("Already added key" + to_string(key));
        }

        int collision = 0;
        int code = this->hashfn(key);

        while(true){
            if(table[code]>0){
                code = (code+1) % N;
                collision++;
            }else{
                table[code] = key;
                count++;
                break;
            }
        }
        return collision;
     }


     int search(K key){
        int ctr = 0;
        int code = this->hashfn(key);
        int orig_code = this->hashfn(key);
        while(true){
            if(table[code] == key){
                return ctr;
            }else if(table[code] == 0){
                return -1;
            }

            code = (code+1)%N;

            if(code == orig_code){
                return -1;
            }
            ctr++;
        }
     }


     int remove(K key){
        int position = search(key);

        if(position == -1){
            return -1;
        }

        int code = (position + this->hashfn(key))%N;
        table[code] = -1;
        if(table[code+1] == 0){
            for(int i = code+1; table[i] != -1; i--){
                table[i] = 0;
                if(i==0){
                    i = N;
                }
            }
        }
        count--;

        if(count == 0){
            for(int i = 0; i < N; i++){
                table[i] = 0;
            }
        }

        return position;
     }


     void print(){
        for(int i = 0; i < N; i++){
            cout << i << "\t";
        }
        cout << endl;
        for(int j = 0; j < N; j++){
            if(table[j] == -1){
                cout << "0\t";
            }else cout << table[j] << "\t";
        }
        cout << endl;
     }
};