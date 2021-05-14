#include<iostream>
using namespace std;
void merge(int, int, int, int[]);
void mergeSort(int, int, int[]);
void printArray(int, int[]);
int main(){
    int a[5] = {5, 4, 3, 2, 1};
    int n = sizeof(a)/sizeof(a[0]);
    mergeSort(0, n-1, a);
    printArray(n, a);
    return 0;
}
void printArray(int n, int a[]){
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}
void merge(int l, int m, int r, int a[]){
    int ls = m-l+1;
    int rs = r-m;
    // int left[ls], right[rs];
    int *left = new int[ls];
    int *right = new int[rs];
    for(int i=0;i<ls;i++){
        left[i] = a[l+i];
    }
    for(int i=0;i<rs;i++){
        right[i] = a[m+1+i];
    }
    int i=0, j=0, k=l;
    while(i < ls && j < rs){
        if(left[i] <= right[j]){
            a[k] = left[i];
            i++;
        }
        else{
            a[k] = right[j];
            j++;
        }
        k++;
    }
    while(i < ls){
        a[k++] = left[i++];
    }
    while(j < rs){
        a[k++] = right[j++];
    }
    delete[] left, right;
}
void mergeSort(int l, int r, int a[]){
    if(l < r){
        int m = l + (r-l)/2;
        mergeSort(l, m, a);
        mergeSort(m+1, r, a);
        merge(l, m, r, a);
    }
}