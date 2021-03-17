//Given an array of intervals where intervals[i] = [starti, endi],
//merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

//Time Complexity = O(nlogn)
//Space Complexity = O(n)


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool sortAccordingToFirstElem(vector<int> v1, vector<int> v2) {
    return v1[0]<v2[0];
}

vector<vector<int>> mergeInterals(vector<vector<int>> &v) {
    sort(v.begin(), v.end(), sortAccordingToFirstElem);
    vector<vector<int>> mergedVector;
    for(auto i : v) {
        if(mergedVector.empty() || mergedVector.back()[1] < i[0]) {
            mergedVector.push_back(i);
        } else if (mergedVector.back()[1] <= i[1]) {
            mergedVector.back()[1] = i[1];
        }
    }
    return mergedVector;
}

int main() {

    vector<vector<int>> v = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> mergedVector = mergeInterals(v);
    cout<<"[";
    for(auto i : mergedVector) {
        cout<<"["<<i[0]<<","<<i[1]<<"]"<<", ";
    }
    cout<<"]\n";
    return 0;
}