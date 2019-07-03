#include<bits/stdc++.h>
using namespace std;
#define lli long long int
lli leap(lli s,lli e){
    lli leaps=0;
    for(lli i=s;i<=e;i++){
        if(i%4==0){
            leaps++;
        }
    }
    return leaps;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    lli t;
    cin>>t;
    while(t--){

        lli n;
        cin>>n;
        lli ndmw[n+1], sdmw[n+1] = {0};
        lli ndiy=0;
        for(lli i = 1;i<=n;i++){
            cin>>ndmw[i];
            ndiy+=ndmw[i];
            sdmw[i]=sdmw[i-1]+ndmw[i];
        }
        lli yb,mb,db,yc,mc,dc;
        cin>>yb>>mb>>db;
        cin>>yc>>mc>>dc;
        lli age = 0;
        if(yb!=yc){
            if(yc-yb > 1){
                age+=(yc-yb-1)*ndiy;
                age+=leap(yb+1,yc-1);
                age+=(ndmw[mb]-db+1);
                for(lli i= mb+1;i<=n;i++){
                    age+=ndmw[i];
                }
                for(lli i=1;i<=mc-1;i++){
                    age+=ndmw[i];
                }
                age+=dc;
                age+=leap(yb,yb);
            }
            if(yc-yb==1){
                age+=(ndmw[mb]-db+1);
                for(lli i=mb+1;i<=n;i++){
                    age+=ndmw[i];
                }
                for(lli i=1;i<=mc-1;i++){
                    age+=ndmw[i];
                }
                age+=dc;
                age+=leap(yb,yb);
            }
        }
        if(yb==yc){
            if(mb==mc){
                age+=dc-db+1;
            }
            if(mb!=mc){
                if(mc-mb == 1){
                    age+=(ndmw[mb]-db+1);
                    age+=dc;
                }
                if(mc-mb > 1){
                    age+=(ndmw[mb]-db+1);
                    for(lli i=mb+1;i<=mc-1;i++){
                        age+=ndmw[i];
                    }
                    age+=dc;
                }
            }
        }
        cout<<age<<endl;



    }


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

