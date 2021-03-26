#include<bits/stdc++.h>
using namespace std;
void merge(int arr1[], int arr2[], int n, int m) {
	    // code here
	   // int i = 0;
	   // int j = 0;
	   // while(i<n) {
	   //     if(arr1[i]>arr2[j]) {
	   //         int t = arr1[n-1];
	   //         int temp = arr1[i];
	   //         int k = i;
	   //         while(k<n-1) {
	   //             int temp_shift = arr1[k+1];
	   //             arr1[k+1] = temp;
	   //             temp = temp_shift;
	   //             k++;
	   //         }
	   //         arr1[i] = arr2[j];
	   //         arr2[j] = t;
	   //         sort(arr2, arr2+m);
	   //     }
	   //     i++;
	   // }
    int gap = ceil((m+n)/2);
    while(gap>=1) {
        int i = 0;
        int j = gap;
        cout<<"Gap: "<<j<<"\n";
        while(j<m+n) {
            cout<<"i="<<i<<" j="<<j<<"    ";
            for (int k = 0; k < n; k++) {
                cout << arr1[k] << " ";
            }
            cout<<"\t";
            for (int k = 0; k < m; k++) {
                cout << arr2[k] << " ";
            }
            cout<<"\n";
            if(j<n) {
                if(arr1[i]>arr1[j]) {
                    int temp = arr1[i];
                    arr1[i] = arr1[j];
                    arr1[j] = temp;
                }
            } else {
                if(i>=n) {
                    if(arr2[i%n]>arr2[j%m]) {
                    int temp = arr2[i%n];
                    arr2[i%n] = arr2[j%m];
                    arr2[j%m] = temp;
                    }  
                } else {
                    if(arr1[i]>arr2[j%m]) {
                    int temp = arr1[i];
                    arr1[i] = arr2[j%m];
                    arr2[j%m] = temp;
                    }
                }
                //if(arr1[i]>arr2[j%n]) {
                //    int temp = arr1[i];
                //    arr1[i] = arr2[j%n];
                //    arr2[j%n] = temp;
            //   }
            }
            j++;
            i++;
        }
    
        for (i = 0; i < n; i++) {
        cout << arr1[i] << " ";
        }
        cout<<"\t";
        for (i = 0; i < m; i++) {
        cout << arr2[i] << " ";
        }
        cout<<"\n";
        cout<<"\n";
        gap = gap/2;   
    }
}

int main() {
    int arr1[] = {7, 9, 9, 10, 11, 11, 13, 14, 17, 19};
    int arr2[] = {1, 1, 4, 5, 8, 11, 13, 16, 19, 19};
    merge(arr1, arr2, 10, 10);
    return 0;
}