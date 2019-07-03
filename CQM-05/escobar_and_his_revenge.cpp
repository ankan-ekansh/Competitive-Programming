#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
        int n;
        cin>>n;
        set<int64_t> s;
        map<int64_t, int64_t> p;
        for(int i=0;i<n;i++){
            int l,r;
            cin>>l>>r;
            p[l]++;
            p[r+1]--;
            s.insert(l);
            s.insert(r+1);
        }
        int ps = 0;
        set<pair<int64_t, int64_t>> v;
        for(auto i = s.begin();i != s.end(); i++){
            ps+=p[(*i)];
            // v.insert({*i,ps});
            v.insert(make_pair(*i,ps));
        }
        int q;
        cin>>q;
        while(q--){
            int x;
            cin>>x;
            if(x < (v.begin()->first)){     //when x is lesser than any of the intervals
                cout<<"0\n";    
            }
            else{
                auto j = v.lower_bound(make_pair(x,0));
                if(j == v.end()){   //when x is greater than any of the intervals
                    cout<<"0\n";
                }
                else{
                    if(j->first != x){  //since lower_bound gives the next biggest element than x if x isnt present, so we move a step back
                        j--;
                    }
                    cout<<j->second<<"\n";
                }
            }            
        }
        
 
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}