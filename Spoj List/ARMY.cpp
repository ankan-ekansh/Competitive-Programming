#include<bits/stdc++.h>
#define i64 int64_t
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    i64 t;
    cin>>t;
    while(t--){
        //fflush(stdin);
        char c;
        //cin>>c;
        //cout<<c<<"\n";
        // if(c==' '){
        //    cout<<"Newline\n";
        // }
        //cout<<(int)c<<"\n";
        i64 ng,nm;
        cin>>ng;
        cin>>nm;
        //cout<<ng<<" "<<nm<<"\n";
        //priority_queue<i64 , vector<i64> , greater<i64> > g,m;
        vector<i64> g,m;
        g.resize(ng);
        m.resize(nm);
        for(i64 i = 0;i<ng;i++){
            cin>>g[i];
        }
        for(i64 i =0;i<nm;i++){
            cin>>m[i];
        }
        sort(g.begin(),g.end());
        sort(m.begin(),m.end());
        i64 kg=0,km=0;
        // if(ng == 0 && nm == 0)
        //     cout<<"uncertain\n";
        i64 i = 0, j = 0;
        while((i<ng) && (j<nm)){
            if(g[i] < m[j]){
                // cout<<"G is "<<g[i]<<" M is "<<m[j]<<"\n";
                // cout<<"i is "<<i<<" j is "<<j<<"\n";
                // cout<<"G is killed by M\n";
                kg++;
                i++;
            }
            else if(m[j] < g[i]){
                // cout<<"G is "<<g[i]<<" M is "<<m[j]<<"\n";
                // cout<<"i is "<<i<<" j is "<<j<<"\n";
                // cout<<"M is killed by G\n";
                km++;
                j++;
            }
            else if(g[i] == m[j]){
                // cout<<"G is "<<g[i]<<" M is "<<m[j]<<"\n";
                // cout<<"i is "<<i<<" j is "<<j<<"\n";
                // cout<<"M is killed by G\n";
                km++;
                j++;
            }
            if( i >= ng){
                cout<<"MechaGodzilla\n";
                break;
            }
            else if(j >= nm){
                cout<<"Godzilla\n";
                break;
            }
            // if(kg == ng || km == nm){
            //     if(kg == ng && km != nm){
            //         cout<<"MechaGodzilla\n";
            //         break;
            //     }
            //     else if(kg != ng && km == nm){
            //         cout<<"Godzilla\n";
            //         break;
            //     }
            //     // else{
            //     //     cout<<"uncertain\n";
            //     //     break;
            //     // }
            // }
        }
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}
