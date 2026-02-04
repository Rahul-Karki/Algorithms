#include<iostream>

using namespace std;

int findNumber(int arr[],int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] == arr[j]){
                return arr[i];
            }
        }
    }
    return -1;
}

void fillNumber(int arr[], int n){
    for(int i=0; i<n; i++){
        arr[i] = rand()%1000;
    }
}

int main(){
    int arr[10000];
    for(int i=1000; i<10000; i+=1000){
        fillNumber(arr,i);
        cout<<findNumber(arr,i)<<endl;
    }
    



    return 0;
}