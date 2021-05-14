#include<iostream>
#include<climits>
using namespace std;
class minHeap{
    int *a;
    int heapSize;
    int maxSize;
public:
    minHeap(int [], int);   // Constructor
    void minHeapify(int);   // Min-Heapify the subtree of this node
    int parent(int);        // Returns parent of the current node
    int left(int);          // Returns left child of current node
    int right(int);         // Returns right child of current node
    int extractMin();       // Extracts root(min) element
    int getMin();           // Returns the root(min) element
};
int minHeap::parent(int i){
    return i/2;
}
int minHeap::left(int i){
    return 2*i;
}
int minHeap::right(int i){
    return 2*i + 1;
}
minHeap::minHeap(int a[], int size){
    heapSize = size;
    this->a = a;
    // minHeap::a = a;  // Stores address of array
    int i = (heapSize - 1)/2;   // Ignore all leaf nodes
    while(i >= 0){
        minHeapify(i);      // Consider the subtree of i and make it into a heap
        i--;
    }
}
void minHeap::minHeapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l < heapSize && a[l] < a[i]){
        smallest = l;
    }
    if(r < heapSize && a[r] < a[smallest]){
        smallest = r;
    }
    if(smallest != i){
        swap(a[smallest], a[i]);
        minHeapify(smallest);       // Recur towards the subtree of the smaller one
    }
}
int minHeap::extractMin(){
    if(heapSize == 0){
        return INT_MAX;
    }
    int root = a[0];
    if(heapSize > 1){
        a[0] = a[heapSize-1];
        minHeapify(0);
    }
    heapSize--;
    return root;
}
int minHeap::getMin(){
    return a[0];
}
int kthSmallest(int arr[], int n, int k){
    minHeap mH(arr, n);
    for(int i=0;i<k-1;i++){
        mH.extractMin();
    }
    return mH.getMin();
}
int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    // for(int i=0;i<n;i++){
    //     cout << arr[i] << " ";
    // }
    // cout << "\n";
    cout << kthSmallest(arr, n, k) << "\n";
    delete[] arr;
    return 0;
}