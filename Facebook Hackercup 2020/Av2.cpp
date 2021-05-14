/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        // freopen("input.txt", "rt", stdin);
        freopen("travel_restrictions_validation_input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    int tc = 1;
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
        for(ll i=0;i<n;i++){
            ll j = i;
            while(j > 0 && O[j] == 'Y' && I[j-1] == 'Y'){
                for(ll l=i;l>=j;l--){
                    P[l][j-1] = 'Y';
                }
                j--;
            }
            j = i;
            while(j < n-1 && O[j] == 'Y' && I[j+1] == 'Y'){
                for(ll l=i;l<=j;l++){
                    P[l][j+1] = 'Y';
                }
                j++;
            }
        }
        cout << "Case #" << tc++ << ":\n";
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