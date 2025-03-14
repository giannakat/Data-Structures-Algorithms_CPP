#include <iostream>
#include "InsertionSort.hpp"
using namespace std;

int main(){
    int s;
    
    cout << "Enter the size of the array: ";
    cin >> s;

    int arr[s];

    cout << "Enter elements:" << endl;
   for(int i = 0; i < s; i++){
    cin >> arr[i];
   }

   cout << "Unsorted elements: " << endl;
   for(int i = 0; i < s; i++){
    cout << arr[i] << " ";
   }

   cout << endl;

   Sortable* sorter = new InsertionSort();
   sorter->sort(arr, s);

   cout << "Sorted elements: " << endl;
   for(int i = 0; i < s; i++){
    cout << arr[i] << " ";
   }

    return 0;
}