#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        int count=0;
        cin>>n>>k;
        int size;
        size=n*sizeof(int);
        int* a=(int*)calloc(n,sizeof(int));
        for(int i=0;i<n;i++){
            cin>>*(a+i);
        }
        sort(a,a+n);
        for(int j=n-1;j>=0;j--){
            if(*(a+j) >= *(a+n-k))
                count++;
            else
                break;
        }
        cout<<count<<endl;
    }
}
