#include<iostream>
using namespace std;
void insertionSort(int, int[]);
void printArray(int, int[]);
int main(){
    int a[5] = {5, 4, 3, 2, 1};
    int n = sizeof(a)/sizeof(a[0]);
    insertionSort(n, a);
    printArray(n, a);
    return 0;
}
void printArray(int n, int a[]){
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}
void insertionSort(int n, int a[]){
    for(int i=0;i<n;i++){
        int hole = i;
        int val  = a[i];
        while(hole > 0 && val < a[hole-1]){     // 2 4 5 _3_ 1  -> 3 is value and 4 is hole position
            a[hole] = a[hole-1];                // shift everything right by one till desired place is reached
            hole--;                             // 2 _4_ 4 5 1  (a[hole-1] > val)
        }                                       // 2  3  4 5 1
        a[hole] = val;
    }
}