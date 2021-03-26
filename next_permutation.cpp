#include<bits/stdc++.h>
using namespace std;

int comp(int a, int b) {
    return a>b;
}

void calculateNextPermutation(vector<int> &nums) {
    int size = nums.size();
    int flag = is_sorted(nums.begin(), nums.end(), comp);
    if(flag == 1) {
        sort(nums.begin(), nums.end());
    } else {
        int curr; 
        for(int i = size-1; i>=1; i--) {
            if(nums[i] <= nums[i-1]) {
                continue;
            } else {
                curr = i;
                break;
            }
        }
        sort(nums.begin()+curr, nums.end());
        int just_max = curr-1;
        for(int i = curr; i<size; i++) {
            if(nums[i]>nums[just_max]) {
                just_max = i;
                break;
            }
        }
        int temp = nums[just_max];
        nums[just_max] = nums[curr-1];
        nums[curr-1] = temp;
        sort(nums.begin()+curr, nums.end());
    }
}


int main() {
    vector<int> nums = {2,2,7,5,4,3,2,2,1};
    calculateNextPermutation(nums);
    for(auto i: nums) {
        cout<<i<<" ";
    }
    cout<<"\n";
    return 0;
}