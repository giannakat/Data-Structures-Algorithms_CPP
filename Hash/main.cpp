#include <iostream>
#include "hash.hpp"
using namespace std;

int main(){
    vector<int> a = {15, 11, 27, 8, 12}; // Input keys
    Hash h(7); // Create a hash table with 7 buckets

    for (int key : a)
        h.insertItem(key); // Insert keys

    h.deleteItem(12); // Delete key 12

    h.displayHash(); // Print hash table
    return 0;


}