#include<iostream>
#include<cstdlib>
using namespace std;
int partition(int [], int, int);
void quickSort(int [], int, int);
void printArray(int [], int);
void swap(int&, int&);
int main(){
    int a[5] = {5, 4, 3, 2, 1};
    int n = sizeof(a)/sizeof(a[0]);
    quickSort(a, 0, n-1);
    printArray(a, n);
    return 0;
}
void swap(int &x, int &y){
    int tmp = x;
    x = y;
    y = tmp;
}
void printArray(int a[], int n){
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}
int partition(int a[], int l, int r){
    int rndmIndex = (rand() % (r - l + 1) + l);
    swap(a[rndmIndex], a[r]);
    int pivot = a[r];
    int partitionIndex = l;
    for(int i=l;i<r;i++){
        if(a[i] <= pivot){
            swap(a[i], a[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(a[partitionIndex], a[r]);
    return partitionIndex;
}
void quickSort(int a[], int l, int r){
    if(l < r){
        int partitionIndex = partition(a, l, r);
        quickSort(a, l, partitionIndex-1);
        quickSort(a, partitionIndex+1, r);
    }
}