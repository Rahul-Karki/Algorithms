#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void fill(int arr[], int n){
    for(int i=0; i<n; i++){
        arr[i] = rand();
    }
}

void bubbleSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] > arr[j]){
                swap(arr[i],arr[j]);
            }
           
        }
    }
}

int main(){
    int n = 100;
    int arr[n];
    fill(arr,n);
    bubbleSort(arr,n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}