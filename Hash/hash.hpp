#include <bits/stdc++.h>
using namespace std;

class Hash{
    int bucket;
    vector<vector<int>> table;

    int hashFunction(int x){
        return(x % bucket);
    }

public:
    Hash(int bucket){
        this->bucket = bucket;
        table.resize(bucket);
    }
    
    void insertItem(int key){
        int index = hashFunction(key);
        table[index].push_back(key);        
    }

    void deleteItem(int key){
        int index = hashFunction(key);
        auto it = find(table[index].begin(), table[index].end(), key);
        if(it != table[index].end()){
            table[index].erase(it);
        }

    }

    

    void displayHash(){
        for(int i = 0; i < bucket; i++){
            cout << i;
            for(int x : table[i]){
                cout << "-->" << x;
            }
            cout << endl;
        }
    }


};