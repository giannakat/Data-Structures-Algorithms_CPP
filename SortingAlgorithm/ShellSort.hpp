#include "Sortable.hpp"

class ShellSort:public Sortable{

    public:

    void sort(int arr[], int size){
        for(int gap = n/2; gap > 0){
            for(int i = gap; i < n; i++){
                int temp = arr[i];
                int j;

                for(j = i; j >= gap && arr[j - gap] > temp; j -= gap){
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
    }
};