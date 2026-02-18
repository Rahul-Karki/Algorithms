#include<iostream>
#include<vector>

using namespace std;

void partition(vector<int>& arr,int low,int high){
    if(low > high){
        return;
    }
    int smaller = low;
    int pivot = arr[low];


    for(int i=low+1; i<high; i++){
        if(pivot >= arr[i]){
            smaller++;
        }
    }
    swap(arr[low],arr[smaller]);
    int i = low;
    int j = high - 1;

    while(i < smaller && j > smaller){
        if(arr[i] <= pivot){
            i++;
        }
        if(arr[j] >= pivot){
            j++;
        }
        else if(arr[i] > pivot && arr[j] < pivot){
            swap(arr[i],arr[j]);
            i++;
            j++;
        }
    }

    partition(arr,low,smaller-1);
    partition(arr,smaller+1,high);

}

int main(){
    vector<int> arr(5,0);
    int num;

    for(int i=0; i<5; i++){
        cin>>num;
        arr[i] = num;
    }

    partition(arr,0,5);

    for(int i=0; i<5; i++){
        cout<<arr[i];
    }

    return 0;
}