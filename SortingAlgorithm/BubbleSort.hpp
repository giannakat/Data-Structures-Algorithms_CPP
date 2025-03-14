#include"Sortable.hpp"

class BubbleSort:public Sortable{
    public:
    
    //compare adjacent element are in order if not switch
    //bubble up or bubble down 
    //the last element will be checked already
    void sort(int arr[], int size){
        // for(int i = 0;  i < size-1; i++){
        //     for(int j = 0; j < size-i-1; j++){
        //     if(arr[j] > arr[j+1]){
        //         int temp = arr[j];
        //         arr[j] = arr[j+1];
        //         arr[j+1] = temp;
        //     }
        // }
        // }
        sort2(arr, size);
    }   

    // 5 4 3 2 1        s=5
    void sort2(int arr[], int size){
        for(int i = size-1; i>=0; i--){
            for(int j = size-1; j > 0; j--){
                if(arr[j] < arr[j-1]){
                    int temp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = temp;
                }
            }
        }
    }
};