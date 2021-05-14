/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        // freopen("travel_restrictions_validation_input.txt", "rt", stdin);
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    ll tc = 1;
    while(t--){
        
        ll n;
        cin >> n;
        // char I[n], O[n];
        vector<char> I(n), O(n);
        for(ll i=0;i<n;i++){
            cin >> I[i];
        }
        for(ll i=0;i<n;i++){
            cin >> O[i];
        }
        // char P[n][n];
        vector<vector<char>> P(n, vector<char>(n, 'N'));
        // memset(P, 'N', sizeof(P));
        for(ll i=0;i<n;i++){
            P[i][i] = 'Y';
        }
        for(ll k=0;k<n;k++){
            for(ll i=0;i<n;i++){
                for(ll j=0;j<n;j++){
                    if(O[k] == 'Y' && I[k] == 'Y' && abs(i - k) == 1 && abs(k-j) == 1){
                        if(O[i] == 'Y' && I[j] == 'Y'){
                            P[i][j] = 'Y';
                        }
                        if(O[j] == 'Y' && I[i] == 'Y'){
                            P[j][i] = 'Y';
                        }
                        if(O[i] == 'Y'){
                            P[i][k] = 'Y';
                        }
                        if(I[i] == 'Y'){
                            P[k][i] = 'Y';
                        }
                        if(O[j] == 'Y'){
                            P[j][k] = 'Y';
                        }
                        if(I[j] == 'Y'){
                            P[k][j] = 'Y';
                        }
                    }
                    if(O[k] == 'Y' && I[k] == 'N'){
                        if(I[i] == 'Y' && abs(i-k) == 1){
                            P[k][i] = 'Y';
                        }
                        if(I[j] == 'Y' && abs(k-j) == 1){
                            P[k][j] = 'Y';
                        }
                    }
                    if(O[k] == 'N' && I[k] == 'Y'){
                        if(O[i] == 'Y' && abs(i - k) == 1){
                            P[i][k] = 'Y';
                        }
                        if(O[j] == 'Y' && abs(k - j) == 1){
                            P[j][k] = 'Y';
                        }
                    }
                }
            }
        }
        cout << "Case #" << tc++ << ": \n";
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                cout << P[i][j] ;
            }
            cout << "\n";
        }
        
    }
    // #ifndef ONLINE_JUDGE
    //     cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    // #endif
    return 0;
}