#include "Sortable.hpp"

class QuickSort:public Sortable{

    public:

    void sort(int arr[], int start, int end){
        if(end <= start) return;

        int pivot = partition(arr, start, end);
        sort(arr, start, pivot-1);
        sort(arr, pivot+1, end);

    }

    int partition(int arr[], int start, int end){
        int pivot = array[end];
        int i = start - 1;

        for(int j = start; j <= end - 1; j++){
            if(arr[j] < pivot){
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        i++;

        int temp = arr[i];
        arr[i] = arr[end];
        arr[end] = temp;

        return i;
    }
};