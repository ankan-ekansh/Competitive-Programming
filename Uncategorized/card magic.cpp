#include<bits/stdc++.h>
using namespace std;
long int a[100050];
long int b[100050];
struct Queue{
    long int rear, front;
    long int size;
    long int *arr;
    Queue(int s){
        front=rear=-1;
        size=s;
        arr=new long int[s];
    }
    void enQueue(long int value);
    void checkQueue();
};
void Queue::enQueue(long int value)
{
    if((front== 0 && rear == size-1)||(rear==(front-1)%(size-1))){
        return;
    }
    else if(front == -1){
        front = rear = 0;
        arr[rear]=value;
    }
    else{
        rear++;
        arr[rear]=value;
    }
}
void Queue::checkQueue(){
    long int k=0;
    long int flag=0;
    if(rear>=front){
        for(long int i=front;i<=rear;i++){
    /*            cout<<arr[i]<<" "<<b[k]<<"\n";*/
            if(arr[i]!=b[k]){
                flag=1;
            }
            k++;

        }
    }
/*    else{
        for(int i = front; i< size;i++){
            cout<<arr[i]<<" "<<b[k]<<"\n";
            if(arr[i]==b[k])
                continue;
            if(arr[i]!=b[k]){
                flag=1;
            }
        k++;
        }
    }
   */
    if(flag!=0)
        cout<<"NO"<<"\n";
    else
        cout<<"YES"<<"\n";
}
int main(){
  #ifndef ONLINE_JUDGE
        freopen("i.txt", "rt", stdin);
        freopen("o.txt", "wt", stdout);
	#endif

 ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long int t;
    cin>>t;
    while(t--){
        long int n;
        cin>>n;
        Queue q(n);
        for(long int i=0;i<n;i++){
            cin>>a[i];
            b[i]=a[i];
        }
        long int smallest=a[0];
        long int pos=0;
        for(long int i=1;i<n;i++){
            if(a[i]<smallest){
                smallest=a[i];
                pos=i;
            }
            if(a[i]==smallest){
                pos=i;
                break;
            }
        }
        for(long int i=pos;i<n;i++){
            q.enQueue(a[i]);
        }
        for(long int i=0;i<pos;i++){
            q.enQueue(a[i]);
        }
        sort(b,b+n);
 /*        for(long int i=0;i<n;i++){
            cout<<b[i]<<"\n";
        }
        */
        q.checkQueue();


    }



/*    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    */
    return 0;
}
