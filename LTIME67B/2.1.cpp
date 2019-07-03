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
        long long int ndiy=0;
        long long int days=0;
        for(int i=1;i<=n;i++){
            cin>>ndmw[i];
//            if(i%4 == 0)
//                ndmw[i]++;
            ndiy+=ndmw[i];
        }
        int yb,mb,db,yc,mc,dc;
        cin>>yb>>mb>>db;
        cin>>yc>>mc>>dc;
        for(int y=yb;y<yc;y++){
            if(y!=yb){
                days+=ndiy;
                if(y%4==0)
                    days++;
            }
            if(y==yb && yb!=yc){
                days+=(ndmw[mb]-db+1);
                for(int i = mb+1; i<=n; i++){
                    days+= ndmw[i];
                }
                if(y%4==0)
                    days++;
            }

        }
        if(yb!=yc){
            days+=(dc);
            for(int i=1;i<=mc-1;i++){
                days+= ndmw[i];
            }
            if(yc%4==0 && mc==n && dc==ndmw[n])
                days++;
        }


        if(yb==yc){
            days+=(ndmw[mb]-db+1);
            for(int i = mb+1;i<mc;i++){
                days+= ndmw[i];
            }
            days+=dc;
            if(yc%4 ==0 && mc==n && dc==ndmw[n])
                days++;
            cout<<days<<endl;
            continue;
        }







        cout<<days<<endl;
        }


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

