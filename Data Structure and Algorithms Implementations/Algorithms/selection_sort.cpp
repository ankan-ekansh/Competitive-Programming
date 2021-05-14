#include<iostream>
using namespace std;
void selectionSort(int, int[]);
// Another method for this function definition
// void selectionSort(int, int*)
// int a[] = int *a (both correspond to the base address)
int main(){
    int a[5] = {5, 4, 3, 2, 1};
    int n = sizeof(a)/sizeof(int);
    selectionSort(n, a);
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}
void selectionSort(int n, int a[]){
    for(int i=0;i<n;i++){
        int minPos = i;
        for(int j=i+1;j<n;j++){
            if(a[j] < a[minPos]){
                minPos = j;
            }
        }
        int tmp = a[i];
        a[i] = a[minPos];
        a[minPos] = tmp;
    }
}