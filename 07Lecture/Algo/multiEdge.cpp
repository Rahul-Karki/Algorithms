#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void makeStages(int a[][5],int V,int s,vector<vector<int>>& stages){
    vector<int>temp;
    stages.push_back({s});

    queue<int>q;
    q.push(s);

    while(!q.empty()){
        int size = q.size();

        while(size--){
            int front = q.front();
            q.pop();

            for(int i = 0; i < V; i++){
                if(a[front][i] != -1 && a[front][i] != 0){
                    temp.push_back(i);
                    q.push(i);
                }
            }
        }
        stages.push_back(temp);
        temp.clear();
    }
}   

void findMinCost(vector<vector<int>>& stages,int a[][5],int sink,int& minCost,int i){

    if(i < 0){
        return;
    }


    priority_queue<int , vector<int> , greater<int>>mq;

    for(int j = 0; j < stages[i].size(); j++){
        mq.push(a[stages[i][j]][sink]);
    }

    int p = mq.top();
    minCost += a[p][sink];
    mq.pop();

    findMinCost(stages,a,p,minCost,i-1);
}

int main(){
    int V = 5;
    int a[V][V]= {{0,4,5,6,-1},{-1,0,-1,-1,2},{-1,-1,0,-1,1},{-1,-1,-1,0,3},{-1,-1,-1,-1,0}};

    vector<vector<int>>stages;

    int source;
    cout<<"Enter the source to start from ";
    cin>>source;

    makeStages(a,V,source,stages);

    int minCost = 0;

    int sink;
    cout<<"Enter the destination node ";
    cin>>sink;

    int n = stages.size();

    findMinCost(stages,a,sink,minCost,n-1);
    
    cout<<"The min cost is "<<minCost;

    return 0;

}