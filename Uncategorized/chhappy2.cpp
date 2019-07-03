#include<bits/stdc++.h>
using namespace std;
vector <int> a;
vector <int> aa;
vector<int> v;
/*
int a[100050];
int aa[100050];
*/
int f(int x,int pos){
    v.push_back(x);
    vector<int>::iterator ip;
    ip=search(aa.begin()+pos+1, aa.end(), v.begin(), v.end());
    if(ip!=aa.end()){
        int k=ip-aa.begin();
/*        cout<<aa[pos]<<" is at "<<k<<" position\n";
*/
        v.clear();
        return k;
    }
    else{
        v.clear();
        return -1;
    }
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
        int n;
        cin>>n;
        int flag=0;
        a.push_back(0);
        for(int i=1;i<=n;i++){

/*          cin>>a[i];
*/
            int x;
            cin>>x;
            a.push_back(x);
        }
        aa.push_back(0);
        for(int i=1;i<=n;i++){
/*
            aa[i]=a[a[i]];
*/
            aa.push_back(a[a[i]]);
        }
/*        for(int i=1;i<=n;i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
        for(int i=1;i<=n;i++){
            cout<<aa[i]<<" ";
        }
        cout<<"\n";
*/

/*
       for(int i=1;i<=n;i++){

        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[i]!=a[j]){
                    if(aa[i]==aa[j]){
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==1)
                    break;
        }
        if(flag==1){
            cout<<"Truly Happy\n";
        }
        else{
            cout<<"Poor Chef\n";
        }
    }
*/

        for(int i=1;i<=n;i++){
            int p=f(aa[i],i);
            if(p!=-1){
                if(a[i]!=a[p] && aa[i]==aa[p]){
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1){
            cout<<"Truly Happy\n";
        }
        else
            cout<<"Poor Chef\n";

        a.clear();
        aa.clear();

    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

