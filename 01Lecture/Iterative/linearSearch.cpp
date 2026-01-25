#include<iostream>
#include<chrono>
#include<bits/stdc++.h>
using namespace std;
using namespace chrono;

int linearSearch(int arr[],int n){
    int count = 0;
    for(int i=0; i<100; i++){
        for(int i=0; i<n; i++){
            arr[i] = rand();
        }
        int target = rand();
        auto x = system_clock::now();
        for(int i=0; i<n; i++){
            if(arr[i]==target){
                break;
            }
        }
        auto y = system_clock::now();
        int diff = duration_cast<nanoseconds>(y - x).count();

        count += diff;
    }
    return count/100;
}

int main(){
    int arr[10000];
    for(int i=1000; i<10000; i+=1000){
        int ans = linearSearch(arr,i);
        cout<<"For size "<<i<<" the time taken was "<<ans<<"ms"<<endl;
    }
    return 0;
}