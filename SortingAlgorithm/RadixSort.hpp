#include "Sortable.hpp"

class RadixSort:public Sortable{
    private:
    int getMax(int arr[i], int size){
        int max = arr[0];

        for(int i = 0; i < size; i++){
            if(max < arr[i]){
                max = arr[i];
            }
        }

        return max;
    }

    public: 
    void sort(int arr[], int size){
        int maxValue = getMax(arr, size);

        for(int place = 1; maxValue/place > 0; place*=10){
            counting_sort(arr[], size, place);
        }
    }

    void counting_sort(int arr[], int size, int place){
        int count[10] = {0};
        int output[size];

        int max = getMax(arr, size);

        for(int i = 0; i < size; i++){
            count[(arr[i]/place)%10]++;
        }

        for(int i = 1; i < 10; i++ ){
            count[i]+=count[i-1];
        }

        //it is important to start at size-1
        for(int i = size-1; i >= 0; i--){
            int digit = (arr[i]/place) % 10;
            output[count[digit]] = arr[i];
            count[digit]--; 
        }

        for(int i = 0; i < n; i++){
            arr[i] = output[i];
        }
    } 
};