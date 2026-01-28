#include <iostream>
#include <vector>

using namespace std;

int findDup(const vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        if ((nums[i] ^ i) != 0) {
            return nums[i];
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {0, 1, 2, 3, 4, 4, 6};
    
    int duplicate = findDup(nums);
    
    if (duplicate != -1) {
        cout<<"The duplicate number is: "<<duplicate<<endl;
    } else {
        cout<<"No duplicate found based on index matching."<<endl;
    }
    
    return 0;
}