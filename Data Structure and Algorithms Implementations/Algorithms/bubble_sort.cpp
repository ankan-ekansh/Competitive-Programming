#include<iostream>
using namespace std;
void bubbleSort(int, int[]);
int main(){
    int a[5] = {5, 4, 3, 2, 1};
    int n = sizeof(a)/sizeof(int);
    bubbleSort(n, a);
    for(int x : a){
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}
void bubbleSort(int n, int a[]){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j] > a[j+1]){
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}