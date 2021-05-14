#include<iostream>
using namespace std;
void heapify(int h[], int n){   // O(NlogN)
    int cnt = 0;
    for(int i=n-1;i>=0;i--){    // iterates over all nodes
        int j = 2*i+1;
        while(j < n-1){     // this explores the left and right child of i
            cnt++;
            if(h[j] < h[j+1]){
                j++;
            }
            if(h[i] < h[j]){
                swap(h[i], h[j]);
                i = j;
                j = 2*j;
            }
            else{
                break;
            }
        }
    }
    cout << cnt << "\n";
}
void heapify_optimized(int h[], int N){     // nearly O(N)
    int cnt = 0;
    int n = (N/2) - 1;      // ignoring the leaf nodes
    for(int i=n-1;i>=0;i--){
        int j = 2*i+1;
        while(j < N-1){     // this explores the left and right child of i
            cnt++;
            if(h[j] < h[j+1]){
                j++;
            }
            if(h[i] < h[j]){
                swap(h[i], h[j]);
                i = j;
                j = 2*j;
            }
            else{
                break;
            }
        }
    }
    cout << cnt << "\n";
}
int main(){
    int h[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int n = sizeof(h)/sizeof(h[0]);
    // heapify starts from right side of the array, from root to leaf
    // insert is done from the right, from leaf to root
    // delete is done from the left, from root to leaf
    heapify(h, n);
    for(int i=0;i<n;i++){
        cout << h[i] << " ";
    }
    cout << "\n";
    int heap[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    heapify_optimized(heap, n);    // we can ignore leaf nodes as they are heap in themselves
    for(int i=0;i<n;i++){
        cout << heap[i] << " ";
    }
    cout << "\n";
    return 0;
}