#include <iostream>
#include <string>
using namespace std;

class HashTable{
    public:
    virtual int insert(string key) = 0;
    virtual int search(string key) = 0;
    virtual int remove(string key) = 0;
    virtual void print() = 0;
};
