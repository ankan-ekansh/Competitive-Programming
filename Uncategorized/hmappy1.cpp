#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
int a[100050];
int b[100050];
int n,k;
void shift(){
    int temp=a[n-1];

    for(int i=0;i<n;i++){
        b[i+1]=a[i];
    }
    b[0]=temp;
    for(int i=0;i<n;i++){
        a[i]=b[i];
    }
}
int len(){
    int l=1;
    int lmax=1;
    for(int i=0;i<n;i++){
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
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    char query[300050];
//  for(int i=0;i<q;i++){
//      cin>>query[i];
//  }
    cin.ignore();
    gets(query);
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

