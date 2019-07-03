#include<bits/stdc++.h>
using namespace std;
vector<int> a;
//int b[400000];
int n,k;
void shift(){
    a.insert(a.begin(),a[n-1]);
    a.pop_back();
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

    vector<int> v = {0};
    vector<int>::iterator i1;

    for(int i=0;i<n;i++){
        if(a[i]==1){
            i1 = search(a.begin()+i+1, a.end(), v.begin(), v.end());
            if(i1!=a.end()){
                l=i1-(a.begin()+i);
                i=(i1-a.begin());
                if(l>lmax){
                    lmax=l;
                }
            }
            else{
                l=n-i;
                if(l>lmax){
                    lmax=l;
                }
                break;
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
        int x;
        cin>>x;
        a.push_back(x);
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

