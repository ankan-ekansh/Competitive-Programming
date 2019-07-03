#include<bits/stdc++.h>
using namespace std;
string s;
int n,k,q;

void shift(){
    int pos = n-1;
    string t = s.substr(pos,1);
    s.append(t,0,1);
    s.pop_back();
    s.resize(n);
}
int len(){
    int l=0;
    int lmax=0;


    string::iterator is;
    string::iterator i1;
    string a("0");
    for(is=s.begin();is<s.end();is++){
        i1=is;
        if(*is == 1){
            is = search(s.begin(), s.end(), a.begin(), a.end());
            if(is!=s.end()){
                l=is-s.begin();
                if(l>lmax){
                    lmax=l;
                }
            }
            else{
                l=(s.begin()+n-1)-i1;
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    cin>>q;
    cin>>k;
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        s.push_back(c);
    }
    string query;
    for(int i=0;i<q;i++){
      char c;
      cin>>c;
      query.push_back(c);
    }
    string::iterator i;
    for(i=query.begin();i!=query.end();i++){
        if(*i == '!'){
            shift();
        }
        if(*i == '?'){
            int lq=len();
            cout<<lq<<"\n";
        }
    }



    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

