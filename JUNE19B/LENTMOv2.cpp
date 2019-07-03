#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
ull solve(ull a[], ull n, ull l, ull x){
    bool found = false;
    ull sum = 0;
    //cout<<"l = "<<l<<"\n";
    for(ull i=0;i<n;i++){
        if(a[i] == l && found == false){
            sum+=a[i];
            found = true;
        }
        else{
            if(a[i] < (a[i]^x)){
                sum+=(a[i]^x);
            }
            else{
                sum+=a[i];
            }
        }
    }
    return sum;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
 
        ull n;
        cin>>n;
        ull a[n]={0};
        ull originalSum = 0, originalXorSum = 0, allHighSum = 0, oneLowAllHighSum = 0;
        vector<ull> lows,highs;
        vector<pair<ll, ull>> diff;
        for(ull i=0;i<n;i++){
            cin>>a[i];
            originalSum+=a[i];
        }
        ull k,x;
        cin>>k;
        cin>>x;
        ull lc=0,hc=0;
        if(x == 0){
            cout<<originalSum<<"\n";
            continue;
        }
        for(ull i=0;i<n;i++){
            originalXorSum+=(a[i]^x);
            if(a[i] < (a[i] ^ x)){
                lc++;
                lows.push_back(a[i]);
                allHighSum+=(a[i] ^ x);
            }
            else{
                hc++;
                highs.push_back(a[i] ^ x);
                allHighSum+=a[i];
            }
        }
        for(auto i=lows.begin();i!=lows.end();i++){
            //cout<<((*i)^x) - (*i)<<" "<<*i<<"\n";
            diff.push_back(make_pair(((*i)^x) - (*i), *i));
        }
        //cout<<"\n";
        sort(diff.begin(),diff.end());
        // for(auto i=diff.begin();i!=diff.end();i++){
        //     cout<<(*i).first<<" "<<(*i).second<<"\n";
        // }
        // cout<<"\n";
        ull l = (*(diff.begin())).second;

        if(lc==0){
            cout<<originalSum<<"\n";
            continue;
        }
        if(k==n){
            cout<<max(originalSum, originalXorSum)<<"\n";
            continue;
        }
        if(k==1){
            cout<<allHighSum<<"\n";
            continue;
        }
        if(k==lc){
            cout<<allHighSum<<"\n";
            continue;
        }
        if(lc % 2 == 0){
            if(k <= (hc + lc/2)){
                cout<<allHighSum<<"\n";
                continue;
            }
            if(k == n-1){
                if(hc % 2 != 0){
                    cout<<allHighSum<<"\n";
                    continue;
                }
                else{
                    oneLowAllHighSum = solve(a, n, l, x);
                    cout<<oneLowAllHighSum<<"\n";
                    continue;
                }
            }
            else{
                if(k % 2 == 0){
                    cout<<allHighSum<<"\n";
                    continue;
                }
                else{
                    oneLowAllHighSum = solve(a, n, l, x);
                    cout<<oneLowAllHighSum<<"\n";
                    continue;
                }
            }
        }
        if(lc % 2 != 0){
            if(k == n-1){
                if(hc % 2 != 0){
                    cout<<allHighSum<<"\n";
                    continue;
                }
                else{
                    oneLowAllHighSum = solve(a, n, l, x);
                    cout<<oneLowAllHighSum<<"\n";
                    continue;
                }
            }
            if(k % 2 != 0){
                cout<<allHighSum<<"\n";
                continue;
            }
            if(k % 2 == 0){
                oneLowAllHighSum = solve(a, n, l, x);
                cout<<oneLowAllHighSum<<"\n";
                continue;
            }
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}