//MaxHeap to find the kth largest number.
//Total Time Complexity: O(nlogn)

#include<iostream>
#include<climits>
using namespace std;

void swap(int* x, int* y);

class MaxHeap{
    public:
        int* harr;
        int heap_size;
        int capacity;
    
    public:
        MaxHeap(int arr[], int size);
        int extractMax();
        void maxHeapify(int  i);

        int getMax(){
            return harr[0];
        }
        int parent(int i){
            return (i-1)/2;
        }
        int left(int i){
            return (2*i + 1);
        }
        int right(int i){
            return(2*i + 2);
        }
};

MaxHeap::MaxHeap(int arr[], int size){
    harr = arr;
    heap_size = size;
    int i = (heap_size - 1)/2;
    while(i>=0){
        maxHeapify(i);
        i--;
    }
}

int MaxHeap::extractMax() {
    if(heap_size == 0) {
        return INT_MAX; 
    }
    int root = harr[0];
    if(heap_size>1){
        harr[0] = harr[heap_size - 1];
        maxHeapify(0);
    }
    heap_size--;
    return root;
}

void MaxHeap::maxHeapify(int i) {
    int largest = i;
    int l = left(i);
    int r = right(i);

    if(l<heap_size && harr[l] > harr[i]) {
        largest = l;
    }
    if(r<heap_size && harr[r] > harr[largest]) {
        largest = r;
    }
    if(largest != i) {
        swap(&harr[largest], &harr[i]);
        maxHeapify(largest);
    }
}

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int kthMaxElement(int arr[], int size, int k) {
    MaxHeap maxHeap(arr, size);
    for(int i = 0; i<k-1; i++) {
        maxHeap.extractMax();
    }
    return maxHeap.getMax();
}

int main() {
    int n;
    cout<<"Enter array size\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array\n";
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the kth largest number you wish to find.\n";
    cin>>k;
    // int arr[] = {32, 45, 989, -32, 654, 231, 47, 62};
    // cout<<kthMaxElement(arr, 8, 7);
    cout<<"Output: "<<kthMaxElement(arr, n, k);
    return 0;
}