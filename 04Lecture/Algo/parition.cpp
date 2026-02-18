#include<iostream>
#include<vector>
using namespace std;

int partiton(vector<int>& arr,int low,int high){
    if(low < high){
        int smaller = low;
        int pivot = arr[low];

        for(int i=low+1; i<high; i++){
            if(arr[i] <= pivot){
                smaller++;
            }
        }
    
        swap(arr[smaller],arr[low]);

        int i = low;
        int j = high - 1;

        while(i < smaller && j > smaller){
            if(arr[i]<=arr[smaller]){
                i++;
            }
            else if(arr[j]>= arr[smaller]){
                j--;
            }
            else{
                swap(arr[i],arr[j]);
                i++;
                j--;
            }
        }

        
        return smaller;

    }
    
    return -1;
}

int find(vector<int>& arr,int low,int high,int k){
    if(low == high){
        return arr[low];
    }

    if(low < high){
        int compare = partiton(arr,low,high);
        
        if(compare == k){
            return arr[k];
        }
        else if(compare < k){
            return find(arr,compare+1,high,k);
        }
        else{
            return find(arr,low,compare-1,k);
        }
    } 
    return -1;
}

int main(){
    vector<int>arr(5,0);
    int n;

    for(int i=0; i<5; i++){
        cin>>n;
        arr[i] = n;
    }
    int k;
    cout<<"enter value of k ";
    cin>>k;

    cout<<find(arr,0,5,k-1);

    return 0;
}