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

    void sort1(int arr[], int size){
        int maxValue = arr[0];

        for(int i = 1; i < size; i++){
            if(arr[i]>maxValue){
                maxValue = arr[i];
            }
        }

        int count[size+1] = {0};

        for(int i = 0; i < size; i++){
            count[arr[i]]++;
        }

        int index = 0;
        for(int i = 0; i <= maxValue; i++){
            if(count[i] > 0){
                arr[index++] = i;
                count[i]--;
            }
        }
    }

    //stable sort
    void stableCountSort(int arr[], int size){
        int maxValue = arr[0];
        int output[size];

        for(int i = 0; i < size; i++){
            if(maxValue < arr[i]){
                maxValue = arr[i];
            }
        }

        int count[size+1] = {0};
        
        //count occurence 
        for(int i = 0; i < size; i++){
            count[arr[i]]++;
        }

        //prefix sum
        for(int i = 1; i < size; i++){
            count[i] += count[i-1];
        }

        //build output   
        for(int i = 0; i < size; i++){
            output[count[arr[i]]-1] = arr[i];
            count[arr[i]]--;
        }

        for(int i = 0; i < n; i++){
            arr[i] = output[i];
        }

    }
};