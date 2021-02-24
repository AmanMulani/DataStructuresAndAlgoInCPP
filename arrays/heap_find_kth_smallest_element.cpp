#include<iostream>
using namespace std;

class MaxHeap{
    public:
        int* harr;
        int capacity;
        int heap_size;
    public:
        MaxHeap(int a[], int size);
        void maxHeapify(int i);
        int parent(int i) {
            return (i-1)/2;
        }
        int left(int i) {
            return (i*2+1);
        }
        int right(int i) {
            return (i*2+2);
        }

        int extractMax();
        int getMax(){
            return harr[0];
        }

        void replaceMax(int x) {
            harr[0] = x;
            maxHeapify(0);
        }
};




