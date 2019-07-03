#include<bits/stdc++.h>
using namespace std;
int a[400000];
//int b[400000];
int n,k;
int f,r;
void shift(){
    int temp=a[r];

    f--;
    r--;
    a[f]=temp;

/*    for(int i=0;i<n;i++){
        b[i+1]=a[i];
    }
    b[0]=temp;
    for(int i=0;i<n;i++){
        a[i]=b[i];
    }
*/
}
int len(){
    int l=0;
    int lmax=0;
    for(int i=f;i<=r;i++){
        if(a[i]==1){
            if(a[i]==1 && a[i+1]==1){
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
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif


    int q;
    cin>>n;
    cin>>q;
    cin>>k;
    f=400000-n;
    r=400000-1;
    for(int i=f;i<=r;i++){
        cin>>a[i];
    }
    char query[300000];
    for(int i=0;i<q;i++){
      cin>>query[i];
    }
    for(int i=0;i<q;i++){
        if(query[i]=='!'){
            shift();
        }
        if(query[i]=='?'){
            int lq=len();
            cout<<lq<<"\n";
        }
    }



    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

