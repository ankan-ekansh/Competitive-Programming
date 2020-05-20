#include<bits/stdc++.h>
#define ll long long
using namespace std; 

vector<ll> b;
// A utility function that returns maximum of two integers 
ll max(ll a, ll b) { return (a > b)? a : b; } 
  
// Returns the maximum value that can be put in a knapsack of capacity W 
ll knapSack(ll W, ll wt[], ll val[], ll n) 
{ 
   ll i, w; 
   ll K[n+1][W+1]; 
  
   // Build table K[][] in bottom up manner 
   for (i = 0; i <= n; i++) 
   { 
       for (w = 0; w <= W; w++) 
       { 
           if (i==0 || w==0) 
               K[i][w] = 0; 
           else if (wt[i-1] <= w) {
                //  K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 
                if(val[i-1] + K[i-1][w - wt[i-1]] > K[i][w]){
                    b.push_back(val[i-1]);
                }
           }
           else
                 K[i][w] = K[i-1][w]; 
       } 
   } 
  
   return K[n][W]; 
} 
  
int main() 
{ 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, z, x, y;
    cin >> n >> z >> x >> y;
    ll c[n], p[n];
    for(ll i=0;i<n;i++){
        cin >> c[i];
    }
    for(ll i=0;i<n;i++){
        cin >> p[i];
    }
    // int val[] = {60, 100, 120}; 
    // int wt[] = {10, 20, 30}; 
    int  W = z; 
    // printf("%d", knapSack(W, c, p, n)); 
    ll ans = knapSack(W, c, p, n);
    sort(b.begin(), b.end(), greater<ll>());
    if(b.size() >= 2){
        ans-=b[0] + (max(x,y) * b[0]);
        ans-=b[1] + (min(x,y) * b[1]);
    }
    else if(b.size() == 1){
        ans-=b[0] + (max(x, y) * b[0]);
    }
    cout << ans << "\n";
    return 0; 
} 