#include "Sortable.hpp"

class MergeSort:public Sortable{

    public:

    void sort(int arr[], int size){
        if(size <= 1) return;

        int middle = size/2;

        int left[middle];
        int right[size - middle];

        int i = 0; //left array
        int j = 0; // right array

        for(; i < size; i++){
            if(i < middle){
                left[i] = arr[i];
            }else{
                right[j] = arr[i];
                j++;
            }
            sort(left, middle);
            sort(right, size - middle);
            merge(left, right, arr, middle, size-middle);
        }
        
    }

    void merge(int left[], int right[], int arr[], int leftSize, int rightSize){
    
        while(i < leftSize && j < rightSize){
            if(left[i] <= right[j]){
                arr[k++] = left[i++];
            }else{
                arr[k++] = right[j++];
            }
        }

        while(i < leftSize) arr[k++] = left[i++];

        while(j < right) arr[k++] = right[j++];
    }



        
    // Merge two sorted halves
    void merge1(int arr[], int left, int mid, int right) {
        int n1 = mid - left + 1;  // Size of left subarray
        int n2 = right - mid;      // Size of right subarray

        // Create temporary arrays
        int L[n1], R[n2];

        // Copy data to temp arrays
        for (int i = 0; i < n1; i++) L[i] = arr[left + i];
        for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

        int i = 0, j = 0, k = left;

        // Merge the temp arrays back into arr[]
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        // Copy remaining elements (if any)
        while (i < n1) {
            arr[k] = L[i];
            i++; k++;
        }
        while (j < n2) {
            arr[k] = R[j];
            j++; k++;
        }
    }

    // Merge Sort function
    void mergeSort(int arr[], int left, int right) {
        if (left >= right) return; // Base case: single element

        int mid = left + (right - left) / 2; // Find the middle point

        // Recursively sort left and right halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
};