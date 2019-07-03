#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        pair<int, int> p;
        map<int, int> m;
        for(int i=1;i<=n;i++){
            cin>>p.first;
            p.second = 0;
            m.insert(p);
        }
/*        for(auto i = m.begin();i!=m.end();i++){
            cout<<'\t'<<i->first<<'\t'<<i->second<<endl;
        }
*/
        auto it = m.rbegin();
        int l = it->first;
//        cout<<l<<endl;
        int pa =0,pb = 0;
        for(int i=a,j=b;i<=l,j<=l;i=i+a,j=j+b){
            auto itr = m.find(i);
            if(itr->second == 0 && itr!=m.end()){
                itr->second = 1;
//                cout<<itr->first<<endl;
                ++pa;
            }
            itr = m.find(j);
            if(itr->second == 0 && itr!=m.end()){
                itr->second = 2;
//                cout<<itr->first<<endl;
                ++pb;
            }
        }
//        cout<<"pa "<<pa<<","<<" pb "<<pb<<endl;
        if(pa>pb){
            cout<<"BOB\n";
        }
        else if(pa<pb){
            cout<<"ALICE\n";
        }
        else if(pa==pb){
            if(b>a){
                if(b%a == 0){
                    cout<<"BOB\n";
                }
            }
            if(b<a){
                if(a%b == 0){
                    cout<<"ALICE\n";
                }
            }
            if(a==b){
                cout<<"BOB\n";
            }
            else{
                cout<<"ALICE\n";
            }
        }


    }


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

