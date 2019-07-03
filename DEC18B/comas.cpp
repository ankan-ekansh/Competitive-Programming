#include<bits/stdc++.h>
using namespace std;
int main(){
//    #ifndef ONLINE_JUDGE
//        freopen("input.txt", "rt", stdin);
//        freopen("output.txt", "wt", stdout);
//    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin>>t;
    vector<int> v;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n-4;i++){
            cout<<"? "<<i<<" "<<i+1<<" "<<i+2<<" "<<i+3<<" "<<i+4<<endl<<flush;
            int a,b;
            cin>>a>>b;
            v.push_back(a);
            v.push_back(b);
        }
        sort(v.begin(), v.end());
        vector<int>::iterator ip;
        ip=unique(v.begin(),v.begin()+(n-4)*2);
        v.resize(distance(v.begin(), ip));
        int s = v.size()/sizeof(int);
        int r=n-s;
        vector<int> v2;
        for(int i=0;i<s;i++){
            v2.push_back(v[i]);
        }
        for(int i=0;i<s;i++){
            for(int j=n-r;j<=n;j++){
                cout<<"? "<<v[i]<<" "<<v[i+1]<<" "<<v[i+2]<<" "<<j<<" "<<j+1<<endl<<flush;
                int a,b;
                cin>>a>>b;
                v2.push_back(a);
                v2.push_back(b);
            }
        }
        vector<int>::iterator ip2;
        ip2=unique(v2.begin(),v2.begin()+(r+1)*2);
        sort(v2.begin(),v2.end());
        v2.resize(distance(v.begin(),ip));
        int s2=v2.size()/sizeof(int);
        for(int i=1;i<=n;i++){
            for(int j=0;j<s2;j++){
                if(i!=v2[j]){
                    cout<<"! "<<i<<endl<<flush;
                    exit(0);
                }
            }
        }

    }


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

