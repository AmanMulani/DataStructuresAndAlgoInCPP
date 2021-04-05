#include<bits/stdc++.h>
using namespace std;

int merge(int arr[], int l, int m, int r) {

    int left[m-l+1];
    int right[r-m];
    int t_index = l;
    int count = 0;
    for(int i = 0; i<m-l+1; i++) {
        left[i] = arr[t_index];
        t_index++; 
    }
    t_index = m+1;
    for(int i = 0; i<r-m; i++) {
        right[i] = arr[t_index];
        t_index++;
    }
    
    int i = 0;
    int j = 0;
    int curr = l;
    while(i<m-l+1 && j<r-m) {
        if(left[i]>right[j]) {
            arr[curr] = right[j];
            count += (m-l-i+1);
            j++;
        } else {
            arr[curr] = left[i];
            i++;
        }
        curr++;
    }

    while(i<m-l+1) {
        arr[curr] = left[i];
        i++;
        curr++;
    }
    while(j<r-m) {
        arr[curr] = right[j];
        j++;
        curr++;
    }
    return count;
}


int mergeSort(int arr[], int l, int r) {
    int count = 0;
    if(l>=r) {
        return 0;
    }
    int m = (l+r)/2;
    count += mergeSort(arr, l, m);
    count += mergeSort(arr,m+1, r);
    count += merge(arr, l, m, r);
    return count;
}

int main() {
    int arr[] = {468, 335, 1, 170, 225, 479, 359, 463, 465, 206, 146, 282, 328, 462, 492, 496, 443, 328, 437, 392, 105, 403, 154, 293, 383, 422, 217, 219, 396, 448, 227, 272, 39, 370, 413, 168, 300, 36, 395, 204, 312, 323};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout<<mergeSort(arr, 0, len-1)<<"\n";
    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    return 0;
}