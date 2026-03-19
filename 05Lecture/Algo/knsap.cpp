#include<iostream>
#include<vector>
#include<functional>
#include<utility>
#include<algorithm>
#include<queue>
using namespace std;

bool compare(pair<double,int>p1,pair<double,int>p2){
    return p1.first > p2.first;
}

int main(){
    // Profit , Weight
    int n;
    cin>>n;
    vector<pair<int,int>>profitWeight;
    // Weight , Profit
    vector<pair<int,int>>weightProfit;
    // Profit/Weight , Weight
    vector<pair<double,int>>perUnit;

    int capacity;
    cout<<"Enter the capacity of the truck ";
    cin>>capacity;

    for(int i=0; i<n; i++){
        int profit = rand()%10 + 1;
        int weight = rand()%10 + 1;

        profitWeight.push_back({profit , weight});
    
        weightProfit.push_back({profitWeight[i].second,profitWeight[i].first});

        double x = (double)(profitWeight[i].first / profitWeight[i].second);

        perUnit.push_back({x,profitWeight[i].second});

    }
    
    sort(weightProfit.begin(),weightProfit.end());    
    sort(profitWeight.begin(),profitWeight.end(),compare);
    sort(perUnit.begin(),perUnit.end(),compare);

    for(int i=0; i<n; i++){
        cout<<profitWeight[i].first<<"and"<<profitWeight[i].second<<endl;
    }

    float profit = 0;

    int spaceLeft = capacity;
    for(int i=0 ; i<n; i++){
        if(spaceLeft - weightProfit[i].first >= 0){
            spaceLeft = spaceLeft - weightProfit[i].first;
            profit += weightProfit[i].second;
        }   
        else{
            float x = ((float)(weightProfit[i].second / weightProfit[i].first))* spaceLeft;
            spaceLeft = 0;
            profit += x;
        }
    }

    cout<<profit<<endl;

    float profit2 = 0;
    spaceLeft = capacity;

    for(int i=0; i<n; i++){
        if(spaceLeft - profitWeight[i].second >= 0){
            spaceLeft = spaceLeft - profitWeight[i].second;
            profit2 += profitWeight[i].first;
        }
        else{
            float x = ((float)(profitWeight[i].first / profitWeight[i].second))* spaceLeft; 
            spaceLeft = 0;
            profit2 += x;
        }
    }

    cout<< profit2<<endl;

    double profit3 = 0;
    spaceLeft = capacity;

    for(int i=0; i<n; i++){
        cout<<perUnit[i].first<<"and"<<perUnit[i].second<<endl;
    }

    for(int i=0; i<n; i++){
        if(spaceLeft - perUnit[i].second >= 0){
            spaceLeft -= perUnit[i].second;
            profit3 += perUnit[i].first * perUnit[i].second;
        }
        else{
            double x = ((double)(perUnit[i].first))* spaceLeft; 
            spaceLeft = 0;
            profit3 += x;
        }
    } 

    cout<<profit3<<endl;
    
    return 0;
}