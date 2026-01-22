#include <iostream>
using namespace std;

void permute(string &s, int index) {
    if (index == s.length()) {
        cout<<s<<endl;
        return;
    }

    for (int i = index; i < s.length(); i++) {
        swap(s[index], s[i]);     
        permute(s, index + 1);    
        swap(s[index], s[i]);     
    }
}

int main() {
    string s;
    cout<<"Enter the string ";
    cin>>s; 
    permute(s, 0);
}
