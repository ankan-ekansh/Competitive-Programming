#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
class minHeap{
    int *a;
    int heapSize;
    int maxSize;

    public:
    minHeap(int a[], int size){
        this->a = a;
        this->maxSize = size;
        this->heapSize = 0;
    }
    int parent(int i){
        return i/2;
    }
    int left(int i){
        return 2*i;
    }
    int right(int i){
        return 2*i + 1;
    }
    void insert(int x){
        int i = heapSize;
        this->a[i] = x;
        while(i >= 0 && this->a[i] < this->a[parent(i)]){
            swap(this->a[i], this->a[parent(i)]);
            i = parent(i);
        }
        heapSize++;
    }
    void deleteMin(){
        if(heapSize == 0){
            cout << "Heap Empty\n";
            return;
        }
        swap(a[0], a[heapSize-1]);
        heapSize--;
        int cur = 0;
        while(cur < heapSize){
            // cout << ".\n";
            int l = left(cur);
            int r = right(cur);
            if(l < heapSize && r < heapSize){
                if(a[l] < a[r]){
                    if(a[l] < a[cur]){
                        swap(a[cur], a[l]);
                        cur = l;
                    }
                    else{
                        break;
                    }
                }
                else{
                    if(a[r] < a[cur]){
                        swap(a[cur], a[r]);
                        cur = r;
                    }
                    else{
                        break;
                    }
                }
            }
            else if(l < heapSize){
                if(a[l] < a[cur]){
                    swap(a[l], a[cur]);
                    cur = l;
                }
                else{
                    break;
                }
            }
            else if(r < heapSize){
                if(a[r] < a[cur]){
                    swap(a[r], a[cur]);
                    cur = r;
                }
                else{
                    break;
                }
            }
            else{
                break;
            }
        }
    }
    void print(){
        for(int i=0;i<heapSize;i++){
            cout << this->a[i] << " ";
        }
        cout << "\n";
    }
    int getMin(){
        if(heapSize == 0){
            return INT_MAX;
        }
        return a[0];
    }
    int size(){
        return heapSize;
    }
};
class maxHeap{
    int *a;
    int heapSize;
    int maxSize;

    public:
    maxHeap(int a[], int size){
        this->a = a;
        this->maxSize = size;
        this->heapSize = 0;
    }
    int parent(int i){
        return i/2;
    }
    int left(int i){
        return 2*i;
    }
    int right(int i){
        return 2*i + 1;
    }
    void insert(int x){
        int i = heapSize;
        this->a[i] = x;
        while(i >= 0 && this->a[i] > this->a[parent(i)]){
            swap(this->a[i], this->a[parent(i)]);
            i = parent(i);
        }
        heapSize++;
    }
    void deleteMax(){
        if(heapSize == 0){
            cout << "Heap Empty\n";
            return;
        }
        swap(a[0], a[heapSize-1]);
        heapSize--;
        int cur = 0;
        while(cur < heapSize){
            // cout << ".\n";
            int l = left(cur);
            int r = right(cur);
            if(l < heapSize && r < heapSize){
                if(a[l] > a[r]){
                    if(a[l] > a[cur]){
                        swap(a[cur], a[l]);
                        cur = l;
                    }
                    else{
                        break;
                    }
                }
                else{
                    if(a[r] > a[cur]){
                        swap(a[cur], a[r]);
                        cur = r;
                    }
                    else{
                        break;
                    }
                }
            }
            else if(l < heapSize){
                if(a[l] > a[cur]){
                    swap(a[l], a[cur]);
                    cur = l;
                }
                else{
                    break;
                }
            }
            else if(r < heapSize){
                if(a[r] > a[cur]){
                    swap(a[r], a[cur]);
                    cur = r;
                }
                else{
                    break;
                }
            }
            else{
                break;
            }
        }
    }
    void print(){
        for(int i=0;i<heapSize;i++){
            cout << this->a[i] << " ";
        }
        cout << "\n";
    }
    int getMax(){
        if(heapSize == 0){
            return INT_MIN;
        }
        return a[0];
    }
    int size(){
        return heapSize;
    }
};
int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    int *a = new int[n];
    // cin >> arr[0];
    int x;
    // cin >> x;
    minHeap minh = minHeap(arr, n);
    maxHeap maxh = maxHeap(a, n);
    // maxh.insert(x);
    // cout << x << "\n";
    for(int i=0;i<n;i++){
        // cin >> arr[i];
        // int x;
        cin >> x;
        if(maxh.size()){
            if(x < maxh.getMax()){
                maxh.insert(x);
            }
            else{
                minh.insert(x);
            }
        }
        else if(minh.size()){
            if(x > minh.getMin()){
                minh.insert(x);
            }
            else{
                maxh.insert(x);
            }
        }
        else{
            maxh.insert(x);
        }
        if(abs(maxh.size() - minh.size()) > 1){
            if(maxh.size() > minh.size()){
                int tmp = maxh.getMax();
                maxh.deleteMax();
                minh.insert(tmp);
            }
            else{
                int tmp = minh.getMin();
                minh.deleteMin();
                maxh.insert(tmp);
            }
        }
        // cout << minh.size() << " " << maxh.size() << "\n";
        // maxh.print();
        // minh.print();
        if(minh.size() == maxh.size()){
            // cout << minh.getMin() << " " << maxh.getMax() << "\n";
            cout << (minh.getMin() + maxh.getMax()) / 2 << "\n";
        }
        else{
            if(minh.size() > maxh.size()){
                cout << minh.getMin() << "\n";
            }
            else{
                cout << maxh.getMax() << "\n";
            }
        }
    }
    delete[] arr;
    delete[] a;
    return 0;
}