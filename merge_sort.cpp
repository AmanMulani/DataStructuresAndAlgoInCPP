#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r) {
    int lenLeft = m-l+1;
    int lenRight = r-m;
    int left[lenLeft];
    int right[lenRight];
    for(int i = l, j=0; i<=m; i++, j++) {
        left[j] = arr[i];
    }
    for(int i = m+1, j=0; i<=r; i++, j++) {
        right[j] = arr[i];
    }
    int curr = l;
    int i = 0, j = 0;
    while(i<lenLeft && j<lenRight) {
        if(left[i]>right[j]) {
            arr[curr++] = right[j++];
        } else {
            arr[curr++] = left[i++];
        }
    }
    while(i<lenLeft) {
        arr[curr++] = left[i++];
    }
    while(j<lenRight) {
        arr[curr++] = right[j++];
    }
}

void mergeSort(int arr[], int l, int r) {
    if(l>=r) {
        return;
    }
    int m = (l+r)/2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    merge(arr, l, m, r);
}

int main() {
    int arr[] = {468, 335, 1, 170, 225, 479, 359, 463, 465, 206, 146, 282, 328, 462, 492, 496, 443, 328, 437, 392, 105, 403, 154, 293, 383, 422, 217, 219, 396, 448, 227, 272, 39, 370, 413, 168, 300, 36, 395, 204, 312, 323};
    int len = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, 0, len-1);
    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    return 0;
}