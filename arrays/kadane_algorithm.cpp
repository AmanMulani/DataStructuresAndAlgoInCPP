/*
Find the maximum sum of subarray in the given array.
Kadane's Algorithm
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include<iostream>
#include<climits>
using namespace std;

int getMaxSubArray(int arr[], int n) {

    int sum {0};
    int best {INT_MIN};

    for(int i = 0; i<n; i++) {
        sum = max(arr[i], sum + arr[i]);
        best = max(best, sum);
    }
    return best;
}

int main() {
    int arr[] = {1, 2, 3, -2, 5};
    cout<<getMaxSubArray(arr, 5)<<"\n";
    return 0;
}