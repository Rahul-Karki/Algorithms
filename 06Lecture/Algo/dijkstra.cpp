#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void dijkstra(int source,vector<int>& visited,vector<int>& dist,int cost,vector<vector<int>>& adj){
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>minHeap;

    for(int i = 0; i < visited.size(); i++){
        if(adj[source][i] == 0 || adj[source][i] == -1){
            continue;
        }
        minHeap.push({adj[source][i],i});
    }

    while(!minHeap.empty()){
        pair<int,int> minVertex = minHeap.top();
        minHeap.pop();

        if(dist[minVertex.second] > cost + minVertex.first){
            dist[minVertex.second] = cost + minVertex.first;
            visited[minVertex.second] = 1;
            
            for(int i = 0; i < visited.size(); i++){
                if(adj[minVertex.second][i] == 0 || adj[minVertex.second][i] == -1 || visited[i]){
                    continue;
                }
                minHeap.push({dist[minVertex.second] + adj[minVertex.second][i],i});
            }

        }   
        
    }
}

int main(){
    int V;
    cout<<"enter the no of vertices ";
    cin>>V;

    vector<vector<int>>adj(V,vector<int>(V,-1));
    
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(i == j){
                adj[i][j] = 0;
            } 
            else{
                int cost;
                cout<< "vertex " << i + 1 << " to " << j + 1 << " Enter the cost of this edge ";
                cin>>cost;
                adj[i][j] = cost;
            }
        }
    }

    int source;
    cout<<"Enter the source vertex "<<endl;
    cin>>source;

    vector<int>visited(V,0);
    vector<int>dist(V,10000);
    int cost = 0;
    dist[source] = 0;

    dijkstra(source,visited,dist,cost,adj);

    for(int i = 0; i < V; i++){
        cout<<dist[i]<<" ";
    }

    return 0;
}