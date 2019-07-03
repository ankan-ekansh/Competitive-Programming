#include<bits/stdc++.h>
using namespace std;
int k;
struct cq{
    int rear,front;
    int size;
    int *arr;
    int l=1;
    int lmax=1;
    int i,j;
    cq(int s){
        front = rear = -1;
        size = s;
        arr = new int[s];
    }
    void add(int value);
    void shift();
    int len();
    void displayQueue();
};
void cq::add(int value)
{
    if ((front == 0 && rear == size-1) ||
            (rear == (front-1)%(size-1)))
    {
        printf("\nQueue is Full");
        return;
    }

    else if (front == -1)
    {
        front = rear = 0;
        arr[rear] = value;
    }

    else if (rear == size-1 && front != 0)
    {
        rear = 0;
        arr[rear] = value;
    }

    else
    {
        rear++;
        arr[rear] = value;
    }
}
void cq::shift()
{
    if (front == 0)
    {
        front = size-1;
        rear--;
    }
    else if(rear == 0){
        rear = size-1;
        front--;
    }
    else{
        front--;
        rear--;
    }
}
int cq::len()
{
    l=1;
    lmax=1;
    for(i=front,j=i%size;(i-rear)<=size;i++){
        if(arr[j]==1){
            if(arr[j]==1 && arr[(j+1)%size]==1){
            l++;
        }
        else if(l>lmax){
            lmax=l;
            l=1;
        }
        }

    }
    if(lmax>=k){
        lmax=k;
    }
    return lmax;
}
void cq::displayQueue()
{
    cout<<"\n";
    for(i=front,j=i%size;(i-rear)<=size;i++){
        printf("%d ", arr[j]);
    }
    cout<<"\n";
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif


    int n,q;
    cin>>n;
    cin>>q;
    cin>>k;
    cq qu(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        qu.add(x);
    }
    char query[300050];
    cin.ignore();
    gets(query);
    for(int i=0;i<q;i++){
        if(query[i]=='!'){
            qu.shift();
            qu.displayQueue();
        }
        if(query[i]=='?'){
            int lq=qu.len();
            cout<<lq<<"\n";
        }
    }



    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

