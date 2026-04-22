#include<iostream>
#include<vector>

using namespace std;

void shortestPath(vector<vector<int>>& graph){
    int n = graph.size();

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(graph[i][k] != -1 && graph[k][j] != -1){
                    if(graph[i][j] == -1 || graph[i][j] > graph[i][k] + graph[k][j]){
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }
    }
}

int main(){
    vector<vector<int>> graph = {
        {0, 3, -1, 7},
        {8, 0, 2, -1},
        {5, -1, 0, 1},
        {2, -1, -1, 0}   
    };

    shortestPath(graph);
    for(int i=0; i<graph.size(); i++){
        for(int j=0; j<graph[i].size(); j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
