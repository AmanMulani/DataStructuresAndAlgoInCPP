#include<iostream>
#include<cstdlib>
using namespace std;

struct minMaxPair{
    int min;
    int max;
};

minMaxPair minMaxPairCal(int arr[], int low, int high) {
    minMaxPair minMax;
    minMaxPair leftMinMax;
    minMaxPair rightMinMax;
    if(low == high) {
        minMax.min = arr[low];
        minMax.max = arr[low];
        return minMax;
    } else if(high == low+1) {
        if(arr[high] > arr[low]) {
            minMax.min = arr[low];
            minMax.max = arr[high];
        } else {
            minMax.min = arr[high];
            minMax.max = arr[low];
        }
        return minMax;
    } else {
        int mid = (low + high) / 2;
        leftMinMax = minMaxPairCal(arr, low, mid);
        rightMinMax = minMaxPairCal(arr, mid+1, high);
        if(leftMinMax.max > rightMinMax.max) {
            minMax.max = leftMinMax.max;
        } else{
            minMax.max = rightMinMax.max;
        }
        if(leftMinMax.min < rightMinMax.min) {
            minMax.min = leftMinMax.min;
        } else{
            minMax.min = rightMinMax.min;
        }
        return minMax;
    }
}

int main() {
    cout<<"Enter the number of elements\n";
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array\n";
    for(int i {0}; i<n; i++) {
        cin>>arr[i];
    }
    minMaxPair minMax = minMaxPairCal(arr, 0, n-1);
    cout<<"Max: "<<minMax.max<<endl;
    cout<<"Min: "<<minMax.min<<endl;
}