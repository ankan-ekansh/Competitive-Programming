#include<iostream>
using namespace std;
// max heap
void insert(int h[], int idx){
    int i = idx;
    int temp = h[i];
    while(i > 1 && temp > h[i/2]){  // i = 1 is the root and if value tmp is more than its parent then loop will run
        h[i] = h[i/2];  // replace value at i by its parent at i/2
        i = i / 2;
    }
    h[i] = temp;    // i is now the location where it is more than all its children and less than all its parents
}
int deleteHeap(int h[], int idx){
    int i = 1;
    int j = 2*i;
    int del = h[1];
    int tmp = h[idx];
    h[1] = h[idx];
    h[idx] = del;
    while(j < idx-1){
        if(h[j] < h[j+1]){
            j++;
        }
        if(h[i] <  h[j]){
            swap(h[i], h[j]);
            i = j;
            j = 2*j;
        }
        else{
            break;
        }
    }
    return del;
}
int main(){
    int h[] = {0, 10, 20, 30, 25, 5, 40, 35};
    // initially only h[1] is in the heap
    for(int i=2;i<=7;i++){
        insert(h, i);
    }
    // cout << deleteHeap(h, 7) << "\n";
    for(int i=7;i>1;i--){
        deleteHeap(h,i);
    }
    for(int i=1;i<=7;i++){
        cout << h[i] << " ";
    }
    return 0;
}