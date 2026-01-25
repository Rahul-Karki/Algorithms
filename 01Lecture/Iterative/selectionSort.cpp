#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i=0; i<n; i++){
        int minimum = i;
        for(int j=i+1; j<n; j++){
            if(arr[minimum] > arr[j]){
                minimum = j;
            }
        }

        swap(arr[i],arr[minimum]);
    }
}

void fill(int arr[], int n){
    for(int i=0; i<n; i++){
        arr[i] = rand();
    }
}

int main(){
    int n = 100;
    int arr[n];
    fill(arr,n);
    selectionSort(arr,n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}