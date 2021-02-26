/*
Dutch national flag algorithm or Three Way Partitioning Algorithm
Time Complexity: O(n)
Space Complexity: O(1)

Sort an array of 0, 1, and 2.
*/

#include<iostream>
using namespace std;

void swap(int* x, int* y);

void sortArray(int arr[], int size) {
    int low = 0;
    int mid = 0;
    int high = size-1;

    //All the elements on the left side of the low will be 0's
    //All the elements on the right side of the high will be 1's
    //All the elements in-between mid and high will be 1's

    while(mid <= high){
        if(arr[mid] == 0) {
            //Increase the low and mid pointer.
            //Swap values at index low and mid of array.
            swap(&arr[low], &arr[mid]);
            mid++;
            low++;
        } else if(arr[mid] == 1) {
            //Increase the mid pointer.
            mid++;
        } else {
            //Decrease the high pointer.
            //Swap values at index high and mid of array 
            swap(&arr[mid], &arr[high]);
            high--;
        }
    }
}

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}


int main() {
    int n;
    cout<<"Enter the number of elements.\n";
    cin>>n;
    cout<<"Enter the elements of the array.\n";
    int arr[n];
    for(int i =0; i<n; i++) {
        cin>>arr[i];
    }
    // int arr[] = {0, 0, 1, 2, 0, 1, 2, 0, 1, 2, 2, 1, 0};
    sortArray(arr, n);
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return 0;
}