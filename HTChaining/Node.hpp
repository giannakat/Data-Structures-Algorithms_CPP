#include <string>
using namespace std;

struct Node{
    string elem;
    Node*  next;

    Node(string value){
        elem = value;
        next = nullptr;
    }
};