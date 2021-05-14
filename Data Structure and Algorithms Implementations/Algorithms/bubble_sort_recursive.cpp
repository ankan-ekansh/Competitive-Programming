#include<iostream>
using namespace std;
void bubbleSortRec(int, int[]);
void printArray(int, int[]);
void swap(int*, int*);
void swap(int&, int&);
int main(){
    int a[5] = {5, 4, 3, 2, 1};
    int n = sizeof(a)/sizeof(a[0]);
    bubbleSortRec(n, a);
    printArray(n, a);
    return 0;
}
void swap(int *x, int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
void swap(int &x, int &y){
    int tmp = x;
    x = y;
    y = tmp;
}
void printArray(int n, int a[]){
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}
void bubbleSortRec(int n, int a[]){
    if(n == 1){
        return;
    }
    for(int i=0;i<n-1;i++){
        if(a[i] > a[i+1]){
            // int tmp = a[i];
            // a[i] = a[i+1];
            // a[i+1] = tmp;
            // swap(&a[i], &a[i+1]);
            swap(a[i], a[i+1]);
        }
    }
    bubbleSortRec(n-1, a);
}