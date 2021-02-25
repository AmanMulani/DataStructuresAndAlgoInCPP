/*
Find k’th smallest element in time complexity better than O(N Log N). 
A simple optimization is to create a Min Heap of the given n elements and call extractMin() k times.
*/

#include<iostream>
#include<climits>
using namespace std;

void swap(int* x, int *y);

class MinHeap{
    public:
        int* harr;
        int capacity;
        int heap_size;
    public:
        MinHeap(int a[], int size);
        void minHeapify(int i);
        int parent(int i) {
            return (i-1)/2;
        }
        int leftChild(int i) {
            return (2 * i + 1);
        }
        int rightChild(int i) {
            return (2 * i + 2);
        }

        int extractMin();
        int getMin(){
            return harr[0];
        }

        // void replaceMin(int x) {
        //     harr[0] = x;
        //     minHeapify(0);
        // }
};

MinHeap::MinHeap(int a[], int size) {
    heap_size = size;
    harr = a;
    int i = (heap_size - 1) / 2;
    while(i >= 0) {
        minHeapify(i);
        i--;
    }
}

int MinHeap::extractMin() {
    
    if(heap_size == 0) {
        return INT_MAX;
    }
    int root = harr[0];
    if(heap_size > 1) {
        harr[0] = harr[heap_size-1];
        minHeapify(0);
    }
    heap_size--;
    return root;
}

void MinHeap::minHeapify(int i) {
    int left = leftChild(i);
    int right = rightChild(i);
    int smallest = i;
    if(left < heap_size && harr[left] < harr[i]) {
        smallest = left;
    }
    if(right < heap_size && harr[right] < harr[smallest]) {
        smallest = right;
    }
    if(smallest != i) {
        swap(&harr[i], &harr[smallest]);
        minHeapify(smallest);
    }
}

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int kthSmallest(int arr[], int n, int k) {
    MinHeap mh(arr, n);
    for(int i = 0; i < k-1; i++) {
        mh.extractMin();
    }
    return mh.getMin();
}

int main() {
    int arr[] = {12, 3, 5, 7, 19};
    int n = sizeof(arr) / sizeof(arr[0]), k = 2;
    int ksmall =  kthSmallest(arr, n, k);
    cout << "K'th smallest element is "<<ksmall <<endl;
    return 0;
}


