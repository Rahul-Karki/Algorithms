#include<iostream>
using namespace std;

void generate(string str, int n){
    if(str.length() == n){
        cout<<str<<endl;
        return;
    }
    str.push_back('0');
    generate(str,n);
    str.pop_back();
    str.push_back('1');
    generate(str,n);
}

int main(){
    int n;
    cout<<"Enter the length of string ";
    cin>>n;
    string str = "";
    generate(str,n);
    return 0;
}