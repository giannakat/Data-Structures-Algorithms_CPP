#include "Sortable.hpp"

class CountingSort:public Sortable{

    public:
    void sort(int arr[], int size){
        if (size <= 0) return; // Edge case: empty array

        // Find the maximum value manually
        int maxVal = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] > maxVal) {
                maxVal = arr[i];
            }
        }

        // Create a count array and initialize to 0
        int* count = new int[maxVal + 1]();
        
        // Count occurrences of each element
        for (int i = 0; i < size; i++) {
            count[arr[i]]++;
        }

        // Reconstruct the sorted array
        int index = 0;
        for (int i = 0; i <= maxVal; i++) {
            while (count[i] > 0) {
                arr[index++] = i;
                count[i]--;
            }
        }

        // Clean up dynamically allocated memory
        delete[] count;
    }
};