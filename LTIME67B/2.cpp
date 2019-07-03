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

        int n;
        cin>>n;
        int ndmw[10050] = {0};
        int ndiy=0;
        int days=0;
        for(int i=1;i<=n;i++){
            cin>>ndmw[i];
//            if(i%4 == 0)
//                ndmw[i]++;
            ndiy+=ndmw[i];
        }
        int yb,mb,db,yc,mc,dc;
        cin>>yb>>mb>>db;
        cin>>yc>>mc>>dc;
        if(yb!=yc && yc-yb >1)
            days+= (yc-yb-1)*ndiy;
        days+=(ndmw[mb]-db+1);
        days+=(dc);
        if(yb==yc && mc-mb==1){
            cout<<days<<endl;
            continue;
        }
        for(int i = mb+1; i<=n; i++){
            days+= ndmw[i];
        }
        if(yb%4==0){
                days+=1;
            }


        for(int i=1;i<=mc-1;i++){
            days+= ndmw[i];
        }



        cout<<days<<endl;
        }


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

