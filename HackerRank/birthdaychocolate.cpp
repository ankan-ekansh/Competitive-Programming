#include<bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int d,m;
    cin>>d>>m;
    int s=0;
    int c=0;
    for(int i=0;i<=n-m;i++){
        for(int j=i;j<(i+m);j++){
            s+=a[j];
            //
        }
        if(s==d){
//            cout<<s<<endl;
            c++;
            s=0;
        }
        s=0;
    }
    cout<<c<<endl;

//    #ifndef ONLINE_JUDGE
//        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
//    #endif
    return 0;
}

