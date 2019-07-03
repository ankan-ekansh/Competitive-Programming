#include<bits/stdc++.h>
using namespace std;
vector<int> v;
vector<int> v2;
int n;
int posfind(int x,int pos){
    v2.push_back(x);
    vector<int>::iterator ip;
    ip=search(v.begin()+pos+1,v.end(),v2.begin(),v2.end());
    int k=ip-v.begin();
    v2.c();
    return k;

}

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

        cin>>n;
        for(int i=0;i<n;i++){
            int x;
            v.push_back(x);
        }
        int k=0;
        int flag=0;
        while(k<n){
            k=posfind(v[k],k);
            for(int i=k+1;i<n;i++){
                if(v[k]!=v[i]){
                    if(v[v[k]] == v[v[i]]){
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==1){
                cout<<"Truly Happy\n";
                break;

            }
        }
        if(flag==0){
            cout<<"Poor Chef\n";
        }
        v.empty();

    }


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

