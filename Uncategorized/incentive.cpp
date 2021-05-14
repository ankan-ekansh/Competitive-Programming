/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long greatestValueDays(vector<int> ratings) {
    long long mxm = -1;
    long long l = -1, r;
    long long pref[ratings.size()+1];
    memset(pref, 0, sizeof(pref));
    for(long long i=0;i<ratings.size();i++) {
        if(i == 0) {
            pref[i] = ratings[0];
        }
        else {
            pref[i] = pref[i-1] + ratings[i];
        }
        if(ratings[i] > mxm) {
            mxm = ratings[i];
            l = i;
        }
    }
    long long mxmIncentive = 0;
    long long mnm = mxm;
    r = l;
    mxmIncentive = mxm * mxm;
    while (l >= 0 && r < ratings.size()) {
        if(l>0 && min((long long)ratings[l-1], mnm) * (pref[r] - pref[l-1] + ratings[l-1]) > mxmIncentive) {
            mnm = min((long long)ratings[l-1], mnm);
            mxmIncentive = mnm * (pref[r] - pref[l-1] + ratings[l-1]);
            l = l-1;
        }
        else if(r<ratings.size()-1 && min((long long)ratings[r+1], mnm) * (pref[r+1] - pref[l] + ratings[l]) > mxmIncentive) {
            mnm = min((long long)ratings[r+1], mnm);
            mxmIncentive = mnm * (pref[r+1] - pref[l] + ratings[l]);
            r = r+1;
        }
        else {
            break;
        }
    }
    // mxmIncentive = max(mxmIncentive, mnm * (pref[]))
    // cout << l << " " << r << "\n";
    return mxmIncentive;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        
        ll n;
        cin >> n;
        vector<int> ratings(n);
        for(ll i=0;i<n;i++) {
            cin >> ratings[i];
        }
        cout << greatestValueDays(ratings) << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}