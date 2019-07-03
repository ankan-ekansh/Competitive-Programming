#include<bits/stdc++.h>
using namespace std;
int ntr,ndr,nts,nds;
int tr[100],dr[100],ts[100],ds[100];
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
        cin>>ntr;
        for(int i=0;i<ntr;i++){
            cin>>tr[i];
        }
        cin>>ndr;
        for(int i=0;i<ndr;i++){
            cin>>dr[i];
        }
        cin>>nts;
        for(int i=0;i<nts;i++){
            cin>>ts[i];
        }
        cin>>nds;
        for(int i=0;i<nds;i++){
            cin>>ds[i];
        }
        int flag=0;
        sort(tr,tr+ntr);
        sort(dr,dr+ndr);
//        sort(ts,ts+nts);
//        sort(ds,ds+nds);
        for(int i=0;i<nts;i++){
            if(!(binary_search(tr,tr+ntr,ts[i]))){
                flag++;
                break;
            }
        }
        for(int i=0;i<nds;i++){
            if(!(binary_search(dr,dr+ndr,ds[i]))){
                flag++;
                break;
            }
        }
        if(flag!=0){
            cout<<"no\n";
        }
        else
            cout<<"yes\n";


    }


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

